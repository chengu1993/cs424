#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include<unistd.h>
#include "mpi.h"
#include "timing.h"
#define MIN(a,b) (((a)<(b))?(a):(b))

//utility function get the size of the coloumn block based on the block index
int get_block_size(int block_idx, int size){
	int idx1 = block_idx * size;
	int idx2 = (block_idx + 1) * size;
	return  idx2 * (idx2 + 1) / 2 - idx1 * (idx1 + 1) / 2; 
}

void main(int argc, char** argv){

	int rank, size, tag = 99, root = 0;
	int N = atoi(argv[1]);
	double* C, * wall_time, * cal_time;
	MPI_Status status;
	int sizeAB = N*(N+1)/2; //Only enough space for the nonzero portions of the matrices
    int sizeC = N*N; // All of C will be nonzero, in general!
	double wctime, wctime0, wctime1, caltime, caltime0, caltime1, cputime;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	MPI_Barrier(MPI_COMM_WORLD);
	timing(&wctime0, &cputime);

	if(rank == root) { // master
		double* A = (double *) calloc(sizeAB, sizeof(double));
    	double* B = (double *) calloc(sizeAB, sizeof(double));	
		C = (double *) calloc(sizeC, sizeof(double));
	    wall_time = (double *) calloc(size, sizeof(double));
		cal_time = (double *) calloc(size, sizeof(double));
		srand(12345); // Use a standard seed value for reproducibility
		// This assumes A is stored by rows, and B is stored by columns. Other storage schemes are permitted
     	for (int i=0; i<sizeAB; i++) A[i] = ((double) rand()/(double)RAND_MAX);
     	for (int i=0; i<sizeAB; i++) B[i] = ((double) rand()/(double)RAND_MAX);
			
		//distribute A and B
		int offset = 0;
		for(int i=0; i<size; i++) {
			MPI_Send(A + offset, get_block_size(i, N/size), MPI_DOUBLE, i, tag, MPI_COMM_WORLD);
			MPI_Send(B + offset, get_block_size(i, N/size), MPI_DOUBLE, i, tag, MPI_COMM_WORLD);
			offset += get_block_size(i, N/size);
		}
		free(A);
		free(B);
	} 

	//Initialization to get row block and column block	
	int col = rank, size_B = get_block_size(rank, N/size);	
	double* buffer_A = (double *) calloc(size_B, sizeof(double));
	double* buffer_B = (double *) calloc(size_B, sizeof(double));
	double* buffer_C = (double *) calloc(sizeC/size, sizeof(double));
	MPI_Recv(buffer_A, size_B, MPI_DOUBLE, root, tag, MPI_COMM_WORLD, &status);
	MPI_Recv(buffer_B, size_B, MPI_DOUBLE, root, tag, MPI_COMM_WORLD, &status);
	

	//start computing C
	for(int iter=0; iter<size; iter++) {
		timing(&caltime0, &cputime);
		for(int i=rank*N/size, iA=0; i<(rank+1)*N/size; i++){
			int iC = (i - rank*N/size) * N + col*N/size;
			for(int j=col*N/size, iB=0; j<(col+1)*N/size; j++, iC++){
				for(int k=0; k<=MIN(i,j); k++) {
					buffer_C[iC] += buffer_A[iA+k] * buffer_B[iB+k];
				}
				iB += (j + 1);
			}
			iA += (i + 1);
		}
		timing(&caltime1, &cputime);
		caltime += caltime1 - caltime0;

		if(iter == size-1) break;
		int original_size_B = size_B;
		size_B = get_block_size((col+size-1)%size, N/size);
		double * temp_buffer = buffer_B;
		buffer_B = (double*) calloc(size_B, sizeof(double));
		//to avoid deadlock, odd rank processes first send then receive, 
		//even rank processes first receive then send.
		if((rank % 2) == 1){
			MPI_Send(temp_buffer, original_size_B, MPI_DOUBLE, (rank+1)%size, tag, MPI_COMM_WORLD);
			MPI_Recv(buffer_B, size_B, MPI_DOUBLE, (rank-1)%size, tag, MPI_COMM_WORLD, &status);
		} else {
			MPI_Recv(buffer_B, size_B, MPI_DOUBLE, (rank-1)%size, tag, MPI_COMM_WORLD, &status);
			MPI_Send(temp_buffer, original_size_B, MPI_DOUBLE, (rank+1)%size, tag, MPI_COMM_WORLD);
		}
		free(temp_buffer);
		col = (col+size-1)%size;

	}
	MPI_Barrier(MPI_COMM_WORLD);

	//gather the result of C
	MPI_Gather(buffer_C, sizeC/size, MPI_DOUBLE, C, sizeC/size, MPI_DOUBLE, root, MPI_COMM_WORLD);
	//worker report their time for computation and communication to root
	MPI_Barrier(MPI_COMM_WORLD);	
	timing(&wctime1, &cputime);
	wctime = wctime1 - wctime0;
	MPI_Gather(&wctime, 1, MPI_DOUBLE, wall_time, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
	MPI_Gather(&caltime, 1, MPI_DOUBLE, cal_time, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
	free(buffer_A);
	free(buffer_B);
	free(buffer_C);
	//print out timing
	if(rank == root){
		double overral_time, overral_cal, overral_com;
		//printf("walltime:");
		for(int i=0; i<size; i++) {
			//printf(" | %f", wall_time[i]);
			overral_time += wall_time[i];
			overral_cal += cal_time[i];
			overral_com += wall_time[i] - cal_time[i];
		}
		//printf("\ncalculation:");
		for(int i=0; i<size; i++){
			//printf(" | %f", cal_time[i]);
		}
		//printf("\ncommunication:");
		for(int i=0; i<size; i++){
			//printf(" | %f", wall_time[i] - cal_time[i]);
		}
		//printf("\nSum of overral wall time is %f.\n", overral_time);
		//printf("Sum of overral calcultion time is %f.\n", overral_cal);
		//printf("Sum of overral communication time is %f.\n", overral_com);
		for(int i=0; i<sizeC; i++) printf("%f ", C[i]);	
  		//printf("Matrix multiplication times:\n   N      TIME (secs)\n -----   -------------\n");
		//printf ("  %5d    %9.4f\n", N, wctime1 - wctime0);
		free(C);
	}
	MPI_Finalize();
}

