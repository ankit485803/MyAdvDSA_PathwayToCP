



/*

20th Nov 2025 (Thursday)


qno  61  https://leetcode.com/problems/rotate-list/

61. Rotate List
Medium
Topics

Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109



When we rotate a linked list to the right by k positions, it means that the nodes are shifted k times to the right. The nodes that move out of the end will reappear at the start of the list.


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
    ListNode* rotateRight(ListNode* head, int k) {  //TC=O(n), SC=O(1)

        if (!head || !head->next || k == 0) return head; // Edge cases
        
        //step1: find lengthLL
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        //step2: Reduce k to avoid unnecessary rotations
        k = k % length;
        if (k == 0) return head;  // If k is a multiple of length, no rotation needed
        

        //step3: Find the new tail (n-k-1) and new head (n-k)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        
        //step4: rotateList
        newTail->next = nullptr; // Break the list
        temp->next = head; // Connect the old tail to the old head
        
        return newHead;
    }
};




/*


qno  20  https://leetcode.com/problems/linked-list-components/description/


817. Linked List Components
Medium
Topics

Companies
You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.

Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

 

Example 1:


Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:


Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
 

Constraints:

The number of nodes in the linked list is n.
1 <= n <= 104
0 <= Node.val < n
All the values Node.val are unique.
1 <= nums.length <= n
0 <= nums[i] < n
All the values of nums are unique.


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
    int numComponents(ListNode* head, vector<int>& nums) {  //TC=O(n + m), SC=O(m), wher n=no of node, m=nums size

        // Step 1: Convert nums into a set for fast lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Step 2: Traverse LL and count connected components
        int count = 0;
        bool inComponent = false; 
        

        while (head) {
            if (numSet.find(head->val) != numSet.end()) { 
                if (!inComponent) { 
                    count++;
                    inComponent = true; // we are now in a component
                }
            } else {
                inComponent = false;

            }

            head = head->next; 
        }
        
        return count;
    }
};
