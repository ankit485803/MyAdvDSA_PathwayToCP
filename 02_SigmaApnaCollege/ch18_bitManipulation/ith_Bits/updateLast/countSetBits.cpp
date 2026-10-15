

/*

Count the set Bits problem

similar to sum of digits in num prob: jis mai hm last digits find out and add to sum


*/

#include <iostream>
using namespace std;


int countSetBits(int num) {
    int count = 0;

    while(num > 0) {
        int lastDig = num & 1;  //using bitwiseAND
        count += lastDig;

        num = num >> 1;  //rightShift
    }

    cout << count << endl;
    return count;

}


int main() {

    countSetBits(10);  //count no of ones in 10 binaryForm   ans = 2
    countSetBits(7);  //ans = 3

    return 0;
}