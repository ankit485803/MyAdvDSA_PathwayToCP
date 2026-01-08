
 //step1: calculateSizeLL
        int iterativeSizeLL(ListNode* head) {
            int sizeLL = 0;
            Node* current = head;  //startWithHead

            while(current != nullptr) {
                sizeLL ++;
                current = current->next;
            }
            return sizeLL;
        }




/*

11th Nov 2025 (Tuesday)

qno 203  https://leetcode.com/problems/remove-linked-list-elements/description/


203. Remove Linked List Elements
Easy
Topics

Companies
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
 


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
    ListNode* removeElements(ListNode* head, int val) {  //TC=O(n) everyNode visitedOnce, SC=o(1)
        //taatlThreeCases Made

        //case1: List is EMPTY - TC=O(1)
        if(head == nullptr) {
            return head;  //doNothing justReturn

        }

        //case2: Node to be deleted is at HeadPosition  - TC=O(n)
        while(head != nullptr  && head->val == val) {
            ListNode* temp = head;  //createOneTempNode because weDon't directly applyOn LL cause destru of LL
            head = head->next;
            delete temp;  // deallocate memory of oldHead
        }

        

        //case3: Node to be deleted is at END or MIDDLE of LL   - TC=O(n)
        ListNode* curr = head;
        while(curr != nullptr  && curr->next != nullptr) {

            if(curr->next->val  == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;

            } else {
                curr = curr->next;
            }
        }

        return head;  //updatedHead
        

    }
};