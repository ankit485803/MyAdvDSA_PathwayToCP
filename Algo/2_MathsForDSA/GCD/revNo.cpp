
#include <iostream>
using namespace std;
#include <climits>   //for OVERFLOW case INT_MAX i.e. C++ STL




// Reverse a Numb  -- qno 7   https://leetcode.com/problems/reverse-integer/description/
//topic req: only maths


class Solution {
public:
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
};


// TC = O(n), SC = O(1)