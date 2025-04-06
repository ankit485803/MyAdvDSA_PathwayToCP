

#include <iostream>
using namespace std;


// qno 430   https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/



 
// Definition for a Node


class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        
        if(head == NULL) {
            return head;

        }

        Node* curr = head;
        while(curr != NULL) {
            if(curr-> child  != NULL) {

                //three Steps
                //step1: Flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                //step2: Find tail
                while(curr->next  !=  NULL) {
                    curr = curr->next;
                }


                //step3: Attach tail with next pointer
                if(next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                } 



            }

            curr = curr->next;

        }

        return head;
    }
};

// TC = O(n), SC = O(1)