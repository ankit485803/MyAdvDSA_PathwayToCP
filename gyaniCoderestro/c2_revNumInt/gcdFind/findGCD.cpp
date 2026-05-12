

/*

8th May 2026 (Friday)

Find gcd for two numbers in cpp 
Tc, sc

Method 1: simple brute force - Town Hall from minimum of two numbers to 1 and first number that you have both number is gcd 

Method2: prime factors 

Method 3: Euclid's algo
Idea:
gcd(a,b)=gcd(b,a%b)
Repeat until remainder becomes 0.


*/

#include <iostream>
using namespace std;

// Idea: Start from min(a, b) and move till 1. The first number dividing both is the GCD.

int gcdBrute(int a, int b) {  //tc=O(min(a, b)), sc=O(1)
    int mini = min(a, b);

    for (int i = mini; i >= 1; i--) {

        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }

    return 1;
}


int main() {
    int a = 24, b = 36;
    cout << "GCD = " << gcdBrute(a, b);
    return 0;
}



//Method 2: Prime Factorization, tc=O(min(a, b)), sc=O(1)
int gcdPrimeFactor(int a, int b) {
    int gcd = 1;

    for (int i = 2; i <= min(a, b); i++) {
        while (a % i == 0 && b % i == 0) {

            gcd *= i;

            a /= i;
            b /= i;
        }
    }

    return gcd;
}


int main() {
    int a = 24, b = 36;
    cout << "GCD = " << gcdPrimeFactor(a, b);
    return 0;
}


//Method 3: Euclid’s Algorithm (Best Method), tc=O(log(min(a, b))), sc=O(1)
int gcdEuclid(int a, int b) {

    while (b != 0) {

        int rem = a % b;

        a = b;
        b = rem;
    }
    return a;
}

int main() {
    int a = 24, b = 36;
    cout << "GCD = " << gcdEuclid(a, b);
    return 0;
}

// Recursive Euclid Version, tc=O(log(min(a, b))) = sc
#include <iostream>
using namespace std;

int gcd(int a, int b) {

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main() {
    int a = 24, b = 36;
    cout << "GCD = " << gcd(a, b);
    return 0;
}




// 8th May 2026 (Friday)
// qno 1979  https://leetcode.com/problems/find-greatest-common-divisor-of-array/
class Solution {
public:
    // Euclidean Algorithm
    int gcdEuclid(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int smallNo = *min_element(nums.begin(), nums.end());
        int largNo  = *max_element(nums.begin(), nums.end());

        return gcdEuclid(smallNo, largNo);
    }
};


// src: D:\GitProj\MyAdvDSA_PathwayToCP\Algo\2_MathsForDSA\GCD\HCF_GCD.CPP
int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if(a == 0) return b;
    return a;
}