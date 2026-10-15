


/*

15th OCt 2026 (Thursday)

Ques. WAF to clear last ith bits of number
            num = 15, i = 2

ok

*/


#include <iostream>
using namespace std;


void clearIthBits(int num, int i) {
    int bitMask = (~0) << i;
    //finalOperation
    num = num & bitMask;

    cout << num << endl;
}


int main() {

    clearIthBits(15, 2);  //clear last 2nd bit from num = 15

    return 0;
}