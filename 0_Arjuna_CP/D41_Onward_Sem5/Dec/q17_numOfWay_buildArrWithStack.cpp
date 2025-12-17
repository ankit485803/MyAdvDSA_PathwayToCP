



/*



17th Dec 2025 (Wednesday)


qno 2348   https://leetcode.com/problems/number-of-zero-filled-subarrays/description/



2348. Number of Zero-Filled Subarrays
Medium
Topics

Companies
Hint
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109



*/


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {  //tc=O(n), sc=O(1)
        long long total = 0;
        long long count = 0;

        for (int num : nums) {
            if (num == 0) {
                count++;  // Increment count for consecutive zeros
                total += count;  // Add the count of subarrays formed by the current block of zeros
            } else {
                count = 0;  // Reset count when a non-zero element is encountered
            }
        }

        return total;
    }
};



/*


qno 713  https://leetcode.com/problems/subarray-product-less-than-k/description/



713. Subarray Product Less Than K
Medium
Topics

Companies
Hint
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106


*/


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // If k is 0 or 1,  edgeCase

        int i = 0, ans = 0;
        long long prod = 1;

        for (int j = 0; j < nums.size(); j++) {
            prod *= nums[j];  

            // Shrink the window until the product is less than k.
            while (prod >= k) {
                prod /= nums[i];
                i++;
            }

            // Count the number of subarrays ending at j.
            ans += j - i + 1;
        }

        return ans;
    }
};





/*


qno 1441  https://leetcode.com/problems/build-an-array-with-stack-operations/


1441. Build an Array With Stack Operations
Medium
Topics

Companies
Hint
You are given an integer array target and an integer n.

You have an empty stack with the two following operations:

"Push": pushes an integer to the top of the stack.
"Pop": removes the integer on the top of the stack.
You also have a stream of the integers in the range [1, n].

Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to target. You should follow the following rules:

If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
If the stack is not empty, pop the integer at the top of the stack.
If, at any moment, the elements in the stack (from the bottom to the top) are equal to target, do not read new integers from the stream and do not do more operations on the stack.
Return the stack operations needed to build target following the mentioned rules. If there are multiple valid answers, return any of them.

 

Example 1:

Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Pop the integer on the top of the stack. s = [1].
Read 3 from the stream and push it to the stack. s = [1,3].
Example 2:

Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Read 3 from the stream and push it to the stack. s = [1,2,3].
Example 3:

Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Since the stack (from the bottom to the top) is equal to target, we stop the stack operations.
The answers that read integer 3 from the stream are not accepted.
 

Constraints:

1 <= target.length <= 100
1 <= n <= 100
1 <= target[i] <= n
target is strictly increasing.




*/



class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {  //tc=O(n), sc=O(1)
        vector<string> result; 
        int targetIdx = 0;  

        for (int i = 1; i <= n; ++i) {
            result.push_back("Push");
            

            if (i == target[targetIdx]) {
                targetIdx++;  
            } else {
                result.push_back("Pop");
            }
            
            // If we have processed all elements in the target, stop
            if (targetIdx == target.size()) break;
        }
        return result;
    }
};
