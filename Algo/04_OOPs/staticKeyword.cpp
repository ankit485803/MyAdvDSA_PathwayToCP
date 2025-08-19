

#include <istream>  // should be <iostream>, not <istream>


#include <iostream>
using namespace std;
#include <string>



/*

19th Aug 2025 (Tuesday - Sem5 starts) Static keywords - freq used

Two ways to uses:
        * Static ko VARIABLE ke sath:  variable declared as static in a funct are created & initialized once for the lifetime of 
        the prog
        static variable in a class are created & initalized once. they are shared by all the obj of class



        * Static OBJECT: 


*/



void Fun() {
    // int x = 0;

    static int x = 0;  //int statement - 1 run hi hoga
    cout << "X : " << x << endl;
    x++;
    
};


class A {
public:
    int x;

    void incx() {
        x = x + 1;
    }
};





int main() {

//    Fun();
//    Fun();
//    Fun();

   A obj;

    obj.x = 0;
    cout << obj.x << endl;
    obj.incx();

    cout << obj.x << endl;

    
    A obj1;
    A obj2;
    obj1.x = 100;
    obj2.x = 200;
    cout << obj1.x << endl;
    cout << obj2.x << endl;


    return 0;
};