#include <iostream>
#include "vector.h"
using namespace std;

void test_construction(){
    /// @brief Test the basic functionnality of the Vector constructors
    
    cout << endl << "___ Constructor tests ___" <<endl << endl;
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

    cout << "Vector-initialized vector (copy of the last vector) : ";
    Vector vec_copy = Vector(array_to_vec);
    vec_copy.print();

}

void test_operator(){
    /// @brief Test the overloading of the operator
    cout << endl << "___ Operator tests ___" <<endl << endl;

    cout << "A : ";
    double a[5] = {0,1,2,3,4};
    Vector vec_1 = Vector(5,a); //{0,1,2,3,4}
    vec_1.print();

    cout << "B : ";
    Vector vec_2 = Vector(5); // {0,0,0,0,0}
    vec_2.print();

    cout << "B = A"<<endl;
    vec_2 = vec_1; 

    cout <<"B = ";
    vec_2.print();// {0,1,2,3,4}
    
    vec_2[4]=40; // {0,1,2,3,40}
    vec_2[3]=30; // {0,1,2,30,40}
    cout <<"B[4] = 40" << endl;
    cout <<"B[3] = 30" << endl;
    cout <<"B = "; 
    vec_2.print();  // {0,1,2,3,40}


    const Vector vec_3 = Vector(5,6.);  // {6.,6.,6.,6.,6.}
    cout <<"const C = ";
    vec_3.print(); // {6.,6.,6.,6.,6.}
    cout << "Reading : C[0] = " << vec_3[0] <<endl; // C[0] = 6.

    vec_1 = vec_3;
    cout << "A = C" << endl << "A = ";
    vec_1.print(); // {6.,6.,6.,6.,6.}
    vec_1[0] = 4; // {4.,6.,6.,6.,6.}
    cout <<"Setting A[0] = 4" << endl;
    cout << "A = ";
    vec_1.print(); // {4.,6.,6.,6.,6.}
}

void test_miscellianous(){
    /// @brief Additionnal tests to ensure reassigning and resizing work
    cout << endl << "___ Other tests ___" <<endl << endl;

    double a[5] = {0,1,2,3,4};
    Vector vec_1 = Vector(5,a); //{1,2,3,4,5}
    cout << "A = ";
    vec_1.print();
    cout << "Resizing A to 6 elements" <<endl;
    vec_1.resize(6);
    cout << "A = ";
    vec_1.print();

    cout << "Reassigning A to 3 elements filled with 3." <<endl;
    vec_1.assign(3,3.);
    cout << "A = ";
    vec_1.print();
}
int main(){
    test_construction();
    test_operator();
    test_miscellianous();
    return 0;
}