

/*

11th May 2026 (Monday)

qno 2553  https://leetcode.com/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-11

2553. Separate the Digits in an Array
Easy
Topics

Companies
Hint
Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.

To separate the digits of an integer is to get all the digits it has in the same order.

For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].
 

Example 1:

Input: nums = [13,25,83,77]
Output: [1,3,2,5,8,3,7,7]
Explanation: 
- The separation of 13 is [1,3].
- The separation of 25 is [2,5].
- The separation of 83 is [8,3].
- The separation of 77 is [7,7].
answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations in the same order.
Example 2:

Input: nums = [7,1,3,9]
Output: [7,1,3,9]
Explanation: The separation of each integer in nums is itself.
answer = [7,1,3,9].
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105
 
Seen this question in a real interview before?
1/6
Yes
No
Accepted
157,115/186.9K
Acceptance Rate
84.1%
Topics
Mid Level
Array
Simulation
Biweekly Contest 97


*/


class Solution {
public:
    
    int helperSeparate(int num) {  //firstAttempt wrong
        int digits = 1;
        while(num > 0) {
            digits = num % 10;  //separate from lastDigits
            num /= 10;  //removeLast
        }

        return digits;
    }

    vector<int> separateDigits(vector<int>& nums) {  //tc=O(n), sc=O(1)
        vector<int> ans;

        for(int i=0; i < nums.size(); i++) {
            //eachElem of numms arr apply
            int dig = helperSeparate(nums[i]);

            ans.push_back(dig);
        }

        return ans;
    }
};




class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            string s = to_string(num);

            for (char ch : s) {
                ans.push_back(ch - '0');
            }
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {  //tc=O(totalDigits), sc=O(1)
        vector<int> ans;

        for(int num : nums) {
            string s = to_string(num);  //convert int to str

            //now mainLogic
            for(char ch : s) {
                ans.push_back(ch - '0');  //push into ans
            }
        }

        return ans;
    }
};



class Solution {
public:
    
    vector<int> helperSeparate(int num) {
        vector<int> temp;

        // extract digits from last
        while(num > 0) {
            int digit = num % 10;
            temp.push_back(digit);
            num /= 10;
        }

        // reverse order to maintain original sequence
        reverse(temp.begin(), temp.end());

        return temp;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            vector<int> digits = helperSeparate(nums[i]);

            for(int d : digits) {
                ans.push_back(d);
            }
        }

        return ans;
    }
};