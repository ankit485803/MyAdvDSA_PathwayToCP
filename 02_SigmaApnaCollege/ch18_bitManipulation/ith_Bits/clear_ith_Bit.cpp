

/*

Clear ith Bit means: convert 0 into 0 and 1 into 0 jise wah clear ho jayega


*/


#include <iostream>
using namespace std;


int clearIthBit(int num, int i) {
    int bitMask = ~(1 << i);

    return num & bitMask;
}


int main() {

    cout << clearIthBit(6, 1) << endl;  //rightside se 1st position ko clear kar do


    return 0;
}