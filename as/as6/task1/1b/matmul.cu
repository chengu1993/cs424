#define FP double

#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <math.h>

__global__ void gpu_matrixmult(FP *a,FP *b, FP *c, int n, int p, int m) {

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
  int Block_Dim = 1; //Block dimension, x and y, square

  int n, p, m; // matrix dimension
  FP *a,*b,*c;
  FP *dev_a, *dev_b, *dev_c;

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

  if ((argc<7) || (argc>8)) {
    printf("Usage: matmul <matrix dim n> <matrix dim p> <matrix dim m> <block dim> <grid dim x> <grid dim y> [<dev num>]\n");
    exit (-1);
  }

  n = atoi(argv[1]);
  p = atoi(argv[2]);
  m = atoi(argv[3]);

  Block_Dim = atoi(argv[4]); // Square block
  if (Block_Dim*Block_Dim > 1024) {
    printf("Error, too many threads in block\n");
    exit (-1);
  }

  Grid_Dim_X = atoi(argv[5]);
  Grid_Dim_Y = atoi(argv[6]);
  if (Grid_Dim_X * Grid_Dim_Y * Block_Dim * Block_Dim < n * m) {
    printf("Error, number of threads in x/y dimensions less than number of array elements\n");
    exit (-1);
  }

  if (argc==8) {
    gpunum = atoi(argv[7]); // Device number
    if ((gpunum > 2) || (gpunum < 0)) {
      printf("Error, Device number must be 0, 1, or 2\n");
      exit (-1);
    }
  }
  cudaSetDevice(gpunum);
  printf("Using device %d\n",gpunum);
  
  printf("Matrix Dimension = %d\n",n);
  printf("Block_Dim = %d, Grid_Dim_X = %d, Grid_Dim_Y = %d\n",Block_Dim,Grid_Dim_X, Grid_Dim_Y);

  dim3 Grid(Grid_Dim_X, Grid_Dim_Y); //Grid structure
  dim3 Block(Block_Dim, Block_Dim); //Block structure


  a = (FP*) malloc(n * p * sizeof(FP)); // dynamically allocated memory for arrays on host
  b = (FP*) malloc(p * m * sizeof(FP));
  c = (FP*) malloc(n * m * sizeof(FP)); // results from GPU
  srand(12345);
  for(i=0; i<n; i++)
    for(j=0; j < p; j++) {
      a[i * p + j] = (FP) rand() / (FP) RAND_MAX;
      //      a[i * p + j] = (FP) i+j; // may be helpful for debugging
    }

  for(i=0; i<p; i++)
    for(j=0; j<m; j++) {
      b[i * m + j] = (FP) rand() / (FP) RAND_MAX;
      //      b[i * n + j] = (FP) i+j; // may be helpful for debugging
    }

  // ------------- COMPUTATION DONE ON GPU ----------------------------

  cudaMalloc((void**)&dev_a, n * p * sizeof(FP)); // allocate memory on device
  cudaMalloc((void**)&dev_b, p * m * sizeof(FP));
  cudaMalloc((void**)&dev_c, n * m * sizeof(FP));

  cudaMemcpy(dev_a, a , n * p * sizeof(FP), cudaMemcpyHostToDevice);
  cudaMemcpy(dev_b, b , p * m * sizeof(FP), cudaMemcpyHostToDevice);

  cudaEventCreate(&start); // instrument code to measure start time
  cudaEventCreate(&stop);
  
  cudaEventRecord(start, 0);
  // cudaEventSynchronize(start); // not needed

  gpu_matrixmult<<<Grid,Block>>>(dev_a, dev_b, dev_c, n, p, m);

  cudaEventRecord(stop, 0); // instrument code to measure end time
  cudaEventSynchronize(stop);
  cudaEventElapsedTime(&elapsed_time_ms, start, stop );

  cudaMemcpy(c,dev_c, n * m * sizeof(FP), cudaMemcpyDeviceToHost);

  printf("Time to calculate results on GPU: %f ms.\n", elapsed_time_ms); // exec. time

  // ------------- COMPUTATION DONE ON HOST CPU ----------------------------
  // DEBUGGING USE ONLY (AND FOR LIMITED NUMBERS OF TIMING RUNS)

  cudaEventRecord(start, 0); // use same timing
  // cudaEventSynchronize(start); // not needed


  //cpu_matrixmult(a,b,c, n); // do calculation on host (NOTE: This computes the diff with GPU result.)
  //kij(a, b, c, n, p, m); // 

  cudaEventRecord(stop, 0); // instrument code to measue end time
  cudaEventSynchronize(stop);
  cudaEventElapsedTime(&elapsed_time_ms, start, stop );

  printf("Time to calculate results on CPU: %f ms.\n", elapsed_time_ms); // exec. time
  //print(c, n, m);
// ------------------- check device creates correct results -----------------

  double error, suma, sumb, sumc, ai, bi, ci;
  suma = 0.; sumb = 0; sumc = 0;
  for(i=0; i<n*p; i++) {
    ai = (double) a[i];
    suma += ai * ai;
  }
  for(i=0; i<p*m; i++) {
	bi = (double) b[i];
    sumb += bi * bi;
  }
  for(i=0; i<n*m; i++) {
	ci = (double) c[i];
    sumc += ci * ci;
  }
  suma = sqrt(suma);
  sumb = sqrt(sumb);
  sumc = sqrt(sumc);
  error =  sumc/(n*suma*sumb);
  printf("Scaled error between GPU and CPU: %e\n", error);

// -------------- clean up ---------------------------------------

  free(a);
  free(b);
  free(c);
  cudaFree(dev_a);
  cudaFree(dev_b);
  cudaFree(dev_c);

  cudaEventDestroy(start);
  cudaEventDestroy(stop);

  return 0;
}
