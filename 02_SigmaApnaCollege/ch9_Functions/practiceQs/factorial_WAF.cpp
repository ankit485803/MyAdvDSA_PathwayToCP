

/*

WAF to print the factorial of a number n

0 ! = 1
1 ! = 1
2 ! = 1 * 2 = 2
3! = 1*2*3 = 6
4! = 1*2*3*4 = 24
5! = 1*2*3*4*5 = 120

*/

#include <iostream>
using namespace std;

int factorialN(int n) {  //wrongLogic 
    int fact = 1;
    //concepts: factorial(n) = n * (n-1) * (n-2) * .... till 1 

    for(int i=1; i <= n-1; i++) {
        fact = n * (n - i);  //multiply
    }

    return fact;
}


int factNumb(int n) {
    int fact = 1;

    // factorial(n) = 1 * 2 * 3 * ... * n
    for(int i=1; i <= n; i++) {
        fact = fact * i;
        //fact *= i;
    }

    return fact;
}


//byShardhaDi
int factorial(int n) {
    int fact = 1;
    for(int i=1; i<=n; i++) {
        fact = fact * i;
    }
    cout << "factorial (" << n << ") = " << fact << endl;
    return fact;
}


int main() {
    int n = 5;

    cout << "factorial = " << factNumb(n) << endl;

    factorial(0);
    factorial(1);
    factorial(2);
    factorial(3);
    factorial(4);
    factorial(5);

    return 0;
}


git commit -m "feat(sigmaApnaCollege): solved practiceQs isEvenOdd, prodTwoNo, factorialNumb (ch9)"