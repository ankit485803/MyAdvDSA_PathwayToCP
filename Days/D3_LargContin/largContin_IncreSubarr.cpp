
// ques  src ==  https://leetcode.com/problems/longest-continuous-increasing-subsequence/description
// NO = 674
// req concept: Array only

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //if empty
        if(nums.empty()) return 0;

        //initilize pointer
        int maxLength = 1, currLength = 1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {  //when Left > right
                currLength ++;
            }
            else {
                maxLength = max(currLength, maxLength);
                currLength = 1;
            }
        }
        //final comparison
        maxLength = max(currLength, maxLength);
        return maxLength;

        
    }
};

//Brute force aproach
// time complex = O(n), spcace = O(1)

