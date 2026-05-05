

/*

5th May 2026 (Tuesday)
https://leetcode.com/contest/weekly-contest-500/problems/count-indices-with-opposite-parity/
qno 3917  https://leetcode.com/problems/count-indices-with-opposite-parity/

Code


Testcase
Testcase
Test Result
3917. Count Indices With Opposite Parity
Easy

Companies
Hint
You are given an integer array nums of length n.

The score of an index i is defined as the number of indices j such that:

i < j < n, and
nums[i] and nums[j] have different parity (one is even and the other is odd).
Return an integer array answer of length n, where answer[i] is the score of index i.

 

Example 1:

Input: nums = [1,2,3,4]

Output: [2,1,1,0]

Explanation:

nums[0] = 1, which is odd. Thus, the indices j = 1 and j = 3 satisfy the conditions, so the score of index 0 is 2.
nums[1] = 2, which is even. Thus, the index j = 2 satisfies the conditions, so the score of index 1 is 1.
nums[2] = 3, which is odd. Thus, the index j = 3 satisfies the conditions, so the score of index 2 is 1.
nums[3] = 4, which is even. Thus, no index satisfies the conditions, so the score of index 3 is 0.
Thus, the answer = [2, 1, 1, 0].

Example 2:

Input: nums = [1]

Output: [0]

Explanation:

There is only one element in nums. Thus, the score of index 0 is 0.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
30,849/37.9K
Acceptance Rate
81.4%
Topics
Mid Level
Weekly Contest 500


approach:
If nums[i] is even → count how many odd numbers are to its right
If nums[i] is odd → count how many even numbers are to its right



*/


class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {  //tc=O(n^2) using evenCount, oddCount
        int n = nums.size();
        vector<int> ans(n, 0); //sc=O(n)

        for(int i=0; i<n; i++) {
            int count = 0; 
            for(int j = i+1; j<n; j++) {
                if(nums[i] % 2 != nums[j] % 2) {
                    count++;
                }
            }
            ans[i] = count;
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {  //optimized tc=O(n)=sc
        int n = nums.size();
        int even = 0, odd = 0;

        // Count total evens and odds
        for(int x : nums) {
            if(x % 2 == 0) even++;
            else odd++;
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            // Remove current element from future consideration
            if(nums[i] % 2 == 0) even--;
            else odd--;

            // Assign answer based on opposite parity
            if(nums[i] % 2 == 0)
                ans[i] = odd;
            else
                ans[i] = even;
        }

        return ans;
    }
};




/*

qno  61  https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05

already submitted on 20th Nov 2025


61. Rotate List
Solved
Medium
Topics

Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
1,654,651/3.9M
Acceptance Rate
42.0%
Topics
Linked List
Two Pointers

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
    ListNode* rotateRight(ListNode* head, int k) {  //TC=O(n), SC=O(1)

        if (!head || !head->next || k == 0) return head; // Edge cases
        
        //step1: find lengthLL
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        //step2: Reduce k to avoid unnecessary rotations
        k = k % length;
        if (k == 0) return head;  // If k is a multiple of length, no rotation needed
        

        //step3: Find the new tail (n-k-1) and new head (n-k)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        
        //step4: rotateList
        newTail->next = nullptr; // Break the list
        temp->next = head; // Connect the old tail to the old head
        
        return newHead;
    }
};
