

#include <iostream>
using namespace std;
#include <vector>


/*

15th Aug 2025 (Friday - Happy Indep Day) 

Polymorphism is the ability of objects to take on diff forms or behave in diff ways depending on the context  in which 
they are used

note: direct defination of polymorism ko interview mai yad karke jana ha ankit bhai 

eg. Constructor overloading 


two Types:
* Compile Time Polymorphism-- eg. constructor overloading, function overloadng, Operator overloading

* Run time polymorphism



*/


class Student {
public:
    //make two constructor jo constructor overloading hoga
    string name;

    Student() {
        cout << " non-parameterized constructor: \n";

    }

    Student(string name) {
        this->name = name;
        cout << "parameterized \n";
    }
};




int main() {

    //Student s1;
    Student s1("Ankit Kumar Happy IndepDay and ICRB exam date out bhai");



    return 0;
}