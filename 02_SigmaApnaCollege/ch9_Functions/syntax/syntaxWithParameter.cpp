

/*

9th May 2026 (Saturday)

Syntax with parameters

q. diff b/w parameter and arguments  
Ans: parameter waha sirf input lete hai funct mai, but arguments mai hm koi fix value dete hai


DEFAULT parameter - jab koi arguments nahi user de to default value pas kar do and be alert fist para ko kabhi bhi nahi assing karte hai
*/


returnType fName(para1, para2, ....) {  //two se jada bhi ho skata hai parameters
    //do someWork

    returnValue;
}


#include <iostream>
using namespace std;

int sumTwoNo(int a, int b=1) {  //yah a, b are parameters
    int sum = a + b;
    return sum;
}


int main() {
    int ans = sumTwoNo(2, 4);
    
    cout << "sum = " << ans << "\n";  //2, 4 are ARGUMENTS

    return 0;
}



git commit -m "feat(sigmaApnaCollege): learn syntaxWithPara, diff b/w para and arguments, defaultParameters (ch9)"