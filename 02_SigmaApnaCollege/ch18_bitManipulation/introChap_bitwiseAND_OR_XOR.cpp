
git commit -m "feat(sigmaApnaCollege): start newChap and cover bitwise AND, OR, XOR and shift opertors, checkOddEven(ch18_bitManipulation)" 

/*

10th Oct 2026 (Saturday)

yah chap use karte hai optimization + diff dataStr mai

&& yah logical AND, || yah logical OR hai be alert ankit

Rule of bitwiseAND:
    0 & 1 --> 0
    0 & 0 --> 0
    1 & 0 --> 0
    1 & 1 --> 0

Rule of bitwisOR:
    0 | 1 --> 1
    1 | 0 --> 1
    0 | 0 --> 0
    1 | 1 --> 1
    
Rule of bitwis XOR:  same dono then 0, and diff 1
    1 | 1 --> 0
    0 | 0 --> 0
    0 | 1 --> 1
    1 | 1 --> 1
    
    


*/


#include <iostream>
using namespace std;


int main() {

    //bitwise operator
    cout << (3 & 5) << endl;  //AND bitwise
    cout << (3 | 5) << endl;  //OR bitwise
    cout << (3 ^ 5) << endl;  //XOR bitwise

    return 0;
}