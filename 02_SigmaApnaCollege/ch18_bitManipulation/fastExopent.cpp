
git commit -m "feat(sigmaApnaCollege): complete this chap by covering lastTopic FastExpo using bit (ch18_bitManipulation)" 

/*

Fast Exponent 

method1: iterative tc=O(n) linear sare digits pe jake

method2: fastExpo approach jismai hm log(n) time se


Note that long long also has a finite range, so sufficiently large powers can still overflow.
Remember: Check the last bit, multiply when it is 1, square the base, and shift the exponent right. That's the core idea of fast exponentiation.



*/

#include <iostream>
using namespace std;


void fastExpo(int x, int n) {
    int ans = 1;

    while(n > 0) {
        int lastBit = n & 1;  //using bitwiseAND

        if(lastBit) {
            ans = ans * x;
        }

        x = x * x;  //multiply
        n = n >> 1;  //rightShift by 1
    }

    cout << ans << endl;
}


int main() {

    fastExpo(3, 5);  //3^5 = 243

    return 0;
}


/* preventOverflow
int usually stores values up to about  2.1 * 10^9  while long long stores values up to about 9.22 * 10^18




1. Use long long (simple approach)

long long fastExpo(long long x, int n) {
    long long ans = 1;

    while (n > 0) {
        if (n & 1) {
            ans = ans * x;
        }

        x = x * x;
        n >>= 1;
    }

    return ans;
}
Limitation: Even long long can overflow when the result becomes too large. Simply using a larger data type doesn't guarantee safety.


2. Use modulo (%) — common in DSA and competitive programming
If the question asks for the answer modulo 10^9+7, apply modulo after each multiplication.
#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long fastExpo(long long x, long long n) {
    long long ans = 1;
    x %= MOD;

    while (n > 0) {
        if (n & 1) {
            ans = (ans * x) % MOD;
        }

        x = (x * x) % MOD;
        n >>= 1;
    }

    return ans;
}

(a×b)modm=((amodm)(bmodm))modm
Because both ans and x remain smaller than MOD, their product fits inside a long long for this particular modulus.

Important: Modulo gives you the remainder, not the full value of 


3. Check before multiplication
If you need the exact result without modulo, you can check whether multiplication would overflow before performing it.

For positive integers:
#include <climits>

if (x != 0 && ans > LLONG_MAX / x) {
    // Overflow would occur
    return -1;
}

ans *= x;

You must also check x * x before squaring it. Returning -1 is just an example of an overflow-handling policy; choose an appropriate response for your application.
*/