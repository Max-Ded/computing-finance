#include <iostream>
int main () {
    // i has value 5
    // the ++ operator increase the value of the variable by 1
    // ++ has prefix and suffix format, which changes the order of evalutation
    // ++a (prefix) the increment will be done before rest of the expression
    // a++ (suffix) the increment will be done after rest of the expression
    int i = 5;
    int j = i++; // increment done after the evaluation of i (which is 5 in this case) => j=5 , i=6
    int k = ++i; // increment done before the evalution of i. So i goes to 6+1=7 and k takes the value of i which is 7 => i=7, k=7
    std :: cout << "i: " << i << std :: endl; // i : 7
    std :: cout << "j: " << j << std :: endl; // j : 5
    std :: cout << "k: " << k << std :: endl; // k : 6
}