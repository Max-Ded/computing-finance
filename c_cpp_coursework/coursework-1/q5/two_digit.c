#include "two_digit.h"
#include <stdio.h>


int get_value(struct two_digit x){
    // get the integer value of a struct two_digit obj
    int res;
    res = 10*x.tens + x.units;
    return res;
}
struct two_digit remove_tens(struct two_digit x){
    // Output a two_digit obj with the tens place value removed from the input
    struct two_digit obj = {0 , x.units};
    return obj;
}
struct two_digit remove_units(struct two_digit x){
    // Output a two_digit obj with the units place value removed from the input
    struct two_digit obj = {x.tens,0};
    return obj;
}

void print_two_digit_div(struct two_digit num,struct two_digit den){
    printf("%d/%d\n",get_value(num),get_value(den));
}