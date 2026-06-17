int *ptr = NULL;

/*

NULL pointer: we assign NULL value to pointer to show it doesn't point to location

int *ptr = NULL;

Dereferencing null ptr is not possible as it will result in error 

| Expression            | Meaning                                            |
| --------------------- | -------------------------------------------------- |
| `ptr`                 | Value stored in the pointer (address it points to) |
| `&ptr`                | Address of the pointer variable itself             |
| `int *ptr;`           | Uninitialized pointer (indeterminate value)        |
| `int *ptr = nullptr;` | Null pointer (points to nothing)                   |
| `*ptr`                | Dereference pointer (access pointed value)         |



*/


#include <iostream>
using namespace std;

int main() {
    int *ptr;
    cout << &ptr << "\n";   //garbage value print

    int *ptr2 = nullptr;
    int *ptr2 = NULL;

    cout << "Value of ptr: " << ptr << endl;     // 0 or 0x0
    cout << "Address of ptr: " << &ptr << endl;  // address where ptr is stored

    cout << *ptr2 << "\n";  //segmentation fault (core dumped) error because deference nullptr ko nahi kar sakte 
    cout << "bye";  //not will print

    return 0;
}


git commit -m "feat(sigmaApnaCollege): covered dereference and nullptr concepts (ch11)"