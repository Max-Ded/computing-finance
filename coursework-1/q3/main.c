#include <stdio.h>
#include <stdlib.h>


int main(){
    int read,highest,lowest,count;
    scanf("%d",&read);
    count = 1;
    highest = read;
    lowest = read;
    while (read>0){
        scanf("%d",&read);
        if (lowest>read){
            lowest = read;
        }
        if (highest<read){
            highest=read;
        }
        count ++;
    }
    printf("Number of values read : %d\nHighest value read : %d\nLowest value read : %d\nRange : %d",count,highest,lowest,highest-lowest);
    return 0;
}