#include "fast_malloc.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define maxn 1000

int main(){
    float start = clock();
    float *v = NULL;
    for(int k = 0; k < maxn * maxn; k++){
        v = (float*)fastMalloc(maxn * sizeof(float));
        for(int i = 0; i < maxn; i++) {
            v[i] = i;
            if( i ){
                v[i] = v[i] * v[i - 1];
                v[i] = sqrt(v[i]);
            }
        }
        fastFree(v);
    }
    float end = clock();
    printf("%f\n", end - start);

    start = clock();
    for(int k = 0; k < maxn * maxn; k++){
        v = (float*) malloc(maxn * sizeof(float));
        for(int i = 0; i < maxn; i++) {
            v[i] = i;
            if( i ){
                v[i] = v[i] * v[i - 1];
                v[i] = sqrt(v[i]);
            }
        }
        free(v);
    }
    end = clock();
    printf("%f\n", end - start);


    return 0;
}
