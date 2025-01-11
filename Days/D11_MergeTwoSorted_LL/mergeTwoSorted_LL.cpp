

#include <iostream>
using namespace std;

// qno 21  https://leetcode.com/problems/merge-two-sorted-lists/


// concept req: LL and Recursion



 // Definition for singly-linked list.

 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        if(head1 ==  NULL || head2 == NULL) {   //BASE-CASE
            return head1 == NULL ? head2 : head1;
        }

        //case1
        if(head1->val <= head2->val) {    //TC=O(n + m)
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;

        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
        
    }
};



// TC = O(n + m) using Recursion method 

