

// Question 4 : For a positive N , WAP that prints all the prime numbers from 2 to N.
// (Assume N >=2)


#include <iostream>
using namespace std;

bool isPrime(int numb) {
    if(numb < 2) {
        return false;
    }

    for(int i = 2; i < numb; i++) {   // FIX: i < numb
        if(numb % i == 0) {
            return false;            // FIX: return false
        }
    }

    return true;                    
}

void printAllPrime(int n) {
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {             // FIX: use function
            cout << i << " " << endl;
        }
    }
}

int main() {
    int n = 10;

    cout << "prime no from 2 to N: " << endl;
    printAllPrime(n);

    return 0;
}