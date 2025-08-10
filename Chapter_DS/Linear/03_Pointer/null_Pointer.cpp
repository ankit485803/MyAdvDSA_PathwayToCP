
#include <iostream>
#include <vector>
using namespace std;

// new chap: POINTER


int main() {
    int* ptr;    //without any value, yah random koi bhi value leke store jata hai called GARBAGE VALUE
    cout << ptr << endl;

    //pointer to pointer
    int** myPtr = NULL;
    cout << myPtr << endl;


    cout << *ptr << endl;  //null pointer ko dereference nahi karte

    return 0;
}









