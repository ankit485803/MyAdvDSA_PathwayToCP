

/*

Set Ith Bit in nums: means ith place ke 0 converts to 1 and 1 converts to 1


*/


#include <iostream>
using namespace std;


int setIthBit(int num, int i) {
    int bitMask = 1 << i;

    return (num | bitMask);  //using bitwise OR operator
}


int main() {

    cout << setIthBit(6, 3) << endl;  //set karo do 3rd position nums 3 binary to 1 and then return in decimal

    return 0;
}