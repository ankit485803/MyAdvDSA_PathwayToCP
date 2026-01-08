



/*

21st Oct 2025 (Tuesday ) 


qno 2011  https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/


2011. Final Value of Variable After Performing Operations
Solved
Easy
Topics

Companies
Hint
There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

 

Example 1:

Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
Example 2:

Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
Example 3:

Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
 

Constraints:

1 <= operations.length <= 100
operations[i] will be either "++X", "X++", "--X", or "X--".


*/


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) { //TC=O(n), sc=O(1)
        
        //initilize
        int X = 0;

        for(const string& op : operations) {
            //increments
            if(op == "++X"  ||  op == "X++") {
                X++;  //inc by 1
            } else if(op == "--X" ||  op == "X--") {
                X--;   //dec by 1
            }
        }

        return X;
    }
};



/*

qno 1287  https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/


1287. Element Appearing More Than 25% In Sorted Array
Easy
Topics

Companies
Hint
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105




*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {  //TC=O(n)  , SC=O(1)
        int n = arr.size();
        int count = 1;  // freqCounter

        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                count++;  //incrCount if curr=prev

                if (count > n / 4) {  //for 25%
                    return arr[i];
                }
            } else {
                count = 1; // reset count for new number
            }
        }

        // Since the problem guarantees one element > 25%, we don't need a return outside loop.
        return arr[0]; // Fallback, though it will never be reached due to constraints.
    }
};



/*

qno  3346  https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/?envType=daily-question&envId=2025-10-21


3346. Maximum Frequency of an Element After Performing Operations I
Medium
Topics

Companies
Hint
You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing the operations.

 

Example 1:

Input: nums = [1,4,5], k = 1, numOperations = 2

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1]. nums becomes [1, 4, 5].
Adding -1 to nums[2]. nums becomes [1, 4, 4].
Example 2:

Input: nums = [5,11,20,20], k = 5, numOperations = 1

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
0 <= k <= 105
0 <= numOperations <= nums.length

*/


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {  //TC=O(nLogN), sc=O(n)

        sort(nums.begin(), nums.end());
        long long total = 0;  // Sum of the  currWindow
        int left = 0;
        int result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];

            // Calculate cost: make all elements in [left, right] equal to nums[right]
            long long cost = (long long)nums[right] (right - left + 1) - total;

            // Each element can only be adjusted by [-k, k], and only numOperations elements can be changed
            if ((right - left + 1) > numOperations) {
                cost = min(cost, (long long)k numOperations);
            }

            if (cost > (long long)k numOperations) {
                total -= nums[left];
                left++;
            }

            result = max(result, right - left + 1);
        }

//         return result;
//     }
// };



class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];
            long long cost = (long long)nums[right] (right - left + 1) - total;
            
            while (cost > (long long)numOperations k) {
                total -= nums[left];
                left++;
                cost = (long long)nums[right] (right - left + 1) - total;
            }
            
            result = max(result, right - left + 1);
        }

        return result;
    }
};


/*

qno 2   https://leetcode.com/problems/add-two-numbers/description/

. Add Two Numbers
Medium
Topics

Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
6,327,906/13.4M
Acceptance Rate
47.2%
Topics
Linked List
Math
Recursion

*/



 Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
 };
 


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);  // dummy node to simplify code
        ListNode* current = dummy;          // pointer to construct the result list
        int carry = 0;                      // to keep track of carry-over
        

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // start with carry from previous operation
            

            // If l1 is not null, add its value to sum
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;  // move to the next node in l1
            }
            
            // If l2 is not null, add its value to sum
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;  // move to the next node in l2
            }
            
            // Update carry for the next addition (sum / 10 gives the carry)
            carry = sum / 10;
            
            // Create a new node with the digit (sum % 10)
            current->next = new ListNode(sum % 10);
            current = current->next;  // move to the new node
        }
        
        return dummy->next;  // the result starts from dummy->next
    }
};


//TC=(max(n, m)) = sc