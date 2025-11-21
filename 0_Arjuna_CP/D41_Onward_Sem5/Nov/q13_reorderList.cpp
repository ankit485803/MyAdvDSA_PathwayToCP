



/*

21st Nov 2025 (Friday - Last day of instruction class Sem5 IITP 3rd year CSDA ankit - of OS, CNS, AI)


qno 143   https://leetcode.com/problems/reorder-list/description/


143. Reorder List
Medium
Topics

Companies
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000



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
    void reorderList(ListNode* head) {  //TC=O(n), SC=O(1)
        if(!head ||  !head->next) return;  //edgeCase if 0 or 1 elem, no need to reorder

        //step1: findMiddleList - O(n) tc
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {  //using slowFastPointer
            slow = slow->next;
            fast = fast->next->next;
        }


        //step2: revSecondHalf - O(n) tc
        ListNode* second = slow->next;
        slow->next = nullptr;  //Split the list into two halves
        ListNode* prev = nullptr;

        while(second) {
            ListNode* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }


        //step3: mergeTwoHalves - O(n) tc
        ListNode* first = head;
        second = prev;  //'second' now points to the head of the reversed second half
        while(second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};





/*

qno  148  https://leetcode.com/problems/sort-list/





*/