

/*

How to reverse the digits in the given numb n = 25

revN = 52

method1: directly iterative approach 


method2: convert int into str, rev its character using c++ stl  and the return str into integer format
*/


#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int revN(int n) {  //tc=O(digits), sc=O(1)
    int myRev = 0;

    while(n > 0) {
        myRev = myRev * 10 + (n % 10);  //rev * 10 + lastDigit
        n /= 10;  //remove lastD
    }
    return myRev;
}



//Edge Cases You Missed
// ❌ Case 1: Negative numbers  n = -25, ans = 25-
//❌ Case 2: Trailing zeros, n = 1200, ans = 12
//❌ Case 3: Integer overflow (IMPORTANT) int n = 1534236469;
int revNumUsingStrApproach(int n) {  //tc=O(n)=sc
    string s = to_string(n);  //step1: convert int to str

    //step2: reverse its characters using STL reverse fuction
    reverse(s.begin(), s.end());

    //step3: return ans in integer format
    int ans = stoi(s);  //string to integer funct
    return ans;
}



int revNumUsingStrApproach(int n) {
    bool isNegative = n < 0;
    string s = to_string(abs(n));

    reverse(s.begin(), s.end());

    long long temp = stoll(s); // safer than stoi

    if (temp > INT_MAX) return 0; // handle overflow

    return isNegative ? -temp : temp;
}


// reverseNumberMath()
// reverseNumberString()
int main() {
    int n = 25;

    int ans = revNumUsingStrApproach(n);
    //cout << "reverse num of " << n << " = " << ans << endl;
    cout << "reverse num using string approach = " << ans << endl;

    return 0;
}







//STL concepts C++
#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

int main() {
    std::string str = "Hello World";
    
    // Reverses the string in-place
    std::reverse(str.begin(), str.end());
    
    std::cout << str; // Output: dlroW olleH
    return 0;
}

void reverseManual(std::string& str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        // Swap characters at opposite ends
        std::swap(str[i], str[n - i - 1]);
    }
}
