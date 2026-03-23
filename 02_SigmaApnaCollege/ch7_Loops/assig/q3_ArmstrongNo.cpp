

/*

Question 3 : WAP to input a number and check whether the number is an Armstrong
number or not.

An Armstrong number is a number that is equal to the sum of cubes of its digits.

Armstrong = sum of (each digit raised to the power n)


*/



#include <iostream>
using namespace std;
#include <vector>

bool isArmstrong(int num) {
    int original = num;  // store original
    int sum = 0;

    while(num > 0) {
        int lastD = num % 10;  //digits
        //int cube = lastD * lastD * lastD;  //find cube

        sum += lastD * lastD * lastD;
        num /= 10;
    }

    return sum == original;
}


bool isArmstrong2(int num) {
    int original = num;  // store original

    //step1: extractDigits
    vector<int> digits;

    while(num > 0) {
        int last = num % 10;
        digits.push_back(last);
        num /= 10;  //removeLast
    }

    //step2: cube and sum
    int sum = 0;
    for(int i=0; i<digits.size(); i++) {
        int cube = digits[i] * digits[i] * digits[i];
        sum += cube;
    }
    
    //finally
    if(original == sum) {
        return true;
    } else {
        return false;
    }
}



int main() {
    int num = 153;

    //https://github.com/ankit485803/MyAdvDSA_PathwayToCP/blob/main/02_SigmaApnaCollege/ch7_Loops/practiceQs/isPrimeByShardhaDi.cpp

    if(isArmstrong(num)) {
        cout << "Numb is armstrong" << endl;
    } else {
        cout << "not armstrong" << endl;
    }

    return 0;
}




/*

General Armstrong Concept
For a number with n digits:

Armstrong = sum of (each digit raised to the power n)

Examples:
153 → 3 digits → 
1^3 + 5^3 + 3^3 = 153  ✓

9474 → 4 digits → 
9^4 + 4^4 + 7^4 + 4^4 = 9474  ✓



*/


#include <cmath>   // for pow()

bool isArmstrongGeneral(int num) {
    int original = num;

    // step1: extract digits
    vector<int> digits;

    while(num > 0) {
        int last = num % 10;
        digits.push_back(last);
        num /= 10;
    }

    // step2: count digits
    int n = digits.size();

    // step3: power sum
    int sum = 0;
    for(int i = 0; i < digits.size(); i++) {
        sum += pow(digits[i], n);
    }

    // final check
    return sum == original;
}




#include <cmath>

bool isArmstrongGeneral(int num) {
    int original = num;

    // count digits
    int temp = num;
    int n = 0;
    while(temp > 0) {
        n++;
        temp /= 10;
    }

    // calculate sum
    int sum = 0;
    while(num > 0) {
        int last = num % 10;
        sum += pow(last, n);
        num /= 10;
    }

    return sum == original;
}



cout << isArmstrongGeneral(153) << endl;   // 1 (true)
cout << isArmstrongGeneral(9474) << endl;  // 1 (true)
cout << isArmstrongGeneral(123) << endl;   // 0 (false)