
#include <iostream>
#include <vector>
using namespace std;

// new chap: POINTER


int main() {
    float price = 100.25f;  // in hexdecimal numb form
    float* ptr = &price;

    cout << ptr << endl;
    cout << &price << endl;
    
    return 0;
}


 