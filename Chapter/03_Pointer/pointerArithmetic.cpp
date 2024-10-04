
// concept of ARITHEMATIC POINTER

// Increment(++) and decrement  (--)
// add and subtraction number


#include <iostream>
#include <vector>
using namespace std;

// array pointer is also called constant pointer

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int a = 10;
    int* ptr = &a;

    cout << ptr << endl;
    // ptr ++;
    ptr --;
    cout << ptr << endl;  //+4

    cout << *arr << endl;  //1
    cout << *(arr+1) << endl;  //2 
    cout << *(arr+2) << endl;  //3
    cout << *(arr+3) << endl; //4

    //pointer2
    int* ptr2; //100
    int* ptr1 = ptr2 + 2;  //108

    cout << ptr1 << endl;
    cout << ptr2 << endl;
    cout << "Differenc of two = " << ptr1 - ptr2 << endl;   //2

    //conditional operator or RELATIONAL operator
    cout << (ptr1 < ptr2) << endl;  //no mean 0
    cout << (ptr1 > ptr2) << endl;  //yes matlab 1
    cout << (ptr1 == ptr2) << endl;  // no

    return 0;
}

