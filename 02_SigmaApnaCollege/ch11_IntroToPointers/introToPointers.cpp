

/*

22nd May 2026 (Friday)

28th May t0 12th June 2026 endSem6 campusImmersion

15th June 2026 (Monday)


memory concepts 


*/



git commit -m "feat(sigmaApnaCollege): started newChap IntroToPointer from today and covered concepts of memory, address of pointers (ch11)"


/*

pointer: is a special variable that stores address of another variable 

int *ptr = &a;
float *ptr = &b;
char *ptr = &c;
int ** ptr2 = &ptr;

*/


#include <iostream>
using namespace std;


int main() {
    int a = 65;
    int *ptr = &a;
    //int * ptr = &a;
    //int* ptr = &a;

    float pi = 3.14;
    float *ptr2 = &pi;

    cout << &pi << "=" << ptr2 << "\n";
    cout << &a << " = " << ptr << "\n";

    cout << sizeof(ptr) << "\n";
    cout << sizeof(ptr2) << "\n";

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int a = 65;
    int *ptr = &a;

    cout << "Value of a: " << a << "\n";
    cout << "Address of a: " << &a << "\n";
    cout << "Value stored in ptr: " << ptr << "\n";
    cout << "Value pointed to by ptr: " << *ptr << "\n";

    return 0;
}



/* output
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
Value of a: 65
Address of a: 0x7fff4ed69fcc
Value stored in ptr: 0x7fff4ed69fcc
Value pointed to by ptr: 65

*/


// 1. Integer Pointer
    int a = 10;
    int *ptr1 = &a;

    // 2. Float Pointer
    float b = 3.14f;
    float *ptr2 = &b;

    // 3. Character Pointer
    char c = 'A';
    char *ptr3 = &c;

    // 4. Double Pointer (Pointer to Pointer)
    int **ptr4 = &ptr1;

git commit -m "feat(sigmaApnaCollege): types of pointers: int, float, char, double (ch11)"