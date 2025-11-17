


/*

17th Nov 2025 (Monday - firstDayOf thisWeek - JaiMaaSarde OmJaneshNamh)


qno 92  https://leetcode.com/problems/reverse-linked-list-ii/


92. Reverse Linked List II
Medium
Topics

Companies
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?


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
    ListNode* reverseBetween(ListNode* head, int left, int right) { //TC=O(n), SC=O(1)
        
        if(!head || !head->next || left==right) return head;  //edgeCase: EMPTY list and singleNode

        //createDummy 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move prev to the node just before the 'left' position
        for(int i=1; i<left; ++i) {
            prev = prev->next;
        }

        //start revProcess
        ListNode* curr = prev->next;
        ListNode* next = nullptr;

        //rev sublist from left to right
        for(int i=left; i<right; ++i) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;

        }

        return dummy->next;  // Return the new head (which might be different if left == 1)
       
    }
};


/*

qno 164  https://leetcode.com/problems/maximum-gap/



164. Maximum Gap
Medium
Topics

Companies
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109



method2: 


*/

class Solution {
public:
    int maximumGap(vector<int>& nums) { //TC=O(n logN), SC=O(1)
        int n = nums.size();

        if(n < 2) return 0;  //edgeCase
        sort(nums.begin(), nums.end());  //O(logN) time

        //keyObservation: afterSorted we find maxDiff = abs(last - secondLast) elem
        int maxDiff = 0;

        for(int i=1; i<n; i++) {
            maxDiff = max(maxDiff, nums[i] - nums[i-1]);
        }

        return maxDiff;
    }
};



