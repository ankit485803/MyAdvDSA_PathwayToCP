
#include <iostream>
using namespace std;


/*  

a*b = LCM(a, b) * HCF(a, b)

or said,  a*b = gcd(a, b) * lcm(a, b)


*/

int gcdRec(int a, int b) {
    if(b == 0) return a;

    return gcdRec(b, a % b);
}



//LCM
int lcm(int a, int b) {
    int gcd = gcdRec(a, b);
    return (a*b) / gcd;
}



int main() {

    cout << "GCD of a & b = " << gcdRec(20, 28) << endl;
    cout << "LCM of a & b = " << lcm(20, 28) << endl;

    return 0;
}