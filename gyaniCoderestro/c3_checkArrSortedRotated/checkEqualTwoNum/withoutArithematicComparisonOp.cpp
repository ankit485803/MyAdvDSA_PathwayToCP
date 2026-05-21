
// 21st May 2026 (Thursday)

#include <iostream>
using namespace std;

void checkEqual(int a, int b) {

    if (a ^ b)
        cout << "Not Equal";

    else
        cout << "Equal";
}

int main() {

    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    checkEqual(a, b);

    return 0;
}