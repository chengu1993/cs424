#define MAX_ITERATION 1500
#define FP float
#include <stdlib.h>
#include <math.h>
#include "timing.h"


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
            int base_col = col;
            //set up t0
            if (grid_row != 0) {
                for (int i = 0; i < 3; i++) {
                    int row_idx = row;
                    int col_idx = base_col + i;
                    if (t0_grid_left <= col_idx && base_col <= col_idx && col_idx < base_col + n &&
                        col_idx < t0_grid_right) {
                        A[index] = t[i];
                        JR[index] = row_idx;
                        JC[index] = col_idx;
                        index++;
                    }
                }
            }
            //set up Ak
            base_col += n;
            for (int i = 0; i < 3; i++) {
                int row_idx = row;
                int col_idx = base_col + i;
                if (a_grid_left <= col_idx && base_col <= col_idx && col_idx < base_col + n && col_idx < a_grid_right) {
                    A[index] = a[i];
                    JR[index] = row_idx;
                    JC[index] = col_idx;
                    index++;
                }
            }
            base_col += n;
            //set up t1
            if (grid_row != n - 1) {
                for (int i = 0; i < 3; i++) {
                    int row_idx = row;
                    int col_idx = base_col + i;
                    if (t1_grid_left <= col_idx && base_col <= col_idx && col_idx < base_col + n &&
                        col_idx < t1_grid_right) {
                        A[index] = t[i];
                        JR[index] = row_idx;
                        JC[index] = col_idx;
                        index++;
                    }
                }
            }
        }
    }

    // initialize vector b
    FP num = 6.0 / (n + 1) / (n + 1);
    b[(n / 2 - 1) * n + (n / 2 - 1)] = num;
    b[(n / 2 - 1) * n + (n / 2)] = num;
    b[(n / 2) * n + (n / 2 - 1)] = num;
    b[(n / 2) * n + (n / 2)] = num;

}


FP vecdot(FP *vec1, FP *vec2, int N) {
    FP res = 0;
    for (int i = 0; i < N; i++) {
        res += vec1[i] * vec2[i];
    }
    return res;
}

void vecop(FP *vec1, FP *vec2, FP *res, FP coef, int N) {
    for (int i = 0; i < N; i++) {
        res[i] = vec1[i] + coef * vec2[i];
    }
}


void matmulvec(int Nz, FP *mat, int *row, int *col, FP *vec, FP *res, int N) {
    for (int i = 0; i < Nz; i++) {
        res[row[i]] += mat[i] * vec[col[i]];
    }
}


void conjugate_gradient(int Nz, FP *A, int *row, int *col, FP *b, int N) {
    int iter;
    double wcs = 0., wce = 0., cts = 0., cte = 0.;
    const FP THRESHOLD = sqrt(vecdot(b, b, N)) / 1000000.;
    FP rho, prev_rho;
    FP *x = (FP *) calloc(N, sizeof(FP));
    FP *r = (FP *) calloc(N, sizeof(FP));
    FP *p = (FP *) calloc(N, sizeof(FP));
    FP *q = (FP *) calloc(N, sizeof(FP));
    timing(&wcs, &cts);
    // r = b - A * x0
    matmulvec(Nz, A, row, col, x, r, N);
    vecop(b, r, r, -1., N);
    rho = vecdot(r, r, N);

    printf("Stopping tolerance: %.6e\n", THRESHOLD);
    printf("Initial residuals: %.6e\n", sqrt(rho));

    for (iter = 0; iter < MAX_ITERATION && sqrt(rho) >= THRESHOLD; iter++) {
        // r =rTr
        prev_rho = rho;
        rho = vecdot(r, r, N);
        //printf("current residuals: %f\n", sqrt(rho));
        if (iter == 0) {
            // p = r;
            for (int i = 0; i < N; i++) {
                p[i] = r[i];
            }
        } else {
            // beta = rho_p / rho_p-1
            FP beta = rho / prev_rho;
            //printf("beta: %f\n", beta);
            // p = r + beta * p;
            vecop(r, p, p, beta, N);
        }
        // q = Ap
        for (int j = 0; j < N; j++) q[j] = .0;
        matmulvec(Nz, A, row, col, p, q, N);
        //a = pTq
        FP alpha = vecdot(p, q, N);
        //printf("alpha: %f\n", alpha);
        // x = x + ap
        vecop(x, p, x, alpha, N);
        // r = r -aq
        vecop(r, q, r, -alpha, N);

    }
    timing(&wce, &cte);
    printf("#CG iterations: %d\n", iter);
    printf("Final residuals: %.6e\n", sqrt(rho));
    printf("Wall clock time: %.12f seconds\n", wce-wcs);
    printf("CPU time: %.12f seconds\n", cte-cts);
    free(x);
    free(r);
    free(p);
    free(q);

}


int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: ./serial n\n");
        exit(1);
    }
    const int n = atoi(argv[1]);
    const int N = n * n;
    const int Nz_in_grid = (n - 2) * 3 + 2 * 2; // number of non-zero elements in a grid
    const int Nz = (n - 2) * 3 * Nz_in_grid + 2 * 2 * Nz_in_grid; // number of non-zero elements
    FP *A, *b;
    int *row, *col;
    A = (FP *) calloc(Nz, sizeof(FP));
    row = (int *) calloc(Nz, sizeof(int));
    col = (int *) calloc(Nz, sizeof(int));
    b = (FP *) calloc(N, sizeof(FP));

    // initialize the matrix A using CSR scheme and and vector b
    initialize(A, row, col, b, n, N);
    // conduct conjugate gradient to compute pde
    conjugate_gradient(Nz, A, row, col, b, N);

    free(A);
    free(row);
    free(col);
    free(b);

    return 0;
}
