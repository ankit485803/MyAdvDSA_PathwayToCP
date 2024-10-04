
// ques src:  https://leetcode.com/problems/plus-one/description

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        //BRUTE-FORCE approach
        for(int i=n-1; i>=0; --i) {
            if(digits[i] < 9) {  //when less than 9, because this last one to decide the length of arr
                digits[i] += 1;  //add one
                return digits;

            }
            digits[i] = 0; // Set current digit to 0 and carry over

        }
        digits.insert(digits.begin(), 1); //prepand 1 to arr
        return digits;

    }
};

//time complexity = O(n), Space = O(1)