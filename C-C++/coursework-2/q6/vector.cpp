#include "vector.h"
#include <iostream>
#include <sstream>

Vector :: Vector(){
    /// @brief Create an empty vector with content NULL
    nn =0;
    v = nullptr; 
}


Vector :: Vector(int n){
    /// @brief Create a vector of size n filled with 0.
    /// @param n  : int size of the vector
    if (n<0){
        //Raises an error if the size is negative
        throw std::invalid_argument(std::string("Vector size should be positive, size given was : " + std::to_string(n)));
    }
    nn = n;
    v = new double[n];
    for (int i =0;i<n;i++){
        v[i]=0.;
    }
}


Vector :: Vector(int n, double a){
    /// @brief Create a vector with size n filled with the value (double) a
    /// @param n : int size of the vector
    /// @param a : double value to fill the vector
    if (n<0){
        //Raises an error if the size is negative
        throw std::invalid_argument(std::string("Vector size should be positive, size given was : " + std::to_string(n)));
    }
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
    if (n<0){
        //Raises an error if the size is negative
        throw std::invalid_argument(std::string("Vector size should be positive, size given was : " + std::to_string(n)));
    }
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

void Vector :: resize(int newn){
    /// @brief Resize the vector, deletes its old content and fills the new one with zero
    /// @param newn new size of the vector
    if (newn<0){
        //Raises an error if the size is negative
        throw std::invalid_argument(std::string("Vector size should be positive, size given was : " + std::to_string(newn)));
    }
    nn = newn;
    delete[] v;
    v = new double[nn];
    for (int i =0; i<newn;i++){
        v[i]=0.;
    }
}


void Vector :: assign(int newn , double a){
    /// @brief resize and assign a constant value
    /// @param newn : int new size of the vector
    /// @param a : double to fill the content of the vector 
    if (newn<0){
        //Raises an error if the size is negative
        throw std::invalid_argument(std::string("Vector size should be positive, size given was : " + std::to_string(newn)));
    }
    nn = newn;
    delete[] v;
    v = new double[nn];
    for (int i=0;i<nn;i++){
        v[i] = a;
    }
}

void Vector :: print() const{
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
