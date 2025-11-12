


/*

12th Nov 2025 (Wednesday)

qno 19  https://leetcode.com/problems/remove-nth-node-from-end-of-list/


19. Remove Nth Node From End of List
Medium
Topics

Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?






*/


class Solution {
public:
    int iterativeSizeLL(ListNode* head) {
        int sizeLL = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            sizeLL++;
            curr = curr->next;
        }
        return sizeLL;
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {   //TC=O(n), SC=O(1)
        //Case1: Empty list
        if (head == nullptr) return nullptr;

        int sizeLL = iterativeSizeLL(head);

        //Case2: Remove the first node (also covers single-node list)
        if (n == sizeLL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }


        //Case3: General case
        ListNode* curr = head;
        for (int i = 1; i < sizeLL - n; ++i) {
            curr = curr->next;
        }

        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete;

        return head;
    }
};


