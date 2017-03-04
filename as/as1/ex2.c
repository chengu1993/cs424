#include "timing.h"
#include "dummy.h"
#include <math.h>

double dp_gen(){
	double drand_max = 100.0 / (double) RAND_MAX;
	return drand_max * (double) rand();
}


void vector(){
    double wcs = 0.0, wce = 0.0, ct  =0.0;
	for(int k=3; k<=24; k++) {
        int N = floor(pow(2.1, k));
        double *A = (double *) calloc(N, sizeof(double));
        double *B = (double *) calloc(N, sizeof(double));
        double *C = (double *) calloc(N, sizeof(double));
        double *D = (double *) calloc(N, sizeof(double));
        for (int i = 0; i < N; i++) {
            B[i] = dp_gen();
            C[i] = dp_gen();
            D[i] = dp_gen();
        }

        int repeat = 1;
        double runtime = 0.;
        for (; runtime < .1; repeat *= 2) {
            timing(&wcs, &ct);
            for (int r = 0; r < repeat; ++r) {
                /* PUT THE KERNEL BENCHMARK LOOP HERE */
                for (int i = 0; i < N; i++) {
                    A[i] = B[i] + C[i] * D[i];
                }
                if (A[N >> 1] < 0) dummy(A); // fools the compiler
            }
            timing(&wce, &ct);
            runtime = wce - wcs;
        }
        repeat /= 2;
        printf("%d %f", N, 2 * N / (runtime / repeat));
        free(A);
        free(B);
        free(C);
        free(D);
    }
}

int main(){
	vector();
	return 0;
}
