

/*

14th June 2026 (Sunday)

qno 2130  https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14

2130. Maximum Twin Sum of a Linked List
Solved
Medium
Topics

Companies
Hint
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

Example 1:


Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
Example 2:


Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
Example 3:


Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
 

Constraints:

The number of nodes in the list is an even integer in the range [2, 105].
1 <= Node.val <= 105
 
Discover more
Online Coding Platform
Seen this question in a real interview before?
1/6
Yes
No
Accepted
541,180/658.1K
Acceptance Rate
82.2%
Topics
Senior
Linked List
Two Pointers
Stack
Biweekly Contest 69

*/

//Approach-1 (Using vector/array)
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        
        while(head) {
            vec.push_back(head->val);
            head = head->next;
        }
        
        int i = 0, j = vec.size()-1;
        int result = 0;
        
        while(i < j) {
            result = max(result, vec[i] + vec[j]);
            i++;
            j--;
        }
        
        return result;
    }
};

//Approach-2 (Using Stack)
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        
        while(curr) {
            st.push(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        int count = 1;
        int N = st.size();
        int result = 0;
        
        while(count <= N/2) {
            result = max(result, curr->val + st.top());
            curr = curr->next;
            st.pop();
            count++;
        }
        
        return result;
    }
};


//Approach-3 (Reversing the second half of the linkedlist)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* mid = NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow;
        
        //Reversing Part
        ListNode* nextNode = NULL;
        ListNode* prev = NULL;
        while(mid) {
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }
        //Reversing Part
        
        ListNode* curr = head;
        int result = 0;
        while(prev) {
            result = max(result, curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        
        return result;
        
    }
};