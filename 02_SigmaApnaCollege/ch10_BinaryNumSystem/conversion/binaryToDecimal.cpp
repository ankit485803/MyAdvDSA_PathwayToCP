


/*

17th May 2026 (Sunday)

convert binary to decimal if num = 101


*/


#include <iostream>
using namespace std;
#include <cmath>  //req for pow(base, exponent)

//from ankitApproach
int binaryToDecimal(int num) {
    int base = 2, exp = 0;
    int ans = 0;

    while(num > 0) {
        int lastD = num % 10;
        ans += lastD * pow(base, exp);  //last * base^exp
        exp++;
        num /= 10;  //removeLastD
    }

    return ans;
}

// by ShardhaDi
void binToDec(int binNum) {
    int n = binNum;
    int decNum = 0;

    int pow = 1;  // 2^0, 2^1, .....

    while(n > 0) {
        int lastDig = n % 10;
        decNum += lastDig * pow;
        pow = pow * 2;
        n = n / 10;
    }
    cout << decNum << endl;
}



int main() {
    int binaryForm = 101;
    cout << "decimalForm of " << binaryForm << " = " << binaryToDecimal(binaryForm) << endl;

    // callFunct
    binToDec(101);

    return 0;
}