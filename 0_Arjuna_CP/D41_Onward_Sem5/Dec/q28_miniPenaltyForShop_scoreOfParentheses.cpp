




/*


28th Dec 2025 (Sunday)


qno 2483  https://leetcode.com/problems/minimum-penalty-for-a-shop/description/


2483. Minimum Penalty for a Shop
Medium
Topics

Companies
Hint
You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

 

Example 1:

Input: customers = "YYNY"
Output: 2
Explanation: 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
Example 2:

Input: customers = "NNNNN"
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers arrive.
Example 3:

Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.
 

Constraints:

1 <= customers.length <= 105
customers consists only of characters 'Y' and 'N'.



*/


class Solution {
public:
    int bestClosingTime(string customers) {  //tc=O(n), sc=O(1)
        int n = customers.size();

        // Step1: Count total Y's
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Step2: Try closing at each hour j (1 to n)
        for (int j = 1; j <= n; j++) {
            if (customers[j - 1] == 'Y') {
                penalty--;   // no longer closed during a customer hour
            } else {
                penalty++;   // stayed open with no customers
            }

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }

        return bestHour;
    }
};




/*


qno 20  https://leetcode.com/problems/valid-parentheses/


20. Valid Parentheses
Solved
Easy
Topics

Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.




*/



class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for(int i=0; i<str.size(); i++) {
            if(str[i] == '('  || str[i] == '{'  || str[i] == '[') {   //OPENING

                st.push(str[i]);

            } else {  // CLOSING
                if(st.size() == 0) {
                    return false;
                }

                if((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']'))    {

                        st.pop();

                    }  else {  //NO MATCH
                        return false;
                    }
            }
        }


        return st.size() == 0;

    }
};

// TC = O(n), SC = O(n) because we use stack DataStr




/*


qno 856  https://leetcode.com/problems/score-of-parentheses/description/


856. Score of Parentheses
Medium
Topics

Companies
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
 

Constraints:

2 <= s.length <= 50
s consists of only '(' and ')'.
s is a balanced parentheses string.



*/



class Solution {
public:
    int scoreOfParentheses(string s) {  //tc=O(n)=sc
        stack<int> stk;
        
        for (char c : s) {
            if (c == '(') {
                stk.push(0); 
            } else {
                int score = 0;
                if (stk.top() == 0) {
                    score = 1;  // Base case: "()" has score 1
                } else {
                    while (!stk.empty() && stk.top() != 0) {
                        score += stk.top();  // Add previous scores for nested parentheses
                        stk.pop();
                    }
                    score *= 2;  
                }
                stk.pop();  
                stk.push(score);  // Push the calculated score back to the stack
            }
        }
        
        int totalScore = 0;
        while (!stk.empty()) {
            totalScore += stk.top();
            stk.pop();
        }
        
        return totalScore;
    }
};




/*


qno  2487   https://leetcode.com/problems/remove-nodes-from-linked-list/


2487. Remove Nodes From Linked List
Medium
Topics
premium lock icon
Companies
Hint
You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105



*/



/*


qno 1004 https://leetcode.com/problems/max-consecutive-ones-iii/description/


1004. Max Consecutive Ones III
Solved
Medium
Topics

Companies
Hint
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length



*/


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxFlip = 0;
        int maxLeng = 0;
        int i = 0;
        for(int j=0; j<nums.size(); j++) {  //sliddingWindow
            if(nums[j] == 0) {
                maxFlip++;
            }
            while(maxFlip > k) {
                if(nums[i] == 0) {
                    maxFlip--;
                }
                i++;
            }
            maxLeng = max(maxLeng, j-i+1);
        }

        return maxLeng;
    }
};