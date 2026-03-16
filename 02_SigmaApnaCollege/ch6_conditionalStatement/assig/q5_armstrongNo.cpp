

/*

Question 5 : For any 3 digit number check whether it’s an Armstrong number or not.
Armstrong number is a number that is equal to the sum of cubes of its digits.
Eg : 371 is an armstrong number.
3*3*3 + 7*7*7 + 1*1*1 = 371



Bonus : Read up about the difference between typedef (keyword), macros & const
(keyword) in C++



*/



#include <iostream>
using namespace std;
#include <vector>

bool isArmstrongNo(int nums) {
    int original = nums;

    //step1:  EXTRACT eachDigit from num and store 
    vector<int> digits;
    
    while(nums > 0) {
        int last = nums % 10;
        digits.push_back(last);
        nums = nums / 10;
    }
    
    //step2: mainLogic - square and sum
    int sum = 0;
    for(int i=0; i<digits.size(); i++) {
        sum += digits[i] * digits[i] * digits[i];
    }
    return sum == original;
}


int main() {
    int nums;
    cout << "Enter nums: ";
    cin >> nums;

    if(isArmstrongNo(nums)) {
        cout << "Armstrong No" << endl;
    } else {
        cout << "not armstrong no" << endl;
    }

    return 0;
}




#include <iostream>
using namespace std;

bool isArmstrong(int num) {

    int original = num;
    int sum = 0;

    while(num > 0) {
        int digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }

    return sum == original;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << (isArmstrong(n) ? "Armstrong Number" : "Not Armstrong Number") << endl;

    return 0;
}




//common armstrongNo for testcases
// 153
// 370
// 371
// 407