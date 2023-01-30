#include "test.h"

int main(){
    int res;
    res = test_basic_functionality() || test_addition() || test_subtraction() || test_multiplication() || test_evalution();
    return 1;
}