

/*

13th Oct 2026 (Tuesday - 3rd Puja Navaratri)

Find the ith bits 

*/


#include <iostream>
using namespace std;


int getIthBit(int num, int i) {
    int bitMask = 1 << i;

    if((num & bitMask) == 0) {  //using bitwise AND operator
        return 0;
    } else {
        return 1;
    }
}


int main() {

    cout << getIthBit(6, 2) << endl;  //6 ke binary mai 2nd bit hon sa hoga find out karo

    return 0;
}