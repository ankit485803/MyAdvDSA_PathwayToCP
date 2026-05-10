



/*

10th May 2026 (Sunday) practiceQs

WAF to find the product of 2 numb - a & b

WAF to print if a numb is odd or even

*/


#include <iostream>
using namespace std;

int prodTwoNo(int a, int b) {
    int prod = a * b;
    return prod;
}



bool isEven(int numb) {  //error
    if(numb % 2 == 0) {
        cout << "Even no \n";
    } else {
        cout << "Odd no \n"; 
    }
}


bool isEven2(int numb) {
    if(numb % 2 == 0) {
        return true;
    } else {
        return false;
    }
}


int main() {
    int a = 10, b = 5;

    cout << "product = " << prodTwoNo(a, b) << endl;
    
    if(isEven2(a)) {
        cout << "Even no \n";
    } else {
        cout << "odd no \n";
    }

    return 0;
}



/*

^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSessiong++ sigmaApnaCollege.cpp -o myRunFile.exe
sigmaApnaCollege.cpp: In function ‘bool isEven(int)’:
sigmaApnaCollege.cpp:15:1: warning: no return statement in function returning non-void [-Wreturn-type]
   15 | }
      | ^
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/


bool isEven(int numb) {
    return numb % 2 == 0;
}