#define FP float
#define BDIM 512
#define MAX_ITERATION 1500
#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <math.h>

// handle vector operations, c = a + ceof * b
__global__ void gpu_vecop(FP *a, FP *b, FP *c, FP coef, int N) {
  int index = threadIdx.x + blockDim.x * blockIdx.x;
  if(index < N) c[index] = a[index] + coef * b[index];
}
// handle dop product, res = dot(a, b)
__global__ void gpu_vecdot(FP *a, FP *b, FP *c, int N) {
  int index = threadIdx.x + blockDim.x * blockIdx.x;
  if(index < N) {
    c[index] = a[index] * b[index]; 
  }
}

// handle assignment, a = b;
__global__ void gpu_vecassign(FP *a, FP *b, int N) {
  int index = threadIdx.x + blockDim.x * blockIdx.x;
  if(index < N) a[index] = b[index]; 
}
// reset vector, a = 0
__global__ void gpu_vecreset(FP *a, int N) {
  int index = threadIdx.x + blockDim.x * blockIdx.x;
  if(index < N) a[index] = 0.; 
}
// handle matrix times vector, c = a * b
__global__ void gpu_matmulvec(FP *a, int *row, int *col, FP *b, FP *c, int Nz) {
  int index = threadIdx.x + blockDim.x * blockIdx.x;
  int start_idx = row[index], end_idx = row[index+1];
  for(int i=start_idx; i<end_idx; i++) {
    c[index] += a[i] * b[col[i]];
  }
}

// use CSR scheme to store the matrix
void initialize(FP *A, int *JR, int *JC, FP *b, int n, int N) {

  // initialize matrix A
  int index = 0;
  FP a[] = {-4, 20, -4};
  FP t[] = {-1, -4, -1};

  for (int grid_row = 0; grid_row < n; grid_row++) {
      int t0_grid_left = (grid_row - 1) * n, t0_grid_right = grid_row * n;
      int a_grid_left = grid_row * n, a_grid_right = (grid_row + 1) * n;
      int t1_grid_left = (grid_row + 1) * n, t1_grid_right = (grid_row + 2) * n;
      for (int row = grid_row * n, col = (grid_row - 1) * n - 1; row < (grid_row + 1) * n; row++, col++) {
          JR[row] = index;
          int base_col = col;
          //set up t0
          if (grid_row != 0) {
              for (int i = 0; i < 3; i++) {
                  int col_idx = base_col + i;
                  if (t0_grid_left <= col_idx && base_col <= col_idx && col_idx < base_col + n &&
                      col_idx < t0_grid_right) {
                      A[index] = t[i];
                      JC[index] = col_idx;
                      index++;
                  }
              }
          }
          //set up Ak
          base_col += n;
          for (int i = 0; i < 3; i++) {
              int col_idx = base_col + i;
              if (a_grid_left <= col_idx && base_col <= col_idx && col_idx < base_col + n && col_idx < a_grid_right) {
                  A[index] = a[i];
                  JC[index] = col_idx;
                  index++;
              }
          }
          base_col += n;
          //set up t1
          if (grid_row != n - 1) {
              for (int i = 0; i < 3; i++) {
                  int col_idx = base_col + i;
                  if (t1_grid_left <= col_idx && base_col <= col_idx && col_idx < base_col + n &&
                      col_idx < t1_grid_right) {
                      A[index] = t[i];
                      JC[index] = col_idx;
                      index++;
                  }
              }
          }
      }
  }

  JR[N] = index; 

  // initialize vector b
  FP num = 6.0 / (n + 1) / (n + 1);
  b[(n / 2 - 1) * n + (n / 2 - 1)] = num;
  b[(n / 2 - 1) * n + (n / 2)] = num;
  b[(n / 2) * n + (n / 2 - 1)] = num;
  b[(n / 2) * n + (n / 2)] = num;

}

void print(FP *a, int n, int m) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%.6e ", a[i*m+j]);
		}
		printf("\n");
	}
}


FP reduce(FP *a, int N) {
  FP res = 0.;
  for(int i=0; i<N; i++) res += a[i];
  return res;
}

int main(int argc, char *argv[]) {

  int gpucount = 0; // Count of available GPUs
  int gpunum = 0; // Device number to use

  int n, N, iter; // matrix dimension
  int Nz_in_grid, Nz; 
  float rho, prev_rho;
  int *row, *col, *dev_row, *dev_col;
  FP *A, *b, *x, *p, *r, *q, *temp;
  FP *dev_A, *dev_b, *dev_x, *dev_p, *dev_r, *dev_q, *dev_temp;

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
  printf("Nz: %d\n", Nz);
  row = (int *) calloc(N+1, sizeof(int));
  col = (int *) calloc(Nz, sizeof(int));
  A = (FP *) calloc(Nz, sizeof(FP));
  b = (FP *) calloc(N, sizeof(FP));
  x = (FP *) calloc(N, sizeof(FP));
  p = (FP *) calloc(N, sizeof(FP));
  r = (FP *) calloc(N, sizeof(FP));
  q = (FP *) calloc(N, sizeof(FP));
  temp = (FP *) calloc(N, sizeof(FP));

  initialize(A, row, col, b, n, N);

  if (argc==3) {
    gpunum = atoi(argv[2]); // Device number
    if ((gpunum > 2) || (gpunum < 0)) {
      printf("Error, Device number must be 0, 1, or 2\n");
      exit (-1);
    }
  }
  cudaSetDevice(gpunum);
  printf("Using device %d\n",gpunum);

  // ------------- COMPUTATION DONE ON GPU ----------------------------
  cudaEventCreate(&start); // instrument code to measure start time
  cudaEventCreate(&stop);
  
  cudaEventRecord(start, 0);


  printf("Setting up cuda memory\n");
  cudaMalloc((void**)&dev_A, Nz * sizeof(FP)); // allocate memory on device
  cudaMalloc((void**)&dev_row, (N+1) * sizeof(int));
  cudaMalloc((void**)&dev_col, Nz * sizeof(int));
  cudaMalloc((void**)&dev_b, N * sizeof(FP));
  cudaMalloc((void**)&dev_x, N * sizeof(FP));
  cudaMalloc((void**)&dev_p, N * sizeof(FP));
  cudaMalloc((void**)&dev_r, N * sizeof(FP));
  cudaMalloc((void**)&dev_q, N * sizeof(FP));
  cudaMalloc((void**)&dev_temp, N * sizeof(FP));



  printf("Copy from host to cuda memory\n");
  cudaMemcpy(dev_A, A , Nz * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_row, row , (N+1) * sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_col, col , Nz * sizeof(int), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_b, b , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_x, x , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_p, p , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_r, r , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_q, q , N * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_temp, temp, N * sizeof(FP), cudaMemcpyHostToDevice);

  // const FP THRESHOLD = sqrt(vecdot(b, b, N)) / 1000000.;
  gpu_vecdot<<<N/BDIM, BDIM>>>(dev_b, dev_b, dev_temp, N);
  cudaMemcpy(temp,dev_temp, N * sizeof(FP), cudaMemcpyDeviceToHost);
  const FP THRESHOLD = sqrt(reduce(temp, N)) / 1000000.;

  gpu_matmulvec<<<N/BDIM, BDIM>>>(dev_A, dev_row, dev_col, dev_x, dev_r, Nz);

  gpu_vecop<<<N/BDIM, BDIM>>>(dev_b, dev_r, dev_r, -1., N);
  gpu_vecdot<<<N/BDIM, BDIM>>>(dev_r, dev_r, dev_temp, N);
  cudaMemcpy(temp,dev_temp, N * sizeof(FP), cudaMemcpyDeviceToHost);
  rho = reduce(temp, N);

  printf("Stopping tolerance: %.6e\n", THRESHOLD);
  printf("Initial residuals: %.6e\n", sqrt(rho));

  for(iter = 0; iter < MAX_ITERATION && sqrt(rho) >= THRESHOLD; iter++) {
    prev_rho = rho;
    gpu_vecdot<<<N/BDIM, BDIM>>>(dev_r, dev_r, dev_temp, N);
    cudaMemcpy(temp,dev_temp, N * sizeof(FP), cudaMemcpyDeviceToHost);
    rho = reduce(temp, N);
    // printf("current residuals: %f\n", sqrt(rho));
    if(iter == 0) {
      gpu_vecassign<<<N/BDIM, BDIM>>>(dev_p, dev_r, N);
    } else {
        FP beta = rho / prev_rho;
        // printf("beta: %.6e\n", beta);
        gpu_vecop<<<N/BDIM, BDIM>>>(dev_r, dev_p, dev_p, beta, N);
    }
    // q = Ap
    gpu_vecreset<<<N/BDIM, BDIM>>>(dev_q, N);
    gpu_matmulvec<<<N/BDIM, BDIM>>>(dev_A, dev_row, dev_col, dev_p, dev_q, Nz);
    //a = pTq
    gpu_vecdot<<<N/BDIM, BDIM>>>(dev_p, dev_q, dev_temp, N);
    cudaMemcpy(temp,dev_temp, N * sizeof(FP), cudaMemcpyDeviceToHost);
    FP alpha = reduce(temp, N);
    // printf("alpha: %.6e\n", alpha);
    // x = x + ap
    gpu_vecop<<<N/BDIM, BDIM>>>(dev_x, dev_p, dev_x, alpha, N);
    // vecop(x, p, x, alpha, N);
    // r = r -aq
    gpu_vecop<<<N/BDIM, BDIM>>>(dev_r, dev_q, dev_r, -alpha, N);
    // vecop(r, q, r, -alpha, N);

  }
  cudaEventRecord(stop, 0); // instrument code to measure end time
  cudaEventSynchronize(stop);
  cudaEventElapsedTime(&elapsed_time_ms, start, stop );

  printf("#CG iterations: %d\n", iter);
  printf("Final residuals: %.6e\n", sqrt(rho));
  printf("Time to calculate results on GPU: %f seconds.\n", elapsed_time_ms/1000.); 





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
  cudaFree(dev_temp);

  // cudaEventDestroy(start);
  // cudaEventDestroy(stop);

  return 0;
}
