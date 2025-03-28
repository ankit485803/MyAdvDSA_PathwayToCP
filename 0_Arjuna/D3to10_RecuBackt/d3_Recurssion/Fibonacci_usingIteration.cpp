
#include <iostream>
using namespace std;

// Fibonacci using Iteration method - O(1)



#include <iostream>
using namespace std;

// void fibonacciLoop(int n) {  //using iteravtive -- O(n) = TC=SC
//     int a = 0, b = 1, next;
//     cout << "Fibonacci Series: " << a << " " << b << " ";
//     for (int i = 2; i < n; i++) {
//         next = a + b;
//         cout << next << " ";
//         a = b;
//         b = next;
//     }
//     cout << endl;
// }









int fibonacciRecursive(int n) {  //TC=O(2^n) Quadreatic
    if (n <= 1) return n;  // Base case
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}




int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    //fibonacciLoop(n);


    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;

    return 0;
}



// also Fibonacci Series using Dynamic Programming (Memoization)