

/*

To build a calculator using switch, you need:
    Two numbers → a, b
    One operator → + , - , * , /
    Use switch to decide the operation.


*/



#include <iostream>
using namespace std;

int main() {
    int a, b;
    char op;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+':
            cout << "Result = " << a + b << endl;
            break;

        case '-':
            cout << "Result = " << a - b << endl;
            break;

        case '*':
            cout << "Result = " << a * b << endl;
            break;

        case '/':
            cout << "Result = " << a / b << endl;
            break;

        default:
            cout << "Invalid operator";
    }

    return 0;
}