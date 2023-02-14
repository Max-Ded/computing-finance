#include <stdio.h>

int sum(int arr[]){
    int s;
    int len = sizeof(arr) / sizeof(int);
    for (int i=0;i<len;i++){
        s+=arr[i];
    }
    return s;
}

int main(){
    int arr[2] = {1,2};
    int s;
    s = sum(arr);
    printf("%d",s);
    return 0;
}