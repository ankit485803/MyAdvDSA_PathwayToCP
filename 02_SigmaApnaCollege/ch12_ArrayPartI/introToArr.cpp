

/*

6th July 2026 (Monday)

Arrays
Linear collections of same type of elements that are stored together in contiguous memory spaces

7th July, Tuesday

CREATING of arr:
memory is statically alloacted at the compile time not dynamically which happens in vector



*/


git commit -m "feat(sigmaApnaCollege): restructure directory for newChap Array Part I (ch12)" 


#include <iostream>
using namespace std;

int main() {
    //creatingArr
    
    //case1: only give arr.size, then elem have garbage values
    int marks[50];
    
    cout << marks[0] << endl; 
    cout << marks[1] << endl; //garbage value
    cout << marks[2] << endl; 

    //case2: give some values, then rest idx have initialized with 0 not garbage values 
    int markStd[50] = {1, 2, 3};

    cout << markStd[0] << endl;  //1
    cout << markStd[1] << endl;  //2
    cout << markStd[2] << endl;   //3
    cout << markStd[15] << endl;  //0


    //case3: without define size
    int markStdIITP[] = {1, 2, 3};

    cout << markStdIITP[0] << endl;
    cout << markStdIITP[1] << endl;
    cout << markStdIITP[2] << endl;
    cout << markStdIITP[4] << endl;  //warning

    return 0;
}







// Case 1: Local array of size 50.
// Elements are uninitialized (indeterminate values).
int marks[50];

// Case 2: Partial initialization.
// Remaining elements are automatically initialized to 0.
int markStd[50] = {1, 2, 3};

// Case 3: Compiler automatically determines the array size (3).
int markStdIITP[] = {1, 2, 3};

// Undefined behavior: index 4 is outside the array bounds.
cout << markStdIITP[4] << endl;




git commit -m "feat(sigmaApnaCollege): started arr chap part I and covered Creating arr (ch12)" 