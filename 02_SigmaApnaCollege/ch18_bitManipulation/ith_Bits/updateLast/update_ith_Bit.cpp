
git commit -m "feat(sigmaApnaCollege): cover get, set and update ith Bit and (ch18_bitManipulation)" 
/*

15th Oct 2026 (Thursday - fifthPuja Navrartri)


*/

#include <iostream>
using namespace std;


void updateIthBit(int num, int i, int val) {
    num = num & ~(1 << i);  //clear ith Bit using bitwiseAND and leftShift
    
    num = num | (val << i);  //set bit using bitwiseOR and leftShift

    cout << num << endl;

}

int main() {

    updateIthBit(7, 2, 0);    //in num = 7, ko i=2 position pe binaryForm mai left side se, clear 1 and set to 0 then return num in decimal

    updateIthBit(7, 3, 1);  // ans = 15
    
    return 0; 
}