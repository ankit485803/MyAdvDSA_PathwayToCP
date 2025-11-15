



/*

15th Nov 2025 (Satursday)

qno 86   https://leetcode.com/problems/partition-list/


86. Partition List
Medium
Topics

Companies
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200


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
    ListNode* partition(ListNode* head, int x) { //TC=O(n), SC=O(1)
        
        //createTwoPointer for Partition
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* lessTail = &lessDummy;   // tail of nodes < x
        ListNode* greaterTail = &greaterDummy; // tail of nodes >= x 

        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = nullptr;

            if(curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }

            curr = nextNode;
        }


        // connectTwoPartitions
        lessTail->next = greaterDummy.next;
        greaterTail->next = nullptr;

        return lessDummy.next;
    }
};


/*

qno  2654   https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/


2654. Minimum Number of Operations to Make All Array Elements Equal to 1
Medium
Topics

Companies
Hint
You are given a 0-indexed array nums consisting of positive integers. You can do the following operation on the array any number of times:

Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

The gcd of two integers is the greatest common divisor of the two integers.

 

Example 1:

Input: nums = [2,6,3,4]
Output: 4
Explanation: We can do the following operations:
- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
Example 2:

Input: nums = [2,10,6,14]
Output: -1
Explanation: It can be shown that it is impossible to make all the elements equal to 1.
 

Constraints:

2 <= nums.length <= 50
1 <= nums[i] <= 106



*/


class Solution {
public:
    int minOperations(vector<int>& nums) {  //TC=O(n^2 * Log(max(nums))), SC=O(1)
        int n = nums.size();
        
        // Step 1: count existing 1s
        int count1 = 0;
        for (int x : nums) 
            if (x == 1) count1++;
        
        // If we already have ones
        if (count1 > 0) {
            return n - count1;  // each non-1 takes 1 operation
        }

        // Step 2: find shortest subarray with gcd = 1
        int bestLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = std::gcd(g, nums[j]);
                if (g == 1) {
                    bestLen = min(bestLen, j - i + 1);
                    break;  // no need to extend further
                }
            }
        }

        // If impossible to create a 1
        if (bestLen == INT_MAX) return -1;

        // Step 3: operations needed
        // (bestLen - 1) to create 1
        // (n - 1) to make all elements 1
        return (bestLen - 1) + (n - 1);
    }
};
