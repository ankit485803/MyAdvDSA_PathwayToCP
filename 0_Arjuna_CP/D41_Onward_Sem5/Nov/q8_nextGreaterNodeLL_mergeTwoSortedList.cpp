

/*

16th Nov 2025 (Sunday)


qno 1019   https://leetcode.com/problems/next-greater-node-in-linked-list/


1019. Next Greater Node In Linked List
Medium
Topics

Companies
Hint
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109




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
    vector<int> nextLargerNodes(ListNode* head) {  //TC=O(n)=SC
        vector<int> values;
        ListNode* temp = head;

        //step1: traverse list and store values 
        while(temp != nullptr) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> result(values.size(), 0);
        stack<int> stk;   //SC=O(n)

        //step2: traverse vector to find nextGreaterElem using stack
        for(int i=0; i<values.size(); ++i) {
            while(!stk.empty()  &&  values[i] > values[stk.top()]) {
                result[stk.top()] = values[i];
                stk.pop();
            }
            
            stk.push(i);  // Push current index onto the stack
        }

        return result;
    }
};



/*

qno 3467   https://leetcode.com/problems/transform-array-by-parity/


3467. Transform Array by Parity
Easy
Topics

Companies
Hint
You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:

Replace each even number with 0.
Replace each odd numbers with 1.
Sort the modified array in non-decreasing order.
Return the resulting array after performing these operations.

 

Example 1:

Input: nums = [4,3,2,1]

Output: [0,0,1,1]

Explanation:

Replace the even numbers (4 and 2) with 0 and the odd numbers (3 and 1) with 1. Now, nums = [0, 1, 0, 1].
After sorting nums in non-descending order, nums = [0, 0, 1, 1].
Example 2:

Input: nums = [1,5,1,4,2]

Output: [0,0,1,1,1]

Explanation:

Replace the even numbers (4 and 2) with 0 and the odd numbers (1, 5 and 1) with 1. Now, nums = [1, 1, 1, 0, 0].
After sorting nums in non-descending order, nums = [0, 0, 1, 1, 1].
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 1000


*/


class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {  //TC=O(n)=SC

        vector<int> ans;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] % 2 == 0) {
                ans.push_back(0);  // Store 0 for even numbers
            } else {
                ans.push_back(1);  // Store 1 for odd numbers
            }
        }

        // Sort the result in non-decreasing order
        sort(ans.begin(), ans.end());

        return ans;
    }
};




/*

qno 328  https://leetcode.com/problems/odd-even-linked-list/description/


328. Odd Even Linked List
Medium
Topics

Companies
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106


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
    ListNode* oddEvenList(ListNode* head) { 
        
        if(!head || !head->next) return head;  //edgeCase: EMPTY or singleNode List

        ListNode* odd = head;  //firstNode (ODD)
        ListNode* even = head->next;  //secondNode (EVEN)
        ListNode* evenHead = even;  // // Keep track of the head of even list

        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;

            //connect lastOddNode to head of evenList
            odd->next = evenHead;

        }

        return head;
    }
};



/*

qno 21   https://leetcode.com/problems/merge-two-sorted-lists/description/


21. Merge Two Sorted Lists
Solved
Easy
Topics

Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.


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


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {  //iterativeMethod TC=O(n + m), SC=O(1)
        // Create a dummy node and a pointer 'current' to build the new merged list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        

        // Traverse both lists while both are not empty
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                current->next = head1;  // Append head1 to the merged list
                head1 = head1->next;      
            } else {
                current->next = head2;   
                head2 = head2->next;      
            }
            current = current->next;    
        }
        
 
        if (head1 != nullptr) {
            current->next = head1;
        } else {
            current->next = head2;
        }
        
        // Return the merged list, starting from dummy->next
        return dummy->next;
    }
};



/*

qno 137  https://leetcode.com/problems/single-number-ii/


137. Single Number II
Medium
Topics

Companies
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
 
Discover more
Software development tools
Seen this question in a real interview before?
1/5
Yes
No
Accepted
815,730/1.2M
Acceptance Rate
66.2%
Topics
Array
Bit Manipulation


*/

class Solution {
public:
    int singleNumber(vector<int>& nums) { //TC=O(n), SC=O(1)
        int ones = 0, twos = 0;
        
        for (int num : nums) {
            // `twos` will store the bits that appeared twice.
            twos |= ones & num;
            
            // `ones` will store the bits that appeared once.
            ones ^= num;

            
            // If a bit appears three times, clear it from both `ones` and `twos`
            int threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        
        return ones;  
    }
};


#include <vector>
#include <algorithm>

class Solution {
public:
    int singleNumber(vector<int>& nums) { //TC=O(n logN), SC=O(1)
        sort(nums.begin(), nums.end());
        

        for (int i = 0; i < nums.size(); i++) {
            // Check if we are at the start or middle of a triplet
            if (i == 0 || nums[i] != nums[i-1]) {
                // If the current number is not equal to the previous one, it is the unique one

                if (i == nums.size() - 1 || nums[i] != nums[i+1]) {
                    return nums[i];
                }
            }
        }
        

        return -1; 

    }
};


/*

qno 3158   https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/

3158. Find the XOR of Numbers Which Appear Twice
Easy
Topics

Companies
Hint
You are given an array nums, where each number in the array appears either once or twice.

Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.

 

Example 1:

Input: nums = [1,2,1,3]

Output: 1

Explanation:

The only number that appears twice in nums is 1.

Example 2:

Input: nums = [1,2,3]

Output: 0

Explanation:

No number appears twice in nums.

Example 3:

Input: nums = [1,2,2,1]

Output: 3

Explanation:

Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.

 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
Each number in nums appears either once or twice.
 
Discover more
Programming language reference cards
Seen this question in a real interview before?
1/5
Yes
No
Accepted
69,704/89K
Acceptance Rate
78.3%
Topics
Array
Hash Table
Bit Manipulation
Biweekly Contest 131


*/

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) { //TC=O(n logN), SC=O(1)
        
        sort(nums.begin(), nums.end());
        int ans = 0;

        for(int i=0; i<nums.size()-1; i++) {
            // Check if the current number is the same as the next one (duplicate)
            if(nums[i] == nums[i+1]) {
                ans ^= nums[i];  // XOR the duplicateNo
                i++;  // Skip the nextElem since it's a duplicate
            }
        }

        return ans;
    }
};




/*

qno  260  https://leetcode.com/problems/single-number-iii/description/

260. Single Number III
Medium
Topics

Companies
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.


*/