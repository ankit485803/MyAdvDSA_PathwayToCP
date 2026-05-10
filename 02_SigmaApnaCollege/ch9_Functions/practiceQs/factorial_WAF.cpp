

/*

WAF to print the factorial of a number n



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


int main() {
    int n = 5;

    cout << "factorial = " << factNumb(n) << endl;

    return 0;
}


git commit -m "feat(sigmaApnaCollege): solved practiceQs isEvenOdd, prodTwoNo, factorialNumb (ch9)"