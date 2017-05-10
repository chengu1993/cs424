#define FP float
#BDIM 1024
#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <math.h>


__global__ void gpu_vecop(FP *a, FP *b, FP *c, FP coef, int N) {
  int index = threadIdx.x + blockDim.x * blockIdx.x;
  if(index < N) c[index] = a[index] + coef * b[index];
}

__global__ void gpu_vecdot(FP *a, FP *b, FP *c, int N) {
  int index = threadIdx.x + blockDim.x * blockIdx.x;
  if(index < N) c[index] = a[index] * b[index]; 
}


__global__ void gpu_matmulvec(FP *a, int *row, int *col, FP *b, FP *c, int Nz) {

  int col = threadIdx.x + blockDim.x * blockIdx.x;
  int row = threadIdx.y + blockDim.y * blockIdx.y;

  int indexb = col;
  int index = row * m + col;
  
  if(col < m && row < n) {
    c[index] = 0.;
    for (int indexa = row*p; indexa < (row*p + p); indexa++, indexb+=m) 
      c[index] += a[indexa]*b[indexb];
  }

}

void print(FP *a, int n, int m) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%.6e ", a[i*m+j]);
		}
		printf("\n");
	}
}

void kij(FP *a, FP *b, FP *c, int n, int p, int m) {
  for(int k = 0; k < p; k++) {
    for(int i = 0; i < n; i++) {
	  //FP r = a[i][k];
	  FP r = a[i * p + k];
	  const int baseC = i * m;
	  const int baseB = k * m;
      for(int j = 0; j < m; j++) 
        c[baseC + j] -= r * b[baseB + j];
    }
  }
}

void cpu_matrixmult(FP *a,FP *b, FP *c, int n) {

  int index, indexa, indexb;
  FP cvalue;
  for(int col=0;col < n; col++)
    for(int row=0;row < n; row++) {
      indexb = col;
      index = row * n + col;
      cvalue = 0.;
      for (indexa = row*n; indexa < (row*n + n); indexa++, indexb+=n) 
	cvalue += a[indexa]*b[indexb];
      c[index] -= cvalue; //NOTE: This calculates the diff between CPU and GPU computations.
    }
}


int main(int argc, char *argv[]) {

  int i, j; // loop counters

  int gpucount = 0; // Count of available GPUs
  int gpunum = 0; // Device number to use
  int Grid_Dim_X = 1, Grid_Dim_Y = 1; //Grid dimension, x and y
  int Block_Dim_X = 1, Block_Dim_Y = 1; //Block dimension, x and y, square

  int n, N; // matrix dimension
  int Nz_in_grid, Nz; 
  float rho, prev_rho;
  int *row, *col;
  FP *A, *b, *x, *p, *r, *q;
  FP *dev_A, *dev_row, *dev_col, *dev_b, *dev_x, *dev_p, *dev_r, *dev_q;

  cudaEvent_t start, stop; // using cuda events to measure time
  float elapsed_time_ms; // which is applicable for asynchronous code also
  cudaError_t errorcode;

  // --------------------SET PARAMETERS AND DATA -----------------------

  errorcode = cudaGetDeviceCount(&gpucount);
  if (errorcode == cudaErrorNoDevice) {
    printf("No GPUs are visible\n");
    exit(-1);
  }
  else {
     printf("Device count = %d\n",gpucount);
  }

  if ((argc<2) || (argc>3)) {
    printf("Usage: matmul <matrix dim n> [<dev num>]\n");
    exit (-1);
  }

  n = atoi(argv[1]);
  N = n * n;
  Nz_in_grid = (n - 2) * 3 + 2 * 2; // number of non-zero elements in a grid
  Nz = (n - 2) * 3 * Nz_in_grid + 2 * 2 * Nz_in_grid; // number of non-zero elements
  row = (int *) calloc(Nz, sizeof(int));
  col = (int *) calloc(Nz, sizeof(int));
  A = (FP *) calloc(Nz, sizeof(FP));
  b = (FP *) calloc(N, sizeof(FP));
  x = (FP *) calloc(N, sizeof(FP));
  p = (FP *) calloc(N, sizeof(FP));
  r = (FP *) calloc(N, sizeof(FP));
  q = (FP *) calloc(N, sizeof(FP));


  // Block_Dim_X = atoi(argv[4]);
  // Block_Dim_Y = atoi(argv[5]);
  // if (Block_Dim_X*Block_Dim_Y > 1024) {
  //   printf("Error, too many threads in block\n");
  //   exit (-1);
  // }

  // Grid_Dim_X = (int) ceil((double) m / Block_Dim_X);
  // Grid_Dim_Y = (int) ceil((double) n / Block_Dim_Y);
  // if (Grid_Dim_X * Grid_Dim_Y * Block_Dim_X * Block_Dim_Y < n * m) {
  //   printf("Error, number of threads in x/y dimensions less than number of array elements\n");
  //   exit (-1);
  // }

  if (argc==3) {
    gpunum = atoi(argv[2]); // Device number
    if ((gpunum > 2) || (gpunum < 0)) {
      printf("Error, Device number must be 0, 1, or 2\n");
      exit (-1);
    }
  }
  cudaSetDevice(gpunum);
  printf("Using device %d\n",gpunum);
  
  // printf("Matrix Dimension = %d\n",n);
  // printf("Block_Dim_X = %d, Block_Dim_Y = %d, Grid_Dim_X = %d, Grid_Dim_Y = %d\n",Block_Dim_X, Block_Dim_Y, Grid_Dim_X, Grid_Dim_Y);

  // dim3 Grid(Grid_Dim_X, Grid_Dim_Y); //Grid structure
  // dim3 Block(Block_Dim_X, Block_Dim_Y); //Block structure



  // ------------- COMPUTATION DONE ON GPU ----------------------------


  cudaMalloc((void**)&dev_A, Nz * sizeof(FP)); // allocate memory on device
  cudaMalloc((void**)&dev_row, Nz * sizeof(int));
  cudaMalloc((void**)&dev_col, Nz * sizeof(int));
  cudaMalloc((void**)&dev_b, p * m * sizeof(FP));
  cudaMalloc((void**)&dev_x, n * m * sizeof(FP));
  cudaMalloc((void**)&dev_p, n * m * sizeof(FP));
  cudaMalloc((void**)&dev_r, n * m * sizeof(FP));
  cudaMalloc((void**)&dev_q, n * m * sizeof(FP));



  cudaMemcpy(dev_A, A , Nz * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_row, row , Nz * sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_col, col , Nz * sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_b, b , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_x, x , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_p, p , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_r, r , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_q, q , N * sizeof(FP), cudaMemcpyHostToDevice);
  

  // gpu_matrixmult<<<Grid,Block>>>(dev_a, dev_b, dev_c, n, p, m);
  gpu_matmulvec<<<N/BDIM, BDIM>>>(dev_A, dev_row, dev_col, dev_x, dev_r, Nz);
  gpu_vecop<<<N/BDIM, BDIM>>>(dev_b, dev_r, dev_r, -1., N);
  cudaMemcpy(r,dev_r, N * sizeof(FP), cudaMemcpyDeviceToHost);


  // // r = b - A * x0
  // matmulvec(Nz, A, row, col, x, r, N);
  // vecop(b, r, r, -1., N);
  // rho = vecdot(r, r, N);

  // for (iter = 0; iter < MAX_ITERATION && sqrt(rho) >= THRESHOLD; iter++) {
  //     // r =rTr
  //     prev_rho = rho;
  //     rho = vecdot(r, r, N);
  //     //printf("current residuals: %f\n", sqrt(rho));
  //     if (iter == 0) {
  //         // p = r;
  //         for (int i = 0; i < N; i++) {
  //             p[i] = r[i];
  //         }
  //     } else {
  //         // beta = rho_p / rho_p-1
  //         FP beta = rho / prev_rho;
  //         //printf("beta: %f\n", beta);
  //         // p = r + beta * p;
  //         vecop(r, p, p, beta, N);
  //     }
  //     // q = Ap
  //     for (int j = 0; j < N; j++) q[j] = .0;
  //     matmulvec(Nz, A, row, col, p, q, N);
  //     //a = pTq
  //     FP alpha = vecdot(p, q, N);
  //     //printf("alpha: %f\n", alpha);
  //     // x = x + ap
  //     vecop(x, p, x, alpha, N);
  //     // r = r -aq
  //     vecop(r, q, r, -alpha, N);

  // }


  // cudaMemcpy(dev_a, a , n * p * sizeof(FP), cudaMemcpyHostToDevice);
  // cudaMemcpy(dev_b, b , p * m * sizeof(FP), cudaMemcpyHostToDevice);

  // gpu_matrixmult<<<Grid,Block>>>(dev_a, dev_b, dev_c, n, p, m);

  // cudaMemcpy(c,dev_c, n * m * sizeof(FP), cudaMemcpyDeviceToHost);



// -------------- clean up ---------------------------------------

  free(A);
  free(row);
  free(col);
  free(b);
  free(x);
  free(p);
  free(r);
  free(q);
  cudaFree(dev_A);
  cudaFree(dev_row);
  cudaFree(dev_col);
  cudaFree(dev_b);
  cudaFree(dev_x);
  cudaFree(dev_p);
  cudaFree(dev_r);
  cudaFree(dev_q);

  cudaEventDestroy(start);
  cudaEventDestroy(stop);

  return 0;
}
