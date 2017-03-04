#include "timing.h"

const int N = 1000000000;

double func(double x){
    return 1.0 / (1.0 + x * x);
}

double approximation(){
    double wcs = 0, wce = 0, ct = 0, rt;
    double res = 0.0;
    double x0 = 1 / (2 * (double)N);
    timing(&wcs, &ct);
    for(int i=0; i<N; i++ ){
        res += func(x0) / (double)N;
        x0 += 1 / (double)N;
    }
    timing(&wce, &ct);
    rt = wce - wcs;
    printf("running time: %f\n", rt);
    return res * 4;
}


int main(){
    printf("pie: %f\n", approximation());
    return 0;
}
