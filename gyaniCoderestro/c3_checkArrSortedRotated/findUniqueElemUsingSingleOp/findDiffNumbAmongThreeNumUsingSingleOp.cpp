


/*
7th May 2026 (Thursday)

prob: Find different number among three numbers using single operator
Link: https://www.instagram.com/reel/DXjFd09ATYI   (25 April Sat uploaded)


Find different number among three numbers using single operator  | Important Interview Question

given numbers: A=7, B = 12, C = 7

Operators allowed:  +, -, *, /, %, ^, <, >



Observation:
Same numbers cancel each other using XOR (^)  yah independence of numbers but must have two duplicate
Properties of XOR:
a ^ a = 0
a ^ 0 = a

So:
7 ^ 12 ^ 7
= (7 ^ 7) ^ 12
= 0 ^ 12
= 12

Hence XOR gives the unique element.
TC = O(1) = SC 



*/



#include <iostream>
using namespace std;

int findDifferent(int a, int b, int c) {

    return a ^ b ^ c;
}

int main() {

    int A = 7;
    int B = 12;
    int C = 7;

    cout << "Different Number = " << findDifferent(A, B, C);

    return 0;
}


// git commit -m "feat(gyaniCoderestro): Use the XOR operator to find the unique element, identical values cancel out because X^X = 0 "


/*
Use the XOR operator to find the unique element.

When you compute A^B^C, identical values cancel out because X^X = 0.

For example, if A = 7, B = 12, and C = 7, then 7 ^12 ^ 7 = 12.
Thus, XOR helps isolate the distinct element efficiently.

- - -
Sent via @SuperProfile.bio

*/