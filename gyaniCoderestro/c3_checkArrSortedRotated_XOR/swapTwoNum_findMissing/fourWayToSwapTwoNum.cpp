

// 13th Aug 2026 (Thursday - after health recovered July) and date of uploaded: 27th May 

#include <iostream>
using namespace std;

// 1. Using a temporary variable
void swapTemp(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Using arithmetic
void swapArithmetic(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

// 3. Using XOR
void swapXOR(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// 4. Using std::swap()
void swapUsingSwap(int &a, int &b) {
    swap(a, b);
}

int main() {
    int a = 3, b = 5;

    cout << "Original: a = " << a << ", b = " << b << endl;

    int x, y;

    // Way 1
    x = a; y = b;
    swapTemp(x, y);
    cout << "1. Temp:       a = " << x << ", b = " << y << endl;

    // Way 2
    x = a; y = b;
    swapArithmetic(x, y);
    cout << "2. Arithmetic: a = " << x << ", b = " << y << endl;

    // Way 3
    x = a; y = b;
    swapXOR(x, y);
    cout << "3. XOR:        a = " << x << ", b = " << y << endl;

    // Way 4
    x = a; y = b;
    swapUsingSwap(x, y);
    cout << "4. std::swap:  a = " << x << ", b = " << y << endl;

    return 0;
}