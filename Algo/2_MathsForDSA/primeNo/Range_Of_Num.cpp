
#include <iostream>
using namespace std;

//Q.  when Range of numb is given, then find the total no of prime 




// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;  // 0 and 1 are not prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false; // num is divisible by i, so it's not prime
    }
    return true; // num is prime
}



// Function to count the number of primes in a given range
int totalPrime(int firstNo, int lastNo) {
    int count = 0;
    
    for (int num = firstNo; num <= lastNo; num++) {
        if (isPrime(num)) {
            count++;
        }
    }
    
    return count;
}



int main() {
    int firstNo = 2;
    int lastNo = 11;

    cout << "Total number of primes between " << firstNo << " and " << lastNo << " are: " 
         << totalPrime(firstNo, lastNo) << endl;

    return 0;
}


/*  TC

If you are given a large range and checking primes up to a large number lastNo, the time complexity of the algorithm becomes:

O(n ⋅ √m)

Where:

n is the size of the range, i.e., lastNo - firstNo + 1
m is the largest number in the range (i.e., lastNo).


Optimization -- using the Sieve of Eratosthenes algorithm,

*/