#include <iostream>
void swap1(int a, int b) {
    // int a and int b are new variable which value are given by the arguments passed to the function when called
    // here we swap the value of a and b (inside the function) and we do not change the value of the arguments passed to the function
    // since the function doesn't return anything, this will not affect the argument after the function is done executing
    int temp = a;
    a = b;
    b = temp;
    }
void swap2(int* a, int* b) {
    // a and b are pointer to an int (value retriedved with the * operator)
    // This code effectively swaps the value of a and b by value
    int temp = *a; // temp is an int with the same value as *a and a new address
    *a = *b; // the address stored in a will point the value pointed to by b
    *b = temp; // the address stored in b will point to the value temp (which is initialized to *a)
    std :: cout << "swap2: *a: " << *a << ", *b: " << *b << std :: endl;
}
void swap3(int& a, int& b) {
    // This code effectively swaps the value of a and b by refernce
    // variable a and b in the function scope can be considered to be the "true" a and b passed when the function is called
    int temp = a; // temp and a has the same value, different address
    a = b; // a becomes b (address and value)
    b = temp; // b takes the value of temp (which is the initial value of a)
    std :: cout << "swap3: a: " << a << ", b: " << b << std :: endl;
}
int main () {
    int a = 3;
    int b = 5;
    std :: cout << "main: a: " << a << ", b: " << b << std :: endl;
    swap1(a, b);
    std :: cout << "main: a: " << a << ", b: " << b << std :: endl;
    swap2 (&a, &b);
    std :: cout << "main: a: " << a << ", b: " << b << std :: endl;
    swap3(a, b);
    std :: cout << "main: a: " << a << ", b: " << b << std :: endl;
}
