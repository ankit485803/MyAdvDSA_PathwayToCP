

/*

Arithmatic: Binary, Unary 

Binary: esko two operands lagta hai
addition, subtraction, multiplication, division, modulo 

UNARY: increment, decrement

PRE-incremnt(++a) UNARY: means update and then use
POST-increment(a++) UNARY: means use and then update 

jaise Airtel Jio ka sim card hota hai prepaid recharge plan and postpaid for international plan

*/


#include <iostream>
using namespace std;

int main() {

    //Arithematic operations - BINARY
    int a = 5;
    int b = 3;

    cout << "+ " << (a + b) << endl;  //8
    cout << "- " << (a - b) << endl;  //2
    cout << "* " << (a * b) << endl;  //15
    cout << "/ " << (a / b) << endl;  //1
    cout << "% " << (a % b) << endl;  // remainder print karna MODULO op: 2

    int c = 3;
    c = c + 1;  //a++   UNIARY 
    c = c - 1;  //a--  Decrement UNIARY

    return 0;
}