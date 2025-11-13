


/*

13th Nov 2025 (Thursday)



qno 2149   https://leetcode.com/problems/rearrange-array-elements-by-sign/description/



2149. Rearrange Array Elements by Sign
Solved
Medium
Topics

Companies
Hint
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
Example 2:

Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
 

Constraints:

2 <= nums.length <= 2 * 105
nums.length is even
1 <= |nums[i]| <= 105
nums consists of equal number of positive and negative integers.
 

It is not required to do the modifications in-place.


*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {  //TC= O(n) = SC
        
        //step1: make separatePositive and Negative from nums
        vector<int> positives, negatives;

        for(int num : nums) {
            if(num > 0) {
                positives.push_back(num);
            } else {
                negatives.push_back(num);
            }
        }

        //step2: ans arr to store rearrangedValues
        vector<int> ans;

        //inplace the positive and negative
        for(int i=0; i<positives.size(); ++i) {  //sizeOf both positiveNegative is same
            ans.push_back(positives[i]);
            ans.push_back(negatives[i]);
        }


        return ans;
    }
};



/*

qno 3228  https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/


3228. Maximum Number of Operations to Move Ones to the End
Medium
Topics

Companies
Hint
You are given a binary string s.

You can perform the following operation on the string any number of times:

Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
Return the maximum number of operations that you can perform.

 

Example 1:

Input: s = "1001101"

Output: 4

Explanation:

We can perform the following operations:

Choose index i = 0. The resulting string is s = "0011101".
Choose index i = 4. The resulting string is s = "0011011".
Choose index i = 3. The resulting string is s = "0010111".
Choose index i = 2. The resulting string is s = "0001111".
Example 2:

Input: s = "00111"

Output: 0

 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.


*/


class Solution {
public:
    int maxOperations(string s) {
        
        int lastOne = s.find_last_of('1');
        long long operations = 0;
        int count1 = 0;

        for(int i=0; i<lastOne; ++i) {
            if(s[i] == '1') {
                count1++;

            } else {  //if  s[i] == '0'
                operations += count1;
            }
        }

        if(s.back() == '1') operations -= 1;    //adjacement
        return operations;
    }
};


//my version (expanded braces)

class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') {
                ones++;

            } else if(i > 0 && s[i - 1] == '1') {
                ans += ones;
            }
        }

        return ans;
    }
};


//RamanDeep CP Friend’s version (compact braces)
class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ones++;
            else if ((i > 0) && s[i - 1] == '1')
                res += ones;
        }

        return res;
    }
};

// ✅ Explanation:
// They omit {} for single-line if / else statements — this is allowed in C++.
// It’s shorter and common in competitive programming.
// Variable name: res (short for result).




class Solution {
public:
    int maxOperations(string s) {  //TC=O(n), SC=O(1)
        int ones = 0, ans = 0;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == '1')
                ones++;
            else if((i > 0) && s[i - 1] == '1')
                ans += ones;    
        }

        return ans;
    }
};