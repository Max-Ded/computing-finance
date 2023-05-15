#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "algo.h"

void prime_opti(int N,int print){
    clock_t start, end;
    start = clock();
    int *arr = calloc((int) N/2, sizeof *arr); // create array of size N+1 : arr[n]==1 means 2*n+1 is not a prime (marked) | stored in the heap and initialized to 0 since N might be large
    arr[0]=1; //1 is not a prime
    for (int k=1;k<sqrt(N)/2;k++){
        //we iterate multiples starting from 2*1+1=3 to sqrt(N/2)
        if (arr[k]==0){
            for (int n=1;(2*k+1)*(2*n+1)<N;n+=1){
                //mark all (2*k+1)*(2*n+1) numbers at index = (2*k+1)*(2*n+1)/2-1 = 2*k*n + (n+k)
                arr[2*k*n + (n+k)]=1;
            }
        }
    }
    int count=1;
    
    if (!print) {
        for (int i=0;i<(int)N/2;i++){
            if (arr[i]==0){
                count ++;
            }
        }
    }
    else{
        printf("Prime number : 2\n"); // Need to add 2 since we ignored it in the process
        for (int i=0;i<(int)N/2;i++){
        if (arr[i]==0){
            printf("Prime number : %d\n",2*i+1); // print all prime numbers
            count ++;
        }
        }
    }
    end = clock();
    printf("Found %d prime numbers between 1 and %d. (%0.01f seconds)",count,N,((double)end - start)/CLOCKS_PER_SEC);
    free(arr);
}

void prime_regular(int N,int print){
    clock_t start, end;
    start = clock();
    int *arr = calloc(N+1, sizeof *arr); // create array of size N+1 : arr[n]==1 means n is not a prime (marked) | stored in the heap and initialized to 0 since N might be large
    arr[1]=1; //1 is not a prime
    for (int k=2;k<=sqrt(N);k++){
        //we iterate multiples starting from 2 to sqrt(N)
        if (arr[k]==0){
            for (int n=2;n*k<=N;n++){
                // if k is not marked, mark all its multiples
                arr[n*k]=1;
            }
        }
    }
    int count=0;
    
    if (!print) {
        for (int i=1;i<N;i++){
            if (arr[i]==0){
                count ++;
            }
        }
    }
    else{
        for (int i=1;i<N;i++){
        if (arr[i]==0){
            printf("Prime number : %d\n",2*i+1); // print all prime numbers
            count ++;
        }
        }
    }
    end = clock();
    printf("Found %d prime numbers between 1 and %d. (%0.01f seconds)",count,N,((double)end - start)/CLOCKS_PER_SEC);
    free(arr);
}
