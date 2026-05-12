
condition ? expression1 : expression2;

/*
12th May 2026 (Tuesday)

WAF to print if a numb is prime or not
condition of prime: fact(num) is 1 or itself

The ternary operator (? :) in C++ is a shorthand for an if-else statement. 
It is the only operator in C++ that takes three operands, which is why it's called "ternary".


same thing in ch7 loops we've read 02_SigmaApnaCollege\ch7_Loops\practiceQs\checkPrimeNo.cpp

*/


#include <iostream>
using namespace std;


//method1: count each fact if count == 2 return true or else false, tc=O(N), sc=O(1)
bool isPrime(int num) {

    if(num <= 1) {
        return false;
    }

    int count = 0;

    for(int i = 1; i <= num; i++) {  //iterateEachNum
        if(num % i == 0) {
            count++;
        }
    }

    return (count == 2) ? true : false;  //usingTernaryOp
}

int main() {
    int num = 5;

    if(isPrime(num)) {
        cout << "Prime No" << "\n";
    } else {
        cout << "not prime" << "\n";
    }

    return 0;
}



/*output of currCode
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
sigmaApnaCollege.cpp: In function ‘bool isPrime(int)’:
sigmaApnaCollege.cpp:14:39: error: expected ‘;’ before ‘}’ token
   14 |     return (count == 2) ? true : false  //usingTernaryOp
      |                                       ^
      |                                       ;
   15 | }
      | ~
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

ieve of Eratosthenes is different:

It finds all prime numbers up to N
Time complexity approximately:  O(nloglogn)

*/


//method2: optimized not iterate all 1 to i, reduce to sqrt(n) by observations, a part of - Sieve of Eratosthenes, tc=O(logN) or sqrt(n), sc=O(1)
bool isEvenSieve(int num) {

    if(num <= 1) return false;

    for(int i = 1; i*i <= num; i++) {
        if(num % i == 0) {
            return false;  //moreThanTwofactors
        }
    }
    return true; 
}


int main() {
    int num = 5;

    cout << (isEvenSieve(num) ? "Prime No" : "not prime") << endl; 
}


#include <iostream>
using namespace std;
// Optimized Prime Check
// TC = O(√n)
// SC = O(1)

bool isPrime(int num) {
    if(num <= 1) {
        return false;
    }

    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false; // more than 2 factors
        }
    }
    return true;
}

int main() {
    int num = 5;
    cout << (isPrime(num) ? "Prime No" : "Not Prime") << endl;
    return 0;
}