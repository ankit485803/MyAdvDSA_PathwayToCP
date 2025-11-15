



/*

15th Nov 2025 (Satursday)

qno 86   https://leetcode.com/problems/partition-list/


86. Partition List
Medium
Topics

Companies
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200


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
    ListNode* partition(ListNode* head, int x) { //TC=O(n), SC=O(1)
        
        //createTwoPointer for Partition
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* lessTail = &lessDummy;   // tail of nodes < x
        ListNode* greaterTail = &greaterDummy; // tail of nodes >= x 

        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = nullptr;

            if(curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }

            curr = nextNode;
        }


        // connectTwoPartitions
        lessTail->next = greaterDummy.next;
        greaterTail->next = nullptr;

        return lessDummy.next;
    }
};


/*

qno  2654   https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/


2654. Minimum Number of Operations to Make All Array Elements Equal to 1
Medium
Topics

Companies
Hint
You are given a 0-indexed array nums consisting of positive integers. You can do the following operation on the array any number of times:

Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

The gcd of two integers is the greatest common divisor of the two integers.

 

Example 1:

Input: nums = [2,6,3,4]
Output: 4
Explanation: We can do the following operations:
- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
Example 2:

Input: nums = [2,10,6,14]
Output: -1
Explanation: It can be shown that it is impossible to make all the elements equal to 1.
 

Constraints:

2 <= nums.length <= 50
1 <= nums[i] <= 106



*/


class Solution {
public:
    int minOperations(vector<int>& nums) {  //TC=O(n^2 * Log(max(nums))), SC=O(1)
        int n = nums.size();
        
        // Step 1: count existing 1s
        int count1 = 0;
        for (int x : nums) 
            if (x == 1) count1++;
        
        // If we already have ones
        if (count1 > 0) {
            return n - count1;  // each non-1 takes 1 operation
        }

        // Step 2: find shortest subarray with gcd = 1
        int bestLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = std::gcd(g, nums[j]);
                if (g == 1) {
                    bestLen = min(bestLen, j - i + 1);
                    break;  // no need to extend further
                }
            }
        }

        // If impossible to create a 1
        if (bestLen == INT_MAX) return -1;

        // Step 3: operations needed
        // (bestLen - 1) to create 1
        // (n - 1) to make all elements 1
        return (bestLen - 1) + (n - 1);
    }
};


/*


qno 2574  https://leetcode.com/problems/left-and-right-sum-differences/description/

2574. Left and Right Sum Differences
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums of size n.

Define two arrays leftSum and rightSum where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

 

Example 1:

Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
Example 2:

Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105


...
explain 
Step 1: Build leftSum

leftSum[i] = sum of elements before i
| i | nums[i] | leftSum[i] calculation | leftSum      |
| - | ------- | ---------------------- | ------------ |
| 0 | 10      | no left → 0            | [0]          |
| 1 | 4       | 10                     | [0,10]       |
| 2 | 8       | 10+4 = 14              | [0,10,14]    |
| 3 | 3       | 10+4+8 = 22            | [0,10,14,22] |


similar for rightSum and then findAns




*/


class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) { //TC=O(n), SC=O(1)
        int n = nums.size();

        // everyElem initialized to 0 and size n
        vector<int> left(n, 0), right(n, 0), ans(n);

        //build leftSum
        for(int i=1; i<n; i++) {
            left[i] = left[i-1] + nums[i-1];
        }

        //build rightSum
        for(int i=n-2; i>=0; i--) {
            right[i] = right[i+1] + nums[i+1];
        }


        //final ans build
        for(int i=0; i<n; i++) {
            ans[i] = abs(left[i] - right[i]);
        }

        return ans;
    }
};


/*

qno 1991   https://leetcode.com/problems/find-the-middle-index-in-array/description/



1991. Find the Middle Index in Array
Easy
Topics

Companies
Hint
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

 

Example 1:

Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4
Example 2:

Input: nums = [1,-1,4]
Output: 2
Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0
Example 3:

Input: nums = [2,5]
Output: -1
Explanation: There is no valid middleIndex.
 

Constraints:

1 <= nums.length <= 100
-1000 <= nums[i] <= 1000
 

Note: This question is the same as 724: https://leetcode.com/problems/find-pivot-index/


*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftSideSum(n, 0), rightSideSum(n, 0);

        // Build leftSideSum
        for (int i = 1; i < n; i++) {
            leftSideSum[i] = leftSideSum[i - 1] + nums[i - 1];
        }

        // Build rightSideSum
        for (int i = n - 2; i >= 0; i--) {
            rightSideSum[i] = rightSideSum[i + 1] + nums[i + 1];
        }

        // Find middle index
        for (int i = 0; i < n; i++) {
            if (leftSideSum[i] == rightSideSum[i]) {
                return i;
            }
        }

        return -1;
    }
};




class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = total - leftSum - nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }

        return -1;
    }
};


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {  //TC =O(n) = SC
        int n = nums.size();

        // prefix-Suffix method

        vector<int> leftSideSum(n, 0), rightSideSum(n, 0);

        //build LeftSS
        for(int i=1; i<n; ++i) {
            leftSideSum[i] = leftSideSum[i-1] + nums[i-1];
        }

        //buil rightSS
        for(int i=n-2; i>=0; --i) {  //from backward
            rightSideSum[i] = rightSideSum[i+1] + nums[i+1];
        }


        //find middleIdx
        for(int i=0; i<n; ++i) {
            if(leftSideSum[i] == rightSideSum[i]) return i;
        }

        return -1;    

    }
};


class Solution {
public:
    int findMiddleIndex(vector<int>& nums) { //TC=O(n), SC=O(1)
        int total = 0;

        for(int v : nums) total += v;
        
        int left = 0;
        for(int i=0; i<nums.size(); ++i) {
            int right = total - left - nums[i];
            if(left == right) return i; 
            left += nums[i];
        }
        return -1;
    }
};




/*


qno 724  https://leetcode.com/problems/find-pivot-index/description/

724. Find Pivot Index
Solved
Easy
Topics

Companies
Hint
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
 

Constraints:

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
 

Note: This question is the same as 1991: https://leetcode.com/problems/find-the-middle-index-in-array/



*/


class Solution {
public:
    int pivotIndex(vector<int>& nums) {  //TC=O(n), SC=O(1)
        //solved using One-Pass Prefix + Total Sum Method
        
        int total = 0;
        for(int v : nums) total += v;

        int left = 0;
        for(int i=0; i<nums.size(); ++i) {
            int right = total - left - nums[i];
            if(left == right) return i;
            left += nums[i];
        }
        return -1;
    }
};
