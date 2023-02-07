#include <stdio.h>
#include <stdlib.h>

void print_pointer_char(char *ptr){
    // prints to the console if the pointer is not NULL
    if (ptr!=NULL){
        printf("%c",*ptr);   
    }
}
void read_remaining(char *before,int remaining){
    // recursive, will run until remaining is equal to 0
    // create an implicit stack within memory as the recursive functions arguments
    if (remaining>0){
        char c;
        scanf("%c",&c); // read a new char from console
        read_remaining(&c,remaining-1); // call itself with the char just read and one less char to read from the total
        print_pointer_char(before); // outputs to the console its argument
    }
    else{
        print_pointer_char(before); // final state when stopping condition is reached => print the argument
    }
}

int main(int argc,char *args){
    char  *ptr = NULL;
    int N=200; // can be set to whatever length we wish to reverse
    read_remaining(ptr,N);
    return 0;
}
