

/*

Tower of Hanoi prob

1LL represents the number 1 as a long long integer.
*/




#include <iostream>
using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxiliaryRod) {
    if (n == 1) {
        cout << "Move disk from " << fromRod << " to " << toRod << endl;
        return;
    }

    towerOfHanoi(n - 1, fromRod, auxiliaryRod, toRod);

    cout << "Move disk from " << fromRod << " to " << toRod << endl;

    towerOfHanoi(n - 1, auxiliaryRod, toRod, fromRod);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "Minimum moves required = " << (1LL << n) - 1 << endl;  

    // Function call
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
