


#include <iostream>
using namespace std;
#include <vector>


/*

RunTimePolym -- dynamic nature

Function overriding: Parent & child both contain the same funct with diff implementaton.
parent class funct is said to be overridden.




*/



class Parent {
public:
    void getInfo() {
        cout << "Parent class \n";
    }


};




class Child : public Parent {
public:    
    void getInfo() {
        cout << "Child class \n";

    }
};




int main() {

    Parent p1;
    p1.getInfo();

    
    Child c1;
    c1.getInfo();


    return 0;
}