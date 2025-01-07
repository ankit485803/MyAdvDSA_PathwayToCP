


#include <iostream>
using namespace std;


// qno 876  https://leetcode.com/problems/middle-of-the-linked-list/
// easy ques

// if no of nodes in LL = EVEN, then two middle mai aata h to apko SECOND WALA ko print karna hai, ODD se case mai middle

// method1: BruteForce -- ans = (size/2  + 1)

// method2: SLOW-FAST POINTER approach to find middle of LL, this approach is also used in next topic: CYCLE-DETECTION in LL
// we use this because the only SINGLE PASS se solve kar rahe h




  //Definition for singly-linked list.

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 



class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

        }
        
        return slow;
    }
};


// using Slow-Fast pointer approach, TC=o(n), SC=O(1)


