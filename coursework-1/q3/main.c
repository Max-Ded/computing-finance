#include <stdio.h>
#include <stdlib.h>


int main(){
    int read,highest,lowest,count;
    scanf("%d",&read);
    count = 1;
    highest = read;
    lowest = read;
    while (read>0){
        // While the read number is not negative
        scanf("%d",&read); //overwrite the read value
        if (lowest>read){
            // overwrite lowest if we have inputed a lower number
            lowest = read;
        }
        if (highest<read){
            // overwrite highest if we have inputed a greater number
            highest=read;
        }
        count ++;
    }
    printf("Number of values read : %d\nHighest value read : %d\nLowest value read : %d\nRange : %d",count,highest,lowest,highest-lowest);
    return 0;
}