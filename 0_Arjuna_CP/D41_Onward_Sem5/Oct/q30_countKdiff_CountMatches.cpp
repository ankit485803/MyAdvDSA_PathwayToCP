


/*


9th Nov 2025 (Sunday)

qno 2006  https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/


2006. Count Number of Pairs With Absolute Difference K
Solved
Easy
Topics

Companies
Hint
Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.
 

Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:

Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99


*/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {  //TC=O(n)=SC due to map
        unordered_map<int, int> freq;
        int count = 0;

        for (int num : nums) {
            // Count pairs where |num - x| == k
            if (freq.count(num - k)) count += freq[num - k];
            if (freq.count(num + k)) count += freq[num + k];
            freq[num]++;
        }

        return count;
    }
};





class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        //bruteForceApproach TC=(n*n), sc=O(1) optimize using HashMap O(n)
        
        //initilize count which count no of such reqPairs
        int count = 0;

        for(int i=0; i<nums.size(); i++) {  //O(n*n) due nestedLoop
            for(int j=i+1; j<nums.size(); j++) {
                //checkCondition
                if( (abs(nums[i] - nums[j]) == k)  ){
                    count++;
                } 
            }
        }

        return count;
    }
};



/*

qno 1758   https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/


1758. Minimum Changes To Make Alternating Binary String
Easy
Topics

Companies
Hint
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

 

Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.
Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.
Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
 

Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.



💡 Approach
1. Initialize two counters:
        count1 → number of mismatches if the string should be "0101..."
        count2 → number of mismatches if the string should be "1010..."

2. Traverse the string once:
    For even index (i % 2 == 0):
            Expected '0' in pattern 1 → if it’s not '0', increment count1
            Expected '1' in pattern 2 → if it’s not '1', increment count2

    For odd index:
            Expected '1' in pattern 1
            Expected '0' in pattern 2


3. Return min(count1, count2).



*/


class Solution {
public:
    int minOperations(string s) {  //TC=O(n),SC=O(1)
 
        int count1 = 0; 
        int count2 = 0; 

        for (int i = 0; i < s.size(); i++) {

            // Case1: evenIndex (i = 0, 2, 4, ...)
            if (i % 2 == 0) {
                // For pattern "0101...", even positions should be '0'
                if (s[i] != '0') count1++;

                // For pattern "1010...", even positions should be '1'
                if (s[i] != '1') count2++;
            } 



            // Case2: oddIndex (i = 1, 3, 5, ...)
            else {a
                // For pattern "0101...", odd positions should be '1'
                if (s[i] != '1') count1++;

                // For pattern "1010...", odd positions should be '0'
                if (s[i] != '0') count2++;
            }
        }


        return min(count1, count2);
    }
};


/*

qno 1773    https://leetcode.com/problems/count-items-matching-a-rule/description/


1773. Count Items Matching a Rule
Attempted
Easy
Topics

Companies
Hint
You are given an array items, where each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item. You are also given a rule represented by two strings, ruleKey and ruleValue.

The ith item is said to match the rule if one of the following is true:

ruleKey == "type" and ruleValue == typei.
ruleKey == "color" and ruleValue == colori.
ruleKey == "name" and ruleValue == namei.
Return the number of items that match the given rule.

 

Example 1:

Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1
Explanation: There is only one item matching the given rule, which is ["computer","silver","lenovo"].
Example 2:

Input: items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
Output: 2
Explanation: There are only two items matching the given rule, which are ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item ["computer","silver","phone"] does not match.
 

Constraints:

1 <= items.length <= 104
1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
ruleKey is equal to either "type", "color", or "name".
All strings consist only of lowercase letters.


*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) { //TC=O(n),SC=O(1)

        int count = 0; // to count matching items

        // Each item: [type, color, name]
        for (int i = 0; i < items.size(); i++) {

            // determine which index to check based on ruleKey
            int index = 0;
            if (ruleKey == "type") index = 0;
            else if (ruleKey == "color") index = 1;
            else if (ruleKey == "name") index = 2;


            // compare the corresponding field with ruleValue
            if (items[i][index] == ruleValue) {
                count++;
            }
        }

        return count;
    }
};
