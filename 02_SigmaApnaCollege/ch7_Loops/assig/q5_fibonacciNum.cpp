


/*


Question 5 : For a positive N , WAP that prints the first N Fibonacci numbers.
(Assume N >=2)
Fibonacci series : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ….
This is a series where each number is a sum of previous 2 numbers in the series.
Eg :
1 =0+1,
2 =1+1,
3 =1+2,
5 =2+3,
8 =3+5&soon




*/



#include <iostream>
using namespace std;

void printFibonacci(int n) {
    int a = 0, b = 1;

    // first two numbers
    cout << a << " " << endl;
    cout << b << " " << endl;

    for(int i = 3; i <= n; i++) {
        int next = a + b;
        cout << next << " " << endl;

        a = b;
        b = next;
    }
}

int main() {
    int n = 10;

    cout << "First N Fibonacci numbers: " << endl;
    printFibonacci(n);

    return 0;
}