#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include<unistd.h>
#include "mpi.h"
#include "timing.h"
#define MIN(a,b) (((a)<(b))?(a):(b))

main (int argc, char** argv){

	int rank, size, tag = 99, root = 0;
	int *scounts, *rcounts, *displs;
	MPI_Request request1, request2;
	MPI_Status status;
    int N = atoi(argv[1]);
	double *A, *B, *C, *wall_time, *cal_time;
	int sizeAB = N*(N+1)/2; //Only enough space for the nonzero portions of the matrices
    int sizeC = N*N; // All of C will be nonzero, in general!
	double wctime, wctime0, wctime1, caltime, caltime0, caltime1, cputime;	

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// block information, 0th elements is start index of block(inclusive), 1st element is
	// the end index of block(exclusive), 2nd element is the size of the block.
	int* block_info = (int *) calloc(3 * size, sizeof(int)); 	
	if(rank == root) { // master
		A = (double *) calloc(sizeAB, sizeof(double));
    	B = (double *) calloc(sizeAB, sizeof(double));	
		C = (double *) calloc(sizeC, sizeof(double));
        wall_time = (double *) calloc(size, sizeof(double));
        cal_time = (double *) calloc(size, sizeof(double));
		srand(12345); // Use a standard seed value for reproducibility
		// This assumes A is stored by rows, and B is stored by columns. Other storage schemes are permitted
     	for (int i=0; i<sizeAB; i++) A[i] = ((double) rand()/(double)RAND_MAX);
     	for (int i=0; i<sizeAB; i++) B[i] = ((double) rand()/(double)RAND_MAX);
			
	} 
	//distribute A and B
	int offset = 0, current_idx = 0;
	double avg_size = sizeAB / size;
	for(int i=0; i<size-1; i++) {
		block_info[3 * i] = current_idx;
		int cur_size = ++current_idx;
		while(cur_size + current_idx + 1 <= avg_size){
			cur_size += ++current_idx;
		}
		block_info[3 * i + 1] = current_idx;
		block_info[3 * i + 2] = cur_size;
		offset += cur_size;
	}
	//deal with last worker
	block_info[3 * size - 3] = current_idx;
	block_info[3 * size - 2] = N;
	block_info[3 * size - 1] = sizeAB-offset;
	
	//calcualte scounts and displs to scatter A and B
	scounts = (int *) calloc(size, sizeof(int));
	displs = (int *) calloc(size, sizeof(int));
	scounts[0] = block_info[2];
	displs[0] = 0;
	for(int i=1; i<size; i++) {
		scounts[i] = block_info[3 * i + 2];
		displs[i] = displs[i-1] + scounts[i-1];
	}	
	if(rank == root) {
		for(int i=0; i<size; i++) printf("%d ", scounts[i]);
	}
	int col = rank, size_B = block_info[3 * rank + 2];	
	//Initialization to get row block and column block
	double* buffer_A = (double *) calloc(size_B, sizeof(double));
	double* buffer_B = (double *) calloc(size_B, sizeof(double));
	MPI_Scatterv(A, scounts, displs, MPI_DOUBLE, buffer_A, size_B, MPI_DOUBLE, root, MPI_COMM_WORLD);
	MPI_Scatterv(B, scounts, displs, MPI_DOUBLE, buffer_B, size_B, MPI_DOUBLE, root, MPI_COMM_WORLD);
	//Broadcast block information	
	//MPI_Bcast(block_info, 3 * size, MPI_INT, root, MPI_COMM_WORLD);
	int size_C = N * (block_info[3*rank+1] - block_info[3*rank]);
	double* buffer_C = (double *) calloc(size_C, sizeof(double));
	
	MPI_Barrier(MPI_COMM_WORLD);
	timing(&wctime0, &cputime);
	
	//start computing C
	for(int iter=0; iter<size; iter++) {
		// Overlay send receive with computation
		MPI_Isend(buffer_B, size_B, MPI_DOUBLE, (rank+1)%size, tag, MPI_COMM_WORLD, &request1);
		size_B = block_info[3 * ((col+size-1)%size) + 2];
		// Use another buffer to receive
		double* temp_buffer = (double*) calloc(size_B, sizeof(double));
		MPI_Irecv(temp_buffer, size_B, MPI_DOUBLE, (rank+size-1)%size, tag, MPI_COMM_WORLD, &request2);
		
		timing(&caltime0, &cputime);
		for(int i=block_info[3*rank], iA=0; i<block_info[3*rank+1]; i++){
			for(int j=block_info[3*col], iB=0; j<block_info[3*col+1]; j++){
				for(int k=0; k<=MIN(i,j); k++) {		
					int iC = (i - block_info[3*rank]) * N + j;
					buffer_C[iC] += buffer_A[iA+k] * buffer_B[iB+k];
				}
				iB += (j + 1);
			}
			iA += (i + 1);
		}
		timing(&caltime1, &cputime);
        caltime += caltime1 - caltime0;
		MPI_Wait(&request1, &status);
		MPI_Wait(&request2, &status);
		// Swap buffer
		double* garbage = buffer_B;
		buffer_B = temp_buffer;
		free(garbage);	
		col = (col+size-1)%size;
	}
	MPI_Barrier(MPI_COMM_WORLD);
	timing(&wctime1, &cputime);
	
	// Gather result C
	displs = (int *) calloc(size, sizeof(int));
	rcounts = (int *) calloc(size, sizeof(int));
	if(rank == 0){
		int offset = 0;
		for(int i=0; i<size; i++){
			displs[i] = offset;
			rcounts[i] = N * (block_info[3*i+1] - block_info[3*i]);
			offset += rcounts[i];
		}
	}
	MPI_Gatherv(buffer_C, size_C, MPI_DOUBLE, C, rcounts, displs, MPI_DOUBLE, root, MPI_COMM_WORLD);
	
	// Gather timing
	MPI_Barrier(MPI_COMM_WORLD);
    timing(&wctime1, &cputime);
    wctime = wctime1 - wctime0;
    MPI_Gather(&wctime, 1, MPI_DOUBLE, wall_time, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
    MPI_Gather(&caltime, 1, MPI_DOUBLE, cal_time, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);

	free(buffer_A);
	free(buffer_B);
	free(buffer_C);

	// Print out timing
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
        //for(int i=0; i<sizeC; i++) printf("%f\n", C[i]);
        free(A);
		free(B);
		free(C);
    }
	MPI_Finalize();

}
