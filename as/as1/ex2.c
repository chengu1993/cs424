#include "timing.h"
#include "dummy.h"
#include <math.h>

const int RAND_MAX = 100;


double dp_gen(){
	double drand_max = 100.0 / (double) RAND_MAX;
	return drand_max * (double) rand();
}


void vector(){

	for(int k=3; k<=24; k++){
		int N = floor(pow(2.1, k));
		double * A = (double *) calloc(sizeof(double));
		double * B = (double *) calloc(sizeof(double));
		double * C = (double *) calloc(sizeof(double));
		double * D = (double *) calloc(sizeof(double));
		for(int i=0; i<N; i++){
			B[i] = dp_gen();
			C[i] = dp_gen();
			D[i] = dp_gen(); 
		} 
	}
	int repeat = 1;
	double runtime=0.;
	for(; runtime<.1; repeat*=2) {
		timing(&wcs, &ct);
		for(r=0; r<repeat; ++r) {
			/* PUT THE KERNEL BENCHMARK LOOP HERE */
			for(int i=0; i<N; i++){
				A[i] = B[i] + C[i] * D[i];
			}
			if (A[N >> 1] < 0) dummy(A); // fools the compiler
		}
		timing(&wce, &ct);
		runtime = wce - wcs; 
	}
	repeat/=2;
}


int main(){
	return 0;
}
