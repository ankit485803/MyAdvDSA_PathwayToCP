

/*

Predict Output ki order mai constructor and deconstructor call hota hai


*/


#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "Constructor A" << endl;
    }

    ~A() {
        cout << "Destructor A" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "Constructor B" << endl;
    }

    ~B() {
        cout << "Destructor B" << endl;
    }
};

int main() {
    B obj;
}