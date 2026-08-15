

/*

15th Aug 2026 (Saturday) Array Pointer, Pointer Arithmetic

Array Pointer acts like a CONSTANT pointer jisko hm change nahi kar sakte hai

Pointer Arithmetic:
1. Increment & Decrement operator
2. Addition & subtraction of constants
3. addition and subtraction of POINTERS
        ptr1 + ptr2  //invalid operations
        ptr1 - ptr2 //both should be same type

4. comparison operators (==, <, <=, >, >=)
==, !=       → compare whether addresses are same/different
<, >, <=, >= → compare positions within the same array


*/


#include <iostream>
using namespace std;


int main() {
    int a = 10;
    int *aptr = &a;

    cout << aptr << "\n";
    aptr++;
    cout << aptr << "\n";

    //Normal pointer
    int b = 5;
    int *ptr = &b;

    cout << ptr << "\n";  //1st
    ptr++;
    cout << ptr << "\n";
    ptr--;
    cout << ptr << "\n";  //3rd

    return 0;
}



//2. Addition and subtraction of constants
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << ptr << "\n";       // address of arr[0]
    ptr = ptr + 3;

    cout << ptr << "\n";       // address of arr[3]

    cout << *ptr << "\n";      // 40
    ptr = ptr - 2;
    cout << *ptr << "\n";      // 20

    return 0;
}



//3
int main() {
    int arr[] = {10, 20, 30, 40, 50};

    int *ptr1 = &arr[1];  // points to 20
    int *ptr2 = &arr[4];  // points to 50

    // ptr1 + ptr2;       // ❌ INVALID

    cout << ptr2 - ptr1 << endl;  // ✅ 3
    cout << ptr2 + ptr1 << endl;  // ✅ 3

    return 0;
}

/*output

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
sigmaApnaCollege.cpp: In function ‘int main()’:
sigmaApnaCollege.cpp:13:18: error: invalid operands of types ‘int*’ and ‘int*’ to binary ‘operator+’
   13 |     cout << ptr2 + ptr1 << endl;
      |             ~~~~ ^ ~~~~
      |             |      |
      |             int*   int*
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/



//4.
#include <iostream>
using namespace std;

int main() {

    int arr[] = {10, 20, 30, 40, 50};

    int *ptr1 = &arr[1];  // points to 20
    int *ptr2 = &arr[3];  // points to 40

    cout << (ptr1 == ptr2) << endl;  // 0 → false
    cout << (ptr1 < ptr2) << endl;   // 1 → true
    cout << (ptr1 <= ptr2) << endl;  // 1 → true
    cout << (ptr1 > ptr2) << endl;   // 0 → false
    cout << (ptr1 >= ptr2) << endl;  // 0 → false

    return 0;
}


/*
ptr1 == ptr2   → false ❌
ptr1 < ptr2    → true  ✅
ptr1 <= ptr2   → true  ✅
ptr1 > ptr2    → false ❌
ptr1 >= ptr2   → false ❌

*/


git commit -m "feat(sigmaApnaCollege): complete this chapter (ch12 arrPart I)" 