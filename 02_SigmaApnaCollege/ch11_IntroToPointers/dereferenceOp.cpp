

/*

17th June 2026 (Wednesday)

Deference Operator: Get the value of variable pointed by any pointer, 
*operator lets us directly access of modify the value of variable 




*/

#include <iostream>
using namespace std;

int main() {
    int a = 10;

    cout << &a << "\n";  //address
    cout << *(&a) << "\n";  //value print

    int b = 6;
    int *ptr = &a;
    cout << ptr << "\n";   //address
    cout << *ptr << "\n";  //values  dereference karte hai

    *ptr = 20;
    cout << b << "\n";   //value ko change bhi kar sakta hai ye dereference 

    return 0;
}