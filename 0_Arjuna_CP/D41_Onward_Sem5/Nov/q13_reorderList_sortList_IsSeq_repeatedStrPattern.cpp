



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


148. Sort List
Medium
Topics

Companies
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

Accepted
1,168,683/1.8M
Acceptance Rate
63.2%
Topics
Linked List
Two Pointers
Divide and Conquer
Sorting
Merge Sort


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
    // Main function to sort the list
    ListNode* sortList(ListNode* head) {  //O(n logN)=SC
        // Base case: If the list has 0 or 1 element, it's already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Step 1: Find the middle of the list
        ListNode* mid = getMid(head);

        // Step 2: Divide the list into two parts
        ListNode* rightHead = mid->next;
        mid->next = nullptr; // Disconnect the left and right parts

        // Step 3: Recursively sort the left and right parts
        ListNode* newLeft = sortList(head);
        ListNode* newRight = sortList(rightHead);

        // Step 4: Merge the sorted left and right parts
        return merge(newLeft, newRight);
    }

private:
    // Helper function to find the middle of the list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move slow by one step and fast by two steps until fast reaches the end
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // slow will be at the middle
    }

    // Helper function to merge two sorted lists
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummy(-1); // Dummy node to simplify the merge process
        ListNode* temp = &dummy;

        // Merge the two sorted lists
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                temp->next = head1;
                head1 = head1->next;
            } else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next; // Move temp to the last node in the merged list
        }

        // Attach any remaining nodes
        if (head1 != nullptr) {
            temp->next = head1;
        } else {
            temp->next = head2;
        }

        return dummy.next; // Return the merged list, skipping the dummy node
    }
};



/*

qno 392  https://leetcode.com/problems/is-subsequence/description/

392. Is Subsequence
Solved
Easy
Topics

Companies
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,293,434/4.7M
Acceptance Rate
48.7%
Topics
Two Pointers
String
Dynamic Programming



*/


class Solution {
public:
    bool isSubsequence(string s, string t) {  //O(n + m), SC=O(1)
        int n = s.length(), m = t.length();

        //twoPointer
        int i=0, j=0;
        while(i<n && j<m) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i==n;  //true if i==n, else false
    }
};




/*

qno 459  https://leetcode.com/problems/repeated-substring-pattern/description/


459. Repeated Substring Pattern
Easy
Topics

Companies
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.


Approach:

1. Length Property:
    If a string s can be formed by repeating a substring p, then the length of s must be divisible by the length of p.
    We need to check all possible substring lengths l that divide the length of s.

2. Concatenate Trick:
    A neat trick to check if a string is formed by repeating a substring is to:
    Concatenate s to itself, forming a string s + s.
    Remove the first and the last character from this new string (because the full string s would match itself in the middle of s + s).



If s appears in this modified string, then s is indeed a repeated substring.
This works because, if s is repeated multiple times, it will show up again within the concatenated string (excluding the first and last positions).

Efficient Check:
    If we can find s inside s + s (excluding the first and last character), then s is a repeated substring. This reduces the problem to a simple substring search.


    
*/

