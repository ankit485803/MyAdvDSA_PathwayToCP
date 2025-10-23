



/*

23rd Oct 2025 (Thursday - train for Lucknow ISRO ICRB paper)


qno 2562  https://leetcode.com/problems/find-the-array-concatenation-value/

2562. Find the Array Concatenation Value
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums.

The concatenation of two numbers is the number formed by concatenating their numerals.

For example, the concatenation of 15, 49 is 1549.
The concatenation value of nums is initially equal to 0. Perform this operation until nums becomes empty:

If nums has a size greater than one, add the value of the concatenation of the first and the last element to the concatenation value of nums, and remove those two elements from nums. For example, if the nums was [1, 2, 4, 5, 6], add 16 to the concatenation value.
If only one element exists in nums, add its value to the concatenation value of nums, then remove it.
Return the concatenation value of nums.

 

Example 1:

Input: nums = [7,52,2,4]
Output: 596
Explanation: Before performing any operation, nums is [7,52,2,4] and concatenation value is 0.
 - In the first operation:
We pick the first element, 7, and the last element, 4.
Their concatenation is 74, and we add it to the concatenation value, so it becomes equal to 74.
Then we delete them from nums, so nums becomes equal to [52,2].
 - In the second operation:
We pick the first element, 52, and the last element, 2.
Their concatenation is 522, and we add it to the concatenation value, so it becomes equal to 596.
Then we delete them from the nums, so nums becomes empty.
Since the concatenation value is 596 so the answer is 596.
Example 2:

Input: nums = [5,14,13,8,12]
Output: 673
Explanation: Before performing any operation, nums is [5,14,13,8,12] and concatenation value is 0.
 - In the first operation:
We pick the first element, 5, and the last element, 12.
Their concatenation is 512, and we add it to the concatenation value, so it becomes equal to 512.
Then we delete them from the nums, so nums becomes equal to [14,13,8].
 - In the second operation:
We pick the first element, 14, and the last element, 8.
Their concatenation is 148, and we add it to the concatenation value, so it becomes equal to 660.
Then we delete them from the nums, so nums becomes equal to [13].
 - In the third operation:
nums has only one element, so we pick 13 and add it to the concatenation value, so it becomes equal to 673.
Then we delete it from nums, so nums become empty.
Since the concatenation value is 673 so the answer is 673.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104


*/

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {  //TC=(n), sc=O(1)
        
        //twoPointerApproach 
        long long concatVal = 0;   //initilize

        //if hm int concatVal = 0; se intilize kar to wah large value ke liye testCase nahi pass kar sakte 


        // takeTwoPointer who will update on each iterate
        int i=0, j=nums.size()-1;

        while(i <= j) {
            
            if(i == j) {
                concatVal += nums[i];  // If there is only one element left, add it directly

            } else {
                string concatenated = to_string(nums[i]) + to_string(nums[j]);
                concatVal += stol(concatenated);
            }

            i++;
            j--;

        }

        return concatVal;
    }
};



/*

qno 3346  https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/

qno 3347  https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/

qno 14 https://leetcode.com/problems/longest-common-prefix/

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        //baseCase
        if (strs.empty()) return "";
        
        string prefix = strs[0];


        for (int i = 1; i < strs.size(); ++i) {  //tc=O(m *  n), sc=0(1)
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }

            // Reduce the prefix to the commonPart
            prefix = prefix.substr(0, j);
            if (prefix == "") return "";
        }


        return prefix;
    }
};


/*

qno 1021   https://leetcode.com/problems/remove-outermost-parentheses/description/


1021. Remove Outermost Parentheses
Solved
Easy
Topics

Companies
Hint
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.


*/

class Solution {
public:
    string removeOuterParentheses(string s) {  //TC=O(n) = sc
        string result;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    result += c;  // Add the character if it's inside a primitive
                }
                depth++;  // IncreDepth  opening parenthesis

            } else {
                depth--;  // decrease on closing parenthesis
                if (depth > 0) {
                    result += c;  // Add the character if it's inside a primitive
                }
            }
        }

        return result;
    }
};
