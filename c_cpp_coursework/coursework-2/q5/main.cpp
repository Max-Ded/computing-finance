#include <iostream>
class MyClass {
    public:
        MyClass(int x); // Constructor function
        const int* get () const; // the final const means the function promises not to modify the object which it is called from
        int* get (); // returns a pointer to an integer (the value pointed to can be changed with this pointer)
    private:
        int x;
};

MyClass :: MyClass(int x) : x(x) {} // Implement the constructor of MyClass taking into arugment an int x and setting obj.x to x

const int* MyClass :: get () const {
    std :: cout << "I am const , x = " << x << std :: endl;
    return &x;
}

int* MyClass :: get () {
    std :: cout << "I am not const , x = " << x << std :: endl;
    return &x;
}

int main (){
    const MyClass a{ 1 }; // a is constant, it cannot be modified
    MyClass b{ 2 }; 
    MyClass* c = new MyClass{ 3 };  // c is a pointer to a MyClass obj on the heap
    const MyClass* d = new MyClass{ 4 };  // d is constant pointer , it cannot be modified
    const MyClass& e{ a }; // e is a const reference to a MyClass obj, it cannot be used to modify the object
    MyClass& f{ b }; // is a reference to a MyClass obj intialized  with the same param as a

    a.get (); // a is a const => prints "i am a const ..."
    b.get (); // b is not a const => prints "i am NOT a const ..."
    c->get (); // c is not a const => prints "i am NOT a const ..."
    d->get (); // d is a const => prints "i am a const ..."
    e.get (); // e is a const => prints "i am a const ..."
    f.get (); // f is not a const => prints "i am NOT a const ..."

    // Free the HEAP when we declared obj with the new keyword
    delete d;
    delete c;
}
