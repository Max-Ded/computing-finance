#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>
#include "algo.h"


int main(int argc, char *args[]){
    char opti,print;
    int N,print_int;
    printf("Use the optimized version (y/n) : ");
    scanf(" %c", &opti);
    printf("Value of N : ");
    scanf(" %d", &N);
    printf("Print all primes numbers (y/n) : ");
    scanf(" %c", &print);
    print_int = print=='y' ? 1:0;
    if (opti=='y'){
        prime_opti(N,print_int);
    }
    else{
        prime_regular(N,print_int);
    }
}