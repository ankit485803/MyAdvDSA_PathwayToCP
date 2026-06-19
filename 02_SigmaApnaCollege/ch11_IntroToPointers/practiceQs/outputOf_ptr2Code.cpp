

/*

Question

What will ptr2 point to in the following code?

int x = 5, y = 10;

int *ptr1 = &x, *ptr2 = &y;

ptr2 = ptr1;


*/


#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 10;

    int *ptr1 = &x, *ptr2 = &y;

    cout << "Before assignment:\n";
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    ptr2 = ptr1;

    cout << "\nAfter assignment:\n";
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}


/*
Before assignment:
*ptr1 = 5
*ptr2 = 10

After assignment:
*ptr1 = 5
*ptr2 = 5

*/