#include <stdio.h>
#include <stdlib.h>
/*
int main(){
    char c1,c2;
    scanf("%c %c", &c1,&c2);
    printf("%c %c",c2,c1);
    return 0;
}
*/

int main(int argc, char* args[]){
    for (int i=argc-1;i>0;i--){
        printf("%c ",*args[i]);
    }
    return 0;
}