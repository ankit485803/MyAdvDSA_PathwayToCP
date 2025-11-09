

/*

9th Nov 2025 (Sunday - Sem5 IITP 3rd year ending semPaper)

Revising LL and do practice


qno 876  https://leetcode.com/problems/middle-of-the-linked-list/description/


876. Middle of the Linked List
Solved
Easy
Topics

Companies
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100


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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

        }
        
        return slow;  //when fast pointer reaches at end, slow pointer must be at middle
    }
};


// using Slow-Fast pointer approach, TC=o(n), SC=O(1)

 

/*

qno 2169  https://leetcode.com/problems/count-operations-to-obtain-zero/



2169. Count Operations to Obtain Zero
Attempted
Easy
Topics

Companies
Hint
You are given two non-negative integers num1 and num2.

In one operation, if num1 >= num2, you must subtract num2 from num1, otherwise subtract num1 from num2.

For example, if num1 = 5 and num2 = 4, subtract num2 from num1, thus obtaining num1 = 1 and num2 = 4. However, if num1 = 4 and num2 = 5, after one operation, num1 = 4 and num2 = 1.
Return the number of operations required to make either num1 = 0 or num2 = 0.

 

Example 1:

Input: num1 = 2, num2 = 3
Output: 3
Explanation: 
- Operation 1: num1 = 2, num2 = 3. Since num1 < num2, we subtract num1 from num2 and get num1 = 2, num2 = 3 - 2 = 1.
- Operation 2: num1 = 2, num2 = 1. Since num1 > num2, we subtract num2 from num1.
- Operation 3: num1 = 1, num2 = 1. Since num1 == num2, we subtract num2 from num1.
Now num1 = 0 and num2 = 1. Since num1 == 0, we do not need to perform any further operations.
So the total number of operations required is 3.
Example 2:

Input: num1 = 10, num2 = 10
Output: 1
Explanation: 
- Operation 1: num1 = 10, num2 = 10. Since num1 == num2, we subtract num2 from num1 and get num1 = 10 - 10 = 0.
Now num1 = 0 and num2 = 10. Since num1 == 0, we are done.
So the total number of operations required is 1.
 

Constraints:

0 <= num1, num2 <= 105 

*/


class Solution {
public:
    int countOperations(int num1, int num2) {  //TC=O(max(num1, num2)), SC=O(1)
      
        //nowPerfomOperation
        int count = 0;
        
        while(num1 > 0 && num2 > 0) {
            if(num1 >= num2) {
                num1 = num1 - num2;   //subtract from greater-smaller
                count++;

            } else {
                num2 = num2-num1;
                count++;

            }

        }

        return count;
    }
};


class Solution {
public:
    int countOperations(int num1, int num2) {  //TC=O(log(max(num1, num2))) using EuclideanAlgo
        int count = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2) 
                count += num1 / num2, num1 %= num2;
            else 
                count += num2 / num1, num2 %= num1;
        }
        return count;
    }
};