#include <iostream>
using namespace std;

// Function to return max of two numbers
int maxTwo(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int a, b;

    cout << "Enter int a value: ";
    cin >> a;

    cout << "Enter int b value: ";
    cin >> b;

    cout << "Max of two numbers is: " << maxTwo(a, b) << endl;

    return 0;
}






int maxTwo(int a, int b) {
    return (a > b) ? a : b;
}