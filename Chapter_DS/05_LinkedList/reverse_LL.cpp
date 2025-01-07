

#include <iostream>
using namespace std;




// qno 206   https://leetcode.com/problems/reverse-linked-list/
// easy question




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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
        
    }
};


// using three-pointer approach, TC=O(n), SC=O(1)





