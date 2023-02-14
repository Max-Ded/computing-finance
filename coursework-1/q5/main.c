#include <stdio.h>
#include <stdlib.h>
#include "two_digit.h"

int fraction_works_for_sleepy(struct two_digit num,struct two_digit den){
    // Inputs :
    //      two_digit obj : numerator
    //      two_digit obj : denominator
    // Outputs : Boolean value if we can simplify the value with sleepy's method
    // Note : We use cross products to check equality of fractions to avoid float rounding error
    int check_equality;
    if (num.tens==den.tens){
        check_equality = get_value(num) * den.units == get_value(den) * num.units;
        if (check_equality){
            return 1;
        }
    }
    if (num.tens==den.units){
        check_equality = get_value(num) * den.tens == get_value(den) * num.units;
        if (check_equality){
            return 1;
        }
    }
    if (num.units==den.units){
        check_equality = get_value(num) * den.tens == get_value(den) * num.tens;
        if (check_equality){
            return 1;
        }
    }
    if (num.units==den.tens){
        check_equality = get_value(num) * den.units == get_value(den) * num.tens;
        if (check_equality){
            return 1;
        }
    }
    return 0;
}

int run_tests(){
    int count=0;
    for (int num_unit=0;num_unit<10;num_unit++){
        for (int num_tens=1;num_tens<10;num_tens++){
            //Generate the digits for the numerator
            struct two_digit num={num_tens,num_unit};

            for (int den_unit = 0;den_unit<10;den_unit++){
                for (int den_tens = 1;den_tens<10;den_tens++){ 
                    //Generate the digits for the denominator

                    struct two_digit den = {den_tens,den_unit};
                    
                    if (fraction_works_for_sleepy(num,den)){
                        //If sleepy's method works => print the couple and add to the count

                        print_two_digit_div(num,den);
                        count++;
                    }
                }
            }
        } 
    }
    return count;
}
int main(){
    int count;
    count = run_tests();
    printf("Found %d successful fractions",count);
}