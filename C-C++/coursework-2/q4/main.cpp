#include <iostream>
class MyClass {
    public:
    MyClass(int x) : x(x) {
        // : x(x) initializes the attribute x to the argument x
        // We print the initialization to the console
        std :: cout << "constructor called , x = " << this ->x << std :: endl;
    }
    MyClass(const MyClass& other) : x(other.x) {
        //  Passing another MyClass obj as argument by reference of the constructor => initialize the private attribute x with the attribute of the obj passed
        std :: cout << "copy constructor called , x = " << x << std :: endl;
    }
    MyClass& operator=(const MyClass& other) {
        // Used to re-affect an obj of MyClass to the argument, passed by reference
        // Passed by CONST reference so we don't have to copy the object in memory and don't modify it accidentaly
        std :: cout << "assignment operator called , x was " << x << " and became " << other.x << std :: endl;
        x = other.x;
        // return a pointer to the obj so we can have chain assigments
        return *this;
    }
    ~MyClass () {
        std :: cout << "destructor called , x = " << this ->x << std :: endl;
    }
    private:
        // MyClass has one private int attribute denoted by x
        int x;
    };
int main (){
    MyClass a{ 3 }; // a has attribute a.x = 3
    MyClass b{ 5 }; // b has attribute b.x = 5
    MyClass c{ a }; // c has attribute c.x = a.x = 3 and a different address in memory
    c = b; // c.x now has for value b.x 
    a = b; // a.x now has for value b.x (which has for value c.x) 

    // OUTPUT :
    // constructor called , x = 3
    // constructor called , x = 5
    // copy constructor called , x = 3
    // assignment operator called , x was 3 and became 5
    // assignment operator called , x was 3 and became 5
    // destructor called , x = 5
    // destructor called , x = 5
    // destructor called , x = 5
}
