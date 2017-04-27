#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "timing.h"
#define DIMENSION 3

/*
 *  Author: Chen Gu
 *  Date:3/29/2017
 */

typedef struct body {
	double v[DIMENSION];
	double p[DIMENSION];
	double m;
} body;

int N, K;
double dt, mass;
body* bodies;

/* Read data from file */
void read(char* filename) {
	// get N
	scanf("%d", &N);
	// get K
	scanf("%d", &K);
	// get dt
	scanf("%lf", &dt);
	// initialize boides
	bodies = (body*) malloc(N * sizeof(body));
	// get masses of bodies
	for(int i=0; i<N; i++) {
		scanf("%lf", &bodies[i].m);
		mass += bodies[i].m;
	}
	// get positions of bodies
	for(int i=0; i<N; i++) {
		for(int j=0; j<DIMENSION; j++) 
			scanf("%lf", &bodies[i].p[j]);
	}
	// get velocities of bodies
	for(int i=0; i<N; i++) {
		for(int j=0; j<DIMENSION; j++) 
			scanf("%lf", &bodies[i].v[j]);
	}

	/*printout bodies for test*/
	/*for(int i=0; i<N; i++) {
		printf("body %d, mass: %lf, vx: %lf, vy: %lf, vz: %lf\n",
			i, bodies[i].m, bodies[i].v[0], bodies[i].v[1], bodies[i].v[2]);
	}*/
}

double distance(body b1, body b2) {
	double d;
	for(int i=0; i<DIMENSION; i++) d += pow(b1.p[i] - b2.p[i], 2);
	return d; 
}


/* print out Center of Mass and Average Velocity */
void print_comav() {
	double com[DIMENSION] = {0.0}, av[DIMENSION] = {0.0};
	for(int i=0; i<N; i++) {
		for(int j=0; j<DIMENSION; j++) { 
			com[j] += bodies[i].p[j] * bodies[i].m;
			av[j] += bodies[i].v[j];
		}
	}
	printf("\tCenter of Mass:   (%.6e, %.6e, %.6e)\n", 
			com[0]/mass, com[1]/mass, com[2]/mass);
	printf("\tAverage Velocity: (%.6e, %.6e, %.6e)\n",
			av[0]/N, av[1]/N, av[2]/N);
}


void simulation() {
	double wct1, wct2, cput, time = dt;
	timing(&wct1, &cput);
	//print out initial info
	printf("\n\nInitial Conditions (time = 0.0)\n\n");
	print_comav();
	
	for(int i=1; i<=K; i++, time+=dt) { // for every time step
		double a[N][DIMENSION];
		memset(a, 0.0, sizeof(double) * N * DIMENSION);
		for(int j=0; j<N; j++) { // for every body
			/*accumalting force in all dimension*/
			for(int k=j+1; k<N; k++) { // for every other body
				double sq_d = distance(bodies[j], bodies[k]);
				if(sq_d > 25.) continue; // skip itself and bodies to far away
				double f = bodies[j].m * bodies[k].m / pow(sqrt(sq_d), 3);
				for(int d=0; d<DIMENSION; d++) {
					a[j][d] += f * (bodies[k].p[d]-bodies[j].p[d]);
					a[k][d] += f * (bodies[j].p[d]-bodies[k].p[d]);
				}				
			}
			/*calculate accelerate in all dimension*/
			for(int d=0; d<DIMENSION; d++) {
				a[j][d] /= bodies[j].m;
			}
		}
		for(int j=0; j<N; j++) {
			/*update postions and speed*/
			for(int d=0; d<DIMENSION; d++) {
				// using average speed to update positions
				double avg_speed = bodies[j].v[d] + dt/2*a[j][d];
				bodies[j].p[d] += avg_speed * dt;
				// update speed
				bodies[j].v[d] += dt * a[j][d];
			}
		}
		if((i%128) == 0 || i == K){
			printf("\n\nConditions after timestep %d (time = %lf)\n\n",
				 i, time);
			print_comav();
		}
	}
	timing(&wct2, &cput);
	printf("\nTime for %d timesteps with %d bodies: %lf seconds\n",
			K, N, wct2-wct1);
}

int main(int argc, char** argv) {
	read("testdata1");
	simulation();
	free(bodies);
	return 0;
}
