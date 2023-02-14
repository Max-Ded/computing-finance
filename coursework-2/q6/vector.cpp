#include "vector.h"
#include <iostream>

Vector :: Vector(int n){
    /// @brief Create a vector of size n filled with 0.
    /// @param n  : int size of the vector
    nn = n;
    v = new double[n];
    for (int i =0;i<n;i++){
        v[i]=0.;
    }
}

Vector :: Vector(){
    /// @brief Create an empty vector with content NULL
    nn =0;
    v = nullptr; 
}

Vector :: Vector(int n, double a){
    /// @brief Create a vector with size n filled with the value (double) a
    /// @param n : int size of the vector
    /// @param a : double value to fill the vector
    nn = n;
    v = new double[n]; // create the array pointer in the heap
    for (int i=0;i<n;i++){
        v[i] = a;
    }
}

Vector :: Vector(int n, const double* a){
    /// @brief Create a vector from an array
    /// @param n : int size of the vector
    /// @param a : array of size n to copy the value from
    nn = n;
    v = new double[n];
    for (int i=0;i<n;i++){
        v[i] = a[i]; // create the array pointer in the heap
    }
}

Vector :: Vector(const Vector& rhs){
    /// @brief Create a new vector from a vector reference (const so the arg is not modified)
    /// @param rhs vector to copy the data from
    nn = rhs.nn;
    v = new double[nn];
    for (int i=0;i<nn;i++){
        v[i] = rhs[i];
    }
}

Vector& Vector :: operator=(const Vector& rhs){
    /// @brief Overloading the "=" operator
    /// @param rhs vector to compare
    /// @return return a pointer to the (modified) vector
    nn = rhs.nn;
    delete[] v; // delete the original vector content to avoid memory leak
    v = new double[nn]; // initialize the new vector
    for (int i=0;i<nn;i++){
        v[i] = rhs[i]; // fill the new vector with the content of the source
    }
    return *this;
}

inline double& Vector :: operator[](const int i){
    /// @brief Access the i'th element from the vector
    /// @param i : int index of element in the vector
    /// @return Reference to the i'th element
    return v[i];
}

inline const double& Vector :: operator[](const int i) const{
    /// @brief Overload the [] operator without modifying its content (to access READ-ONLY the content of the vector)
    /// @param i i'th element of the vector
    /// @return the read-only i'th element of the vector
    return v[i];
}

void Vector :: resize(int newn){
    /// @brief Resize the vector, deletes its old content
    /// @param newn new size of the vector
    nn = newn;
    delete[] v;
    v = new double[nn];
}


int Vector :: size() const{
    /// @brief return the int size of the vector
    /// @return Size of the vector
    return nn;
}

void Vector :: assign(int newn , double a){
    /// @brief resize and assign a constant value
    /// @param newn : int new size of the vector
    /// @param a : double to fill the content of the vector 
    nn = newn;
    delete[] v;
    v = new double[nn];
    for (int i=0;i<nn;i++){
        v[i] = a;
    }
}

void Vector :: print(){
    /// @brief Print the content of the vector and its size
    std :: cout << size() << " element(s) ";
    if (nn>0){
        // print the content of the vector if it's not empty
        std :: cout << "{ ";
        for (int i=0;i<size();i++){
            std :: cout << v[i] << " ";
        }
        std :: cout << "}";
    }
    std :: cout << std :: endl;
}

Vector :: ~ Vector(){
    /// @brief destructor for the vector class, free the space in the heap
    delete[] v;
}
