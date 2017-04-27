#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mpi.h"
#include "timing.h"
#define DIMENSION 3

typedef struct node {
	double body[7];
	struct node *next;
} node;


int which_oct(double x, double y, double z) {
	int oct = 0;
	if(z < 0) oct += 4;
	if(y < 0) oct += 2;
	if(x < 0) oct += 1;
	return oct;
}

int main(int argc, char** argv) {
	int N, K;
	double dt, mass;
	int rank, size, tag = 99, root = 0;
	int *scounts, *rcounts, *sdispls, *rdispls;
	double **data, **bodies;
	double wct0, wct1, cputime;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	scounts = (int *) calloc(size, sizeof(int));
	rcounts = (int *) calloc(size, sizeof(int));
	sdispls = (int *) calloc(size, sizeof(int));
	rdispls = (int *) calloc(size, sizeof(int));
	if(rank == root) { //master
		/*read data from file*/
		FILE *file = fopen("/home/fas/cpsc424/cg736/as/as4/data/testdata1", "r");
		// get N
		fscanf(file, "%d", &N);	
		// get K
		fscanf(file, "%d", &K);
		// get delta t
		fscanf(file, "%lf", &dt);
		printf("N: %d, K: %d, dt: %lf\n", N, K, dt);
		// 7 rows and N columns to hold data
		// 0th row holds masses
		// 1st to 3rd row hold positions
		// 4th to 6th row hold velocities
		double **temp = (double **) malloc (7 * sizeof(double *));
		for(int i=0; i<7; i++) {
			temp[i] = (double *) calloc (N, sizeof(double));
		}
		// get masses of bodies
		for(int i=0; i<N; i++) {
			fscanf(file, "%lf", &temp[0][i]);
		}
		// get positions of bodies
		for(int i=0; i<N; i++) {
			for(int j=1; j<1+DIMENSION; j++)
				fscanf(file, "%lf", &temp[j][i]);
		}
		// get velocities of bodies
		for(int i=0; i<N; i++) {
			for(int j=1+DIMENSION; j<1+2*DIMENSION; j++)
				fscanf(file, "%lf", &temp[j][i]);
		}
		fclose(file);
		// calculate scounts and sdispls
		// first pass to calculate scounts
		for(int i=0; i<N; i++) {
			int oct = which_oct(temp[1][i], temp[2][i], temp[3][i]);
			scounts[oct] ++;
		}
		for(int i=1; i<size; i++) {
			sdispls[i] = sdispls[i-1] + scounts[i-1];
		}
			// second pass to sort data
		int *offset = (int *) calloc(size, sizeof(int));
		memcpy(offset, sdispls, size*sizeof(int));
		data = (double **) malloc (7 * sizeof(double *));
    	for(int i=0; i<7; i++) {
        	data[i] = (double *) calloc (N, sizeof(double));
        }
		for(int i=0; i<N; i++) {
			int oct = which_oct(temp[1][i], temp[2][i], temp[3][i]);
			int off = offset[oct]++;
			for(int j=0; j<7; j++) {
				data[j][off] = temp[j][i];
			}
		}
		// free memory
		free(offset);
		for(int i=0; i<7; i++) {
			free(temp[i]);
		}
		free(temp);
	}
	// distribute N, K, dt, scounts and sdispls
	MPI_Bcast(&N, 1, MPI_INT, root, MPI_COMM_WORLD);
	MPI_Bcast(&K, 1, MPI_INT, root, MPI_COMM_WORLD);
	MPI_Bcast(&dt, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
	MPI_Bcast(scounts, size, MPI_INT, root, MPI_COMM_WORLD);
	MPI_Bcast(sdispls, size, MPI_INT, root, MPI_COMM_WORLD);
	// create receive buffer to hold bodies within its octant
	bodies = (double **) malloc(7 * sizeof(double *));
	for(int i=0; i<7; i++) {
		bodies[i] = (double *) calloc(scounts[rank], sizeof(double));
	}
	if(rank == 2){
		for(int i=0; i<size; i++) {
			printf("%d ", scounts[i]);
		}
		printf("\n");
		for(int i=0;i<size; i++) {	
			printf("%d ", sdispls[i]);
		}
		printf("\n");
		for(int i=0; i<7; i++) {
			for(int j=0; j<scounts[rank]; j++) {
				printf("%.6e ", bodies[i][j]);
			}
		}
	}
	printf("I am %d, and i receve %d data\n", rank, scounts[rank]);
	MPI_Barrier(MPI_COMM_WORLD);
	for(int i=0; i<7; i++) {
		if(rank == root)
			MPI_Scatterv(data[i], scounts, sdispls, MPI_DOUBLE, bodies[i], scounts[rank], MPI_DOUBLE, 0, MPI_COMM_WORLD);
		else 	
			MPI_Scatterv(data, scounts, sdispls, MPI_DOUBLE, bodies[i], scounts[rank], MPI_DOUBLE, 0, MPI_COMM_WORLD);
	}
	if(rank == 2){
		for(int i=0; i<size; i++) {
			printf("%d ", scounts[i]);
			printf("%d ", sdispls[i]);
		}
		for(int i=0; i<7; i++) {
			for(int j=0; j<scounts[rank]; j++) {
				printf("%.6e ", bodies[i][j]);
			}
		}
	}
	// initialization finishes, free orginal data on master
	if(rank == root) {
		for(int i=0; i<7; i++) free(data[i]);
		free(data);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	printf("\n\nalive\n\n");
	MPI_Finalize();	
	return 0;
}
