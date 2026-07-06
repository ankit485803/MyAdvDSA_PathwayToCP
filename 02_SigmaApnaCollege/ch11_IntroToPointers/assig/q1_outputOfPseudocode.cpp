

/*

6th July 2026 (Monday)

Question 1 : What will be the output of the following code 
output of pseudocode 


Key Concepts
    & → Address-of operator
    * (in declaration) → Declares a pointer
    * (in expression) → Dereference operator (accesses the value stored at the pointed address)



*/


#include <iostream>
using namespace std;

int main() {
    int x;
    int *ptr;
    
    x = 7;
    ptr = &x;

    cout << *ptr << "\n";  //7

    return 0;
}