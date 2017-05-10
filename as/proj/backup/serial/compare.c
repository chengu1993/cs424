#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "timing.h"
#define MAX_ITER 1500
#define FP float

//perform c = a + b * num; a, b, c are vectors, num is scalar;
void vectorOp(FP* a, FP* b, FP* c, FP num, int sz){
	for(int i = 0; i < sz; i++){
		c[i] = a[i] + b[i] * num;
	}
}
//perform L2 norm on vector b;
FP norm(FP* b, int sz){
	FP res = .0;
	for(int i = 0; i < sz; i++){
		res += b[i] * b[i];
	}
	res = sqrt(res);
	return res;
}
// perform vector dot multiply on vector a and vector b, store results in res;
FP dot(FP* a, FP* b, int sz){
	FP res = .0;
	for(int i = 0; i < sz; i++){
		res += a[i] * b[i];
	}
	return res;

}
//perform multiply on matrix A and vector p, store results in res;
void multiply(FP* A, int* row, int* col, FP* p, FP* res, int sz){
	for(int i = 0; i < sz; i++){
		res[row[i]] += p[col[i]] * A[i];
	}
}
//set numbers in A
int set(FP* A, int* row, int* col, int startidx, int startidy, int n, int num1, int num2, int idx){
	for(int j = 0; j < n; j++){
		row[idx] = startidx + j;
		col[idx] = startidy + j;
		A[idx] = num1;
		idx++;
		if(j != 0){
			row[idx] = startidx + j;
			col[idx] = startidy + j - 1;
			A[idx] = num2;
			idx++;
		}
		if(j != (n - 1)){
			row[idx] = startidx + j;
			col[idx] = startidy+ j + 1;
			A[idx] = num2;
			idx++;
		}
	}
	return idx;
}
int main(int argc, char *argv[]) {
	int n, N;
	n = atoi(argv[1]);
	N = n * n;
	FP *x, *b, *A, *r, *p, *q;
	double wct = .0, wct0 =.0, wct1 = .0, cput = .0;
	//timing(&wct, &cput);
	int *col, *row;
	FP cur_d, prev_d, alpha, beta;
	int i, j;
	x = (FP *) calloc(N, sizeof(FP));
	b = (FP *) calloc(N, sizeof(FP));
	r = (FP *) calloc(N, sizeof(FP));
	p = (FP *) calloc(N, sizeof(FP));
	q = (FP *) calloc(N, sizeof(FP));
	A = (FP *) calloc(9 * N, sizeof(FP));
	col = (int *) calloc(9 * N, sizeof(int));
	row = (int *) calloc(9 * N, sizeof(int));
	int idx = 0;
	// set numbers in A
	for(i = 0; i < n; i++){
		idx = set(A, row, col, i * n, i * n, n, 20, -4, idx);
		if(i != n - 1) idx = set(A, row, col, i * n, i * n + n, n, -4, -1, idx);
		if(i != 0) idx = set(A, row, col, i * n, i * n - n, n, -4, -1, idx);
	}

	// for(int i=0; i<9*N; i++){
	// 	printf("element:%f row:%d, col:%d\n", A[i], row[i], col[i]);
	// }

	//debug
	// FP* B;
	// B = (FP *) calloc(N * N, sizeof(FP));
	// for(i = 0; i < idx; i++){
	// 	B[row[i] * N + col[i]] = A[i];
	// }
	// for(i = 0; i < N; i++){
	// 	for(j = 0; j < N; j++){
	// 		printf("%f ", B[i * N + j]);
	// 	}
	// 	printf("\n");
	// }
	
	//set numbers in b
	FP num = 6.0 / (n + 1) / (n + 1);
	b[(n / 2 - 1)* n + (n / 2 - 1)] = num;
	b[(n / 2 - 1)* n + (n / 2)] = num;
	b[(n / 2)* n + (n / 2 - 1)] = num;
	b[(n / 2)* n + (n / 2)] = num;
	// for(i = 0; i < N; i++){
	// 	if(b[i] != .0){
	// 		printf("i: %d, j: %d b:%f\n", i / n + 1, i % n + 1, b[i]);
	// 	}
	// }
//	timing(&wct0, &cput);
	// for(int i = 0; i < N; i++) x[i] = i;
	multiply(A, row, col, x, r, 9 * N ); // r = multiply(A, x);
	// for(int i = 0; i < N; i++) printf("x%d, %f ", i, r[i]);
	vectorOp(b, r, r, -1, N); //r = b + r * (-1);
	FP limit = norm(b, N) / 1000000.0;
	printf("the initial residual is: %f .\n", norm(r, N));
	printf("the limit is: %.10lf .\n", limit);
	for(i = 0; i < MAX_ITER; i++){
		// printf("residual is: %f .\n", norm(r, N));
		if(norm(r, N) <= limit) break;
		cur_d = dot(r, r, N);
		//printf("cur_d: %f \n", cur_d);
		if(i == 0){
			for(j = 0; j < N; j++) p[j] = r[j];
		}else{
			beta = (FP) cur_d / prev_d;
			// printf("beta: %f\n", beta);
			// printf("beta: %f ", beta);
			vectorOp(r, p, p, beta, N); //p = r + beta * p;
		}
		for(j = 0; j < N; j++) q[j] = .0;
		multiply(A, row, col, p, q, 9 * N ); // q = multiply(A, p);
		alpha = dot(p, q, N);
		// printf("alpha: %f\n", alpha);
		vectorOp(x, p, x, alpha, N); //x = x + alpha * p;
		vectorOp(r, q, r, (-1) * alpha, N); //r = r - alpha * q;
		// for(int k = 0; k < N; k++){
		// 	if(r[k] != .0){
		// 		printf("i: %d, r:%.6e\n", k, r[k]);
		// 	}
		// }
		prev_d = cur_d;
	}
//	timing(&wct1, &cput);
	printf("total elapsed time: %f, CG costs time : %f \n", wct1 - wct, wct1 - wct0);
	printf("after %d rounds, the final residual is: %.6e .\n", i, norm(r, N));
}
