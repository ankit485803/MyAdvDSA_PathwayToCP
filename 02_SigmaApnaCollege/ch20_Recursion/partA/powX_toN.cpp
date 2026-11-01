
git commit -m "feat(sigmaApnaCollege): covert partA intro, sum of N naturalNum, isSorted, fibonacci, first & lastOccur, pow of x^n (ch20_Recursion)" 
/*

WAF to find the pow of X^n 

approach1: basic iterative tc=O(n), sc=O(1)
approach2: Bit Manipulation  tc=O(n), sc=O(1)
approach3: Recursion  tc=O(n), sc=O(1)

approach4: using logN time jo binarySearch mai hota hai

 x^n/2
*/


#include <iostream>
using namespace std;


int pow(int x, int n) {  //tc=O(logN)
    //basecase
    if(n == 0) {
        return 1;
    }

   
    //kam hm kar rahe h
    int halfPow = pow(x, n/2);
    int halfPowSquare = halfPow * halfPow;

    if(n % 2 != 0) {
        //odd
        return x * halfPowSquare;
    }
    return halfPowSquare;  //even ke case mai
}


int main() {
    cout << pow(2, 5) << endl;

    return 0;
}




#include <iostream>
using namespace std;

// Approach 1: Basic Iterative
// TC = O(n), SC = O(1)
int pow1(int x, int n) {
    int ans = 1;

    for(int i = 0; i < n; i++) {
        ans = ans * x;
    }

    return ans;
}


// Approach 2: Bit Manipulation
// TC = O(log n), SC = O(1)
int pow2(int x, int n) {
    int ans = 1;

    while(n > 0) {
        if(n & 1) {
            ans = ans * x;
        }

        x = x * x;
        n = n >> 1;
    }

    return ans;
}


// Approach 3: Basic Recursion
// TC = O(n), SC = O(n)
int pow3(int x, int n) {
    // Base case
    if(n == 0) {
        return 1;
    }

    return x * pow3(x, n - 1);
}


// Approach 4: Binary Exponentiation
// TC = O(log n), SC = O(log n)
int pow4(int x, int n) {
    // Base case
    if(n == 0) {
        return 1;
    }

    int halfPow = pow4(x, n / 2);
    int halfPowSquare = halfPow * halfPow;

    if(n % 2 != 0) {
        return x * halfPowSquare;
    }

    return halfPowSquare;
}


int main() {
    int x = 2;
    int n = 5;

    cout << "Approach 1: " << pow1(x, n) << endl;
    cout << "Approach 2: " << pow2(x, n) << endl;
    cout << "Approach 3: " << pow3(x, n) << endl;
    cout << "Approach 4: " << pow4(x, n) << endl;

    return 0;
}
