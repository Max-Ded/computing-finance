#include <iostream>
#include "vector.h"
using namespace std;

void test_construction(){
    /// @brief Test the basic functionnality of the Vector constructors
    
    cout << "___ Constructor test ___" <<endl << endl;
    cout << "Empty vector : ";
    Vector empty_vec = Vector();
    empty_vec.print();

    cout << "Zero-based vector : ";
    Vector zerobased_vec = Vector(10);
    zerobased_vec.print();

    cout << "Double filled vector : ";
    const double ct = 5.0;
    Vector constant_to_vec = Vector(10,ct);
    constant_to_vec.print();

    cout << "Array-initialized vector : ";
    double a[5] = {0,1,2,3,4};
    Vector array_to_vec = Vector(5,a);
    array_to_vec.print();

    Vector vec_copy = Vector(array_to_vec);
    vec_copy.print();
    cout <<endl << endl;

}

void test_operator(){
    /// @brief Test the overloading of the operator
    cout << "___ Operator test ___" <<endl << endl;

    cout << "A : ";
    double a[5] = {0,1,2,3,4};
    Vector vec_1 = Vector(5,a); //{1,2,3,4,5}
    vec_1.print();

    cout << "B : ";
    Vector vec_2 = Vector(5); // {0,0,0,0,0}
    vec_2.print();

    cout << "B = A"<<endl;
    vec_2 = vec_1;

    cout <<"B = ";
    vec_2.print();
    
    cout << endl << endl;
}

int main(){
    test_construction();
    test_operator();

    return 0;
}