#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mpi.h"
#include "timing.h"
#define DIMENSION 3

/*
 *  Author: Chen Gu
 *  Date: 3/31/2017
 */

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
	double **data = (double **) malloc(7 * sizeof(double *));
	double **bodies = (double **) malloc(7 * sizeof(double *));
	double wct0, wct1, cputime;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	scounts = (int *) calloc(size, sizeof(int));
	rcounts = (int *) calloc(size, sizeof(int));
	sdispls = (int *) calloc(size, sizeof(int));
	rdispls = (int *) calloc(size, sizeof(int));
	if(rank == root) { //master
		double m = 0, com[DIMENSION] = {0.}, av[DIMENSION] = {0.};
		// get N
		scanf("%d", &N);	
		// get K
		scanf("%d", &K);
		// get delta t
		scanf("%lf", &dt);
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
			scanf("%lf", &temp[0][i]);
			m += temp[0][i];
		}
		// get positions of bodies
		for(int i=0; i<N; i++) {
			for(int j=1; j<1+DIMENSION; j++)
				scanf("%lf", &temp[j][i]);
		}
		// get velocities of bodies
		for(int i=0; i<N; i++) {
			for(int j=1+DIMENSION; j<1+2*DIMENSION; j++)
				scanf("%lf", &temp[j][i]);
		}
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
		// print out initial conditions
		for(int i=0; i<N; i++) {
			for(int j=0; j<DIMENSION; j++) {
				com[j] += temp[1+j][i] * temp[0][i];
				av[j] += temp[4+j][i];
			}
		}
 		printf("\n\nInitial Conditions (time = 0.0)\n\n");
		printf("\t#boides each octant has: (%d, %d, %d, %d, %d, %d, %d, %d)\n", scounts[0], scounts[1], scounts[2], scounts[3], scounts[4], scounts[5], scounts[6], scounts[7]);
	 	printf("\tCenter of Mass:   (%.6e, %.6e, %.6e)\n",
            com[0]/m, com[1]/m, com[2]/m);
    	printf("\tAverage Velocity: (%.6e, %.6e, %.6e)\n",
            av[0]/N, av[1]/N, av[2]/N);


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
	for(int i=0; i<7; i++) {
		bodies[i] = (double *) calloc(scounts[rank], sizeof(double));
	}

	MPI_Barrier(MPI_COMM_WORLD);
	for(int i=0; i<7; i++) {
		MPI_Scatterv(data[i], scounts, sdispls, MPI_DOUBLE, bodies[i], scounts[rank], MPI_DOUBLE, root, MPI_COMM_WORLD);
	}
	// initialization finishes, free orginal data on master
	if(rank == root) {
		for(int i=0; i<7; i++) free(data[i]);
		free(data);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	timing(&wct0, &cputime);
	int body_owned = scounts[rank];
	double time = dt;
	/*start to simualte*/
	for(int i=1; i<=K; i++, time+=dt){
		
		for(int j=0; j<size; j++) {
			scounts[j] = sdispls[j] = rcounts[j] = rdispls[j] = 0;
		}
		// send bodies to other octant who may need it
		double **to_send = (double **) malloc(size*sizeof(double*));
		for(int j=0; j<size; j++) {
			to_send[j] = (double *) calloc(body_owned*size, sizeof(double));
		}
		double **to_recv = (double **) malloc(size*sizeof(double*));
		double **affected = (double **) malloc(size*sizeof(double*));
		for(int j=0; j<size; j++) scounts[j] = sdispls[j] = 0;
		for(int j=0; j<body_owned; j++) {
			int cur_oct  = which_oct(bodies[1][j], bodies[2][j], bodies[3][j]); // send to which oct
			int queue_length = 0, queue[8] = {0};
			if(abs(bodies[1][j]) <= 5.) { // within 5 DU of yz plane
				int send_oct = cur_oct ^ 1; // xor 001 to flip last bit
				queue[queue_length++] = send_oct;
			}
			if(abs(bodies[2][j]) <= 5.) { // within 5 DU of xz plane
				int send_oct = cur_oct ^ 2; // xor 010 to flip last two bit
				queue[queue_length++] = send_oct;
			}
			if(abs(bodies[3][j]) <= 5.) { // within 5 DU of xy plane
				int send_oct = cur_oct ^ 4; // xor 100 to flip most significant bit
				queue[queue_length++] = send_oct;
			}
			if(bodies[1][j] * bodies[1][j] + bodies[2][j] * bodies[2][j] + bodies[3][j] * bodies[3][j] <= 25.) { // with 5 DU of origin
				int send_oct = cur_oct ^ 7; // xor 111 to flip highest 2 bit;
				queue[queue_length++] = send_oct;
			}
			if(bodies[1][j] * bodies[1][j] + bodies[2][j] * bodies[2][j] <= 25.) {
				int send_oct = cur_oct ^ 3; // xor 011 to flip highest 2 bit;
				queue[queue_length++] = send_oct;
			}
			if(bodies[1][j] * bodies[1][j] + bodies[3][j] * bodies[3][j] <= 25.) {
				int send_oct = cur_oct ^ 5; // xor 101 to flip highest 2 bit;
				queue[queue_length++] = send_oct;
			}
			if(bodies[2][j] * bodies[2][j] + bodies[3][j] * bodies[3][j] <= 25.) {
				int send_oct = cur_oct ^ 6; // xor 111 to flip highest 2 bit;
				queue[queue_length++] = send_oct;
			}

			for(int k=0; k<queue_length; k++) {
				int oct = queue[k];
				int index = oct * body_owned + scounts[oct]++;
				for(int m=0; m<7; m++) {
					to_send[m][index] = bodies[m][j];
				}
			}
		}

		MPI_Alltoall(scounts, 1, MPI_INT, rcounts, 1, MPI_INT, MPI_COMM_WORLD);
		int body_affected = 0;
		for(int j=0; j<size; j++) body_affected += rcounts[j];
		for(int j=0; j<size; j++) {
			to_recv[j] = (double *) calloc(body_affected, sizeof(double));
			affected[j] = (double *) calloc(body_owned+body_affected, sizeof(double));
		}
		// set up send displacement
		for(int j=0; j<size; j++) {
			sdispls[j] = j * body_owned;
		}
		// set up receive displacement
		for(int j=1; j<size; j++) {
			rdispls[j] = rdispls[j-1] + rcounts[j-1];
		}
		for(int j=0; j<7; j++) {
			MPI_Alltoallv(to_send[j], scounts, sdispls, MPI_DOUBLE, to_recv[j], rcounts, rdispls, MPI_DOUBLE, MPI_COMM_WORLD);
		}

		// merge bodies for convenient
		for(int j=0; j<7; j++) {
			for(int k=0; k<body_owned; k++) 
				affected[j][k] = bodies[j][k];
			for(int k=0; k<body_affected; k++) 
				affected[j][k+body_owned] = to_recv[j][k];	
		}

		free(to_send);
		free(to_recv);

/***************************************************************************/	
		// start to calculate
		double **a = (double **) malloc(DIMENSION*sizeof(double *));
		for(int j=0; j<DIMENSION; j++){
			a[j] = (double *) calloc(body_owned, sizeof(double));
		}
		for(int j=0; j<body_owned; j++) {
			for(int k=j+1; k<body_owned+body_affected; k++) {
				double dis_sq = 0;
				for(int m=1; m<4; m++) 
					dis_sq += pow((bodies[m][j]-affected[m][k]), 2);  
				if(dis_sq > 25.) continue; // skip itself and bodies to far away
				double f = bodies[0][j] * affected[0][k] / pow(sqrt(dis_sq), 3);
				for(int d=0; d<DIMENSION; d++) {
					a[d][j] += f * (affected[d+1][k] - bodies[d+1][j]);
					/*take advantage of symmetry*/
					if(k < body_owned) 
						a[d][k] += f * (bodies[d+1][j] - affected[d+1][k]);
				}
			}
			/*calculate acceleration in 3 dimension*/
			for(int d=0; d<DIMENSION; d++) {
				a[d][j] /= bodies[0][j];
			}
		}
		for(int j=0; j<body_owned; j++) {
			/*update positions and speed*/
			for(int d=0; d<DIMENSION; d++) {
				// using average speed to update positions
				double avg_speed = bodies[1+DIMENSION+d][j] + dt/2*a[d][j];
				bodies[1+d][j] += avg_speed * dt;
				// update speed
				bodies[1+DIMENSION+d][j] += dt * a[d][j];
			}
		}
		for(int j=0; j<7; j++) free(affected[j]);
		for(int j=0; j<3; j++) free(a[j]);
		free(affected);
		free(a);
		
/***************************************************************************/	
		// send bodies to where it belongs
		to_send = (double **) malloc(7 * sizeof(double *));
		for(int j=0; j<7; j++) {
			to_send[j] = (double *) calloc(size * body_owned, sizeof(double));
		}
		to_recv = (double **) malloc(7 * sizeof(double *));
		for(int j=0; j<size; j++) {
			scounts[j] = sdispls[j] = rcounts[j] = rdispls[j] = 0;
		}
		// first pass to calculate scounts
		int queue_length = 0;
		int *queue = (int *) calloc(body_owned, sizeof(int));
		for(int j=0; j<body_owned; j++) {
			int oct = which_oct(bodies[1][j], bodies[2][j], bodies[3][j]);
			if(oct != rank) {
				int index = oct * body_owned + scounts[oct]++;
				for(int m=0; m<7; m++) 
					to_send[m][index] = bodies[m][j];
			} else {
				queue[queue_length++] = j;
			}
		}
	
		MPI_Alltoall(scounts, 1, MPI_INT, rcounts, 1, MPI_INT, MPI_COMM_WORLD);
		
		// set up send and receive displacement
		for(int j=1; j<size; j++) {
			sdispls[j] = j * body_owned;
			rdispls[j] = rdispls[j-1] + rcounts[j-1];
		}
		int body_to_add = rdispls[size-1] + rcounts[size-1];
		body_owned = queue_length + body_to_add;
		for(int j=0; j<7; j++) {
			to_recv[j] = (double *) calloc(body_to_add, sizeof(double));
		}
	   	for(int j=0; j<7; j++) {
			MPI_Alltoallv(to_send[j], scounts, sdispls, MPI_DOUBLE, to_recv[j], rcounts, rdispls, MPI_DOUBLE, MPI_COMM_WORLD);
		}
		double **temp = (double **) malloc(7 * sizeof(double *));
		for(int j=0; j<7; j++) {
			temp[j] = (double *) calloc(body_owned, sizeof(double));
			for(int k=0; k<queue_length; k++) {
				temp[j][k] = bodies[j][queue[k]];
			}			
			for(int k=0; k<body_to_add; k++) 
				temp[j][k+queue_length] = to_recv[j][k];	
		}
		
		for(int j=0; j<7; j++) free(bodies[j]);
		free(bodies);
		free(to_send);
		free(to_recv);
		free(queue);
		bodies = temp;
		
		if((i%128) == 0 || i == K) {
			int br[8] = {0};
			double mass_p = 0, com_p[DIMENSION] = {0.0}, av_p[DIMENSION] = {0.0};
			double com[DIMENSION] = {0.}, av[DIMENSION] = {0.};
			for(int j=0; j<body_owned; j++) {
				mass_p += bodies[0][j];
				for(int k=0; k<DIMENSION; k++) {
					com_p[k] += bodies[k+1][j] * bodies[0][j];
					av_p[k] += bodies[k+4][j];
				}
			}
			MPI_Gather(&body_owned, 1, MPI_INT, br, 1, MPI_INT, root, MPI_COMM_WORLD);
			MPI_Reduce(&mass_p, &mass, 1, MPI_DOUBLE, MPI_SUM, root, MPI_COMM_WORLD);	
			MPI_Reduce(com_p, com, DIMENSION, MPI_DOUBLE, MPI_SUM, root, MPI_COMM_WORLD);
			MPI_Reduce(av_p, av, DIMENSION, MPI_DOUBLE, MPI_SUM, root, MPI_COMM_WORLD);	
	
			if(rank == root) {
				printf("\n\nConditions after timestep %d (time = %.lf)\n\n", i, time);
				printf("\t#boides each octant has: (%d, %d, %d, %d, %d, %d, %d, %d)\n", br[0], br[1], br[2], br[3], br[4], br[5], br[6], br[7]);
				printf("\tCenter of Mass:     (%.6e, %.6e, %.6e)\n", com[0]/mass, com[1]/mass, com[2]/mass);
				printf("\tAverage Velocities: (%.6e, %.6e, %.6e)\n", av[0]/N, av[1]/N, av[2]/N);
			}
		}
	}
	timing(&wct1, &cputime);
   	if(rank == 0) {
		printf("\nTime for %d timesteps with %d bodies: %lf seconds\n",
            K, N, wct1-wct0);
	}
	MPI_Finalize();	
	return 0;
}
