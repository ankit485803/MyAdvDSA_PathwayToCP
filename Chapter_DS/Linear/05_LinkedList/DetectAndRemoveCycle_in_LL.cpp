

#include <iostream>
using namespace std;


// qno 141   https://leetcode.com/problems/linked-list-cycle/



 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast-> next != NULL) {
            slow = slow-> next;
            fast = fast-> next-> next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
        
    }
};


// using two pointer = Slow-Fast pointer approach 





//  Qno 142  https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                isCycle = true;
                break;
            }

        }

        if(! isCycle) {
            return NULL;
        }

        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }


        //pre->next = NULL  //for removing cycle
        return slow;
    }
};


// using Slow-Fast pointer approach
// mathematical proof:  x = (k-1)d + (d-y)