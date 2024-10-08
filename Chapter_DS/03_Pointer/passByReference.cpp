
#include <iostream>
#include <vector>
using namespace std;

// pass by Ref -- two ways: POINTER + ALIAS (reference)


// using pointer
void changeA(int* a) { 
    *a = 20; // Dereferencing the pointer to change the original value
}

int main() {
    int a = 10;

    changeA(&a); // Pass the address of a

    cout << "Inside Main Function : " << a << endl;  // Outputs: 20
    return 0;
}





//using refernce or alias
void changeA(int& a) { 
    a = 20; // Directly modifying the referenced variable
}

int main() {
    int a = 10;

    changeA(a); // Pass by reference

    cout << "Inside Main Function : " << a << endl;  // Outputs: 20
    return 0;
}