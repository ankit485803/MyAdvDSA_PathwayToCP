

/*

12th May 2026 (Tuesday)

WAF to find the binomial coefficient of given n, r 
nCr = n! / r! * (n-r)!

thoughtProcess:
step1: create a fact helperFunct to calculate the factorial 
step2: now calculate numerator and denominator separately
step3: return numR / denoR  which is our final ans

*/


#include <iostream>
using namespace std;


int fact(int num) {  //helperFunct
    int f = 1;
    for(int i=1; i <= num; i++) {
        f = f * i;
    }
    return f;
}


int binomialCoeff(int n, int r) {
    //using formula nCr = n! / r! * (n-r)!
    int numR = fact(n);
    int denomR = fact(r) * fact(n - r);

    return numR / denomR;
}

int main() {
    int n = 5, r = 2;

    cout << "Binomial coefficient = " << binomialCoeff(n, r) << endl;

    return 0;
}


//shorter version tc=O(n), sc=O(1)
#include <iostream>
using namespace std;

int fact(int num) {
    int f = 1;
    for(int i = 1; i <= num; i++) {
        f *= i;
    }
    return f;
}

int binomialCoeff(int n, int r) {
    if(r > n || r < 0) {
        return 0;
    }
    return fact(n) / (fact(r) * fact(n - r));
}


int main() {
    int n = 5, r = 2;
    cout << binomialCoeff(n, r);
    return 0;
}


// feat(sigmaApnaCollege): completed thisChap today and impConcepts binomialCoefficient, primeNo variousMethods, functOverloading learnt (ch9)