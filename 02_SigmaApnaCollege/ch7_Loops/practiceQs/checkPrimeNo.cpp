


/*


22nd March 2026 (Sunday)
1 is not a prime number, nor is it a composite number.

Qs. check if a numb is prime or not



“If a number has a factor greater than √n, its pair must already be smaller than √n.”




*/


#include <iostream>
using namespace std;
#include <vector>

bool isPrime(int numb) {
    //step1: final all possibleFactors
    vector<int> factors;

    for(int i=1; i<=numb; i++) {
        if(numb % i == 0) {
            factors.push_back(i);
        }
    }

    //step2: mainLogic for prime
    bool isPrime = false;
    int j = 0;
    while(j < factors.size()) {
        if(factors[j] == 1 && factors[j] == numb) {   //sirf ONE, and itself factor ho 
            isPrime = true;
            j++;
        }
    }

    return isPrime;
}




int main() {
    int numb;
    cout << "Enter numb: ";
    cin >> numb;

    cout << numb << " is " << isPrime(numb) << endl;
    
}


/*
❌ Issues in your code
1. Infinite loop
int j = 0;
while(j < factors.size()) {
    if(factors[j] == 1 && factors[j] == numb) {
        isPrime = true;
    }
}

👉 Problem:
You never increment j, so while loop runs forever.



2. Wrong logic for prime check
if(factors[j] == 1 && factors[j] == numb)

👉 This condition is impossible:
A number cannot be both 1 AND numb at the same time





*/


bool isPrime(int numb) {
    if(numb <= 1) return false;
    if(numb == 2) return true;
    if(numb % 2 == 0) return false;

    for(int i = 3; i * i <= numb; i += 2) {
        if(numb % i == 0) return false;
    }
    return true;
}




#include <iostream>
using namespace std;
#include <vector>

bool isPrime(int numb) {
    if(numb <= 1) return false;  //edgeCase

    //bruteForce approach
    vector<int> factors;

    for(int i=1; i<=numb; i++) {  //tc=O(N) jo sufficent nahi hai esliye apko Ankit O(n ^ 0.5) sqaureRoot mai
        if(numb % i == 0) {
            factors.push_back(i);
        }
    }

    return (factors.size() == 2);   //onlyTwoFactors
}




int main() {
    int numb;
    cout << "Enter numb: ";
    cin >> numb;

    if(isPrime(numb) ) {
        cout << numb << " is Prime" << endl;
    } else {
        cout << numb << " is not prime" << endl;
    }
    
}




/*
🧠 Why i * i <= numb ?

Instead of writing:

i <= sqrt(numb)

we write:

i * i <= numb

👉 Same meaning, but:

avoids using sqrt() (faster)
stays in integer math


If you want next level, I can show:

🔥 Prime numbers in a range (very common question)
🚀 Sieve of Eratosthenes (used in big problems)
💡 Competitive programming tricks

*/


#include <iostream>
using namespace std;

bool isPrime(int numb) {
    if(numb <= 1) return false;

    for(int i = 2; i * i <= numb; i++) {
        if(numb % i == 0) {
            return false;  // found a factor → not prime
        }
    }
    return true;  // no factors found
}

int main() {
    int numb;
    cout << "Enter numb: ";
    cin >> numb;

    if(isPrime(numb)) {
        cout << numb << " is Prime" << endl;
    } else {
        cout << numb << " is not prime" << endl;
    }
}