

/*

16th Nov 2025 (Sunday)


qno 1019   https://leetcode.com/problems/next-greater-node-in-linked-list/


1019. Next Greater Node In Linked List
Medium
Topics

Companies
Hint
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109




*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {  //TC=O(n)=SC
        vector<int> values;
        ListNode* temp = head;

        //step1: traverse list and store values 
        while(temp != nullptr) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> result(values.size(), 0);
        stack<int> stk;   //SC=O(n)

        //step2: traverse vector to find nextGreaterElem using stack
        for(int i=0; i<values.size(); ++i) {
            while(!stk.empty()  &&  values[i] > values[stk.top()]) {
                result[stk.top()] = values[i];
                stk.pop();
            }
            
            stk.push(i);  // Push current index onto the stack
        }

        return result;
    }
};



/*

qno 3467   https://leetcode.com/problems/transform-array-by-parity/


3467. Transform Array by Parity
Easy
Topics

Companies
Hint
You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:

Replace each even number with 0.
Replace each odd numbers with 1.
Sort the modified array in non-decreasing order.
Return the resulting array after performing these operations.

 

Example 1:

Input: nums = [4,3,2,1]

Output: [0,0,1,1]

Explanation:

Replace the even numbers (4 and 2) with 0 and the odd numbers (3 and 1) with 1. Now, nums = [0, 1, 0, 1].
After sorting nums in non-descending order, nums = [0, 0, 1, 1].
Example 2:

Input: nums = [1,5,1,4,2]

Output: [0,0,1,1,1]

Explanation:

Replace the even numbers (4 and 2) with 0 and the odd numbers (1, 5 and 1) with 1. Now, nums = [1, 1, 1, 0, 0].
After sorting nums in non-descending order, nums = [0, 0, 1, 1, 1].
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 1000


*/


class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {  //TC=O(n)=SC

        vector<int> ans;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] % 2 == 0) {
                ans.push_back(0);  // Store 0 for even numbers
            } else {
                ans.push_back(1);  // Store 1 for odd numbers
            }
        }

        // Sort the result in non-decreasing order
        sort(ans.begin(), ans.end());

        return ans;
    }
};
