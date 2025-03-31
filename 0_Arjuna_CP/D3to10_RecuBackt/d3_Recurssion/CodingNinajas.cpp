

/*  src--https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

28th March (Friday) Day9

*/








#include <bits/stdc++.h>
using namespace std;

// Function to print the Fibonacci series up to n terms
void FiboSer(int n) {
    if (n <= 0) return;
    
    int a = 1, b = 1, next;

    cout << a << " ";  // First Fibonacci number
    if (n > 1) cout << b << " ";  // Second Fibonacci number

    for (int i = 3; i <= n; i++) {  // Loop starts from 3rd term
        next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;  // Take user input

    FiboSer(n);  // Call function to print Fibonacci series

    return 0;
}
