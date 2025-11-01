



/*

1st Nov 2025 (Satursday)




qno 3289  https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/

3289. The Two Sneaky Numbers of Digitville
Easy
Topics

Companies
Hint
In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.

 

Example 1:

Input: nums = [0,1,1,0]

Output: [0,1]

Explanation:

The numbers 0 and 1 each appear twice in the array.

Example 2:

Input: nums = [0,3,2,1,3,2]

Output: [2,3]

Explanation:

The numbers 2 and 3 each appear twice in the array.

Example 3:

Input: nums = [7,1,5,4,3,4,6,0,9,5,8,2]

Output: [4,5]

Explanation:

The numbers 4 and 5 each appear twice in the array.

 

Constraints:

2 <= n <= 100
nums.length == n + 2
0 <= nums[i] < n
The input is generated such that nums contains exactly two repeated elements.

*/


class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) { //TC=O(nlogN), sc=O(1) but this give TLE 
        
        //bruteForceAppraoch - CheckUnique Occurence or moreThanOneElem

        vector<int> ans;
        sort(nums.begin(), nums.end());  //sorting TC=O(logN) 

        int idx=0;
        while(idx < nums.size() ) {

            if(nums[idx] == nums[idx + 1]) {
                ans.push_back(nums[idx]);
                idx ++;
            }
        }

        return ans;
    
    }
};



class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) { //TC=O(nlogN), sc=O(1)  , runtime error due to HEAP BUFFER OVERFLOW  
    

        vector<int> ans;
        sort(nums.begin(), nums.end());  //sorting TC=O(logN) 

         
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == nums[i+1]) {
                ans.push_back(nums[i]);
                i++;
            }
        }

        return ans;
    
    }
};



#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 1; i < nums.size(); ++i) {  // start from 1
            if (nums[i] == nums[i - 1]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
