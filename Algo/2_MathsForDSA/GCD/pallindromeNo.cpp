
#include <iostream>
using namespace std;
#include <climits>   //for OVERFLOW case INT_MAX i.e. C++ STL


// Pallindrome number -- only for positive no
//eg.  n = 353 , aap pallindrome ke liyer find the rev 

//Qno 9.   https://leetcode.com/problems/palindrome-number/




//make funct to rev a numb
int reverse(int n) {
        
        int revNum = 0;

        while(n != 0) {
            int dig = n % 10;

            //check within RANGE -- otherwise overflow case hoga
            if(revNum > INT_MAX / 10 ||  revNum  < INT_MIN / 10) {
                return 0;
            }

            revNum = revNum * 10 + dig;
            n = n / 10;
        }

        return revNum;
    }




class Solution {
public:
    bool isPalindrome(int n) {
        
        if(n < 0) return false;   //can't check pallindrome for negative no

        int revNum = reverse(n);
        return n == revNum;
    }
};


//TC=O(n), SC=O(1)