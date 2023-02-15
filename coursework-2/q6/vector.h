class Vector{
    private:
        int nn; // size of array; upper index is nn - 1
        double* v;
    public:
        Vector (); // empty
        explicit Vector(int n); // zero -based array
        Vector(int n, double a); // initialize to constant value
        Vector(int n, const double* a); // initialize to array
        Vector(const Vector& rhs); // copy constructor
        Vector& operator=(const Vector& rhs); // assignment
        inline double& operator[](const int i); // i’th element
        inline const double& operator[](const int i) const;
        inline int size () const;
        void resize(int newn); // resize (contents not preserved )
        void assign(int newn , double a); // resize and assign a constant value
        ~Vector ();
        void print() const;
};


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


int Vector :: size() const{
    /// @brief return the int size of the vector
    /// @return Size of the vector
    return nn;
}