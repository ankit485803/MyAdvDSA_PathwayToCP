#include <iostream>
#include <vector>
using namespace std;


/*

de-refence matlab vale at address

*/

int main() {
    int a = 10;
    int* ptr = &a;

    //pointer to pointer -- parent pointer
    int** parPtr = &ptr;

    cout << &ptr << endl;  //address
    cout << parPtr << endl;  
    cout << *(&a) << endl; //   DE-REFERECNCE operator

    return 0;
}









