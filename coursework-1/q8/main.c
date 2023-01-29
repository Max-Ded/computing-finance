#include "test.h"

int main(){
    int res;
    //res = test_1() || test_2() || test_3() || test_4() || test_5();
    res = test_basic_functionality() || test_addition() || test_subtraction() || test_multiplication() || test_evalution();
    return res;
}