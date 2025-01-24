
#include <iostream>
using namespace std;




// qno 25   https://leetcode.com/problems/reverse-nodes-in-k-group/description/



 
 //Definition for singly-linked list



 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        int cnt = 0;  //count

        //check if k  nodes exist
        while(cnt < k) {
            if(temp == NULL) {
                return head;
            }

            temp = temp->next;
            cnt++;
        }

        //recursively call for rest of LL
        ListNode* prevNode = reverseKGroup(temp, k);


        //reverse current group
        temp = head; cnt  = 0;

        while(cnt < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;

            cnt++;
        }

        return prevNode;
    }
};