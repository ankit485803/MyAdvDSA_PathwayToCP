

/*

29th Oct 2026 (Thursday)

Run-Time polymorphism: esmai compiler ko pahle se pata nahi hoga kya boga like compileTimePolymor
twoWays:
function overriding (RIDING) and Virtual Function

Q. diff b/w Function overLOADING and overRIDING
Ans: overloading mai compilerTime polymorphism hai, jismai ek hi function ke andar same class 
        whereas overRIDING - runTime polymorphism jismai Inheritance hota hai and parent-class alag se call karte hai


#Virtual Functions: is a member funct that you expect to be redefined in derived classes.



*/

#include <iostream>
#include <string>
using namespace std;


class Parent {
public:
    void show() {
        cout << "Parent class show.. \n";
    }

    //aab hm virtualFun banyenge 
    virtual void hello() {
        cout << "parent hello\n";
    }
};


class Child : public Parent {
public:
    void show() {
        cout << "child class show.. \n";
    }

    //aur hmko child mai virtual keywords likhne ki req nahi
    void hello() {
        cout << "child hello\n";
    }
};


int main() {
    Child child1;
    child1.show();  //yaha pe compiler confuse but runTime pe decide hoga child class ka hai to child show print

    Child child2;
    Parent *ptr;

    ptr = &child2;  //runTime binding ho raha 
    ptr->hello();  //virtual fun

    return 0;
}