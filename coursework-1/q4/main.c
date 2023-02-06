#include <stdio.h>
#include <stdlib.h>

void print_pointer_char(char *ptr){
    if (ptr!=NULL){
        printf("%c",*ptr);   
    }
}
void read_remaining(char *before,int remaining){
    if (remaining>0){
        char c;
        scanf("%c",&c);
        read_remaining(&c,remaining-1);
        print_pointer_char(before);
    }
    else{
        print_pointer_char(before);
    }
}

int main(int argc,char *args){
    char  *ptr = NULL;
    int N=200;
    read_remaining(ptr,N);
    return 0;
}
