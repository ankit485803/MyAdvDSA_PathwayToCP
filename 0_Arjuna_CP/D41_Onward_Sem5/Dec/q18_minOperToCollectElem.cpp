



/*


18th Dec 2025 (Thursday)


qno 2869   https://leetcode.com/problems/minimum-operations-to-collect-elements/description/



2869. Minimum Operations to Collect Elements
Easy
Topics

Companies
Hint
You are given an array nums of positive integers and an integer k.

In one operation, you can remove the last element of the array and add it to your collection.

Return the minimum number of operations needed to collect elements 1, 2, ..., k.

 

Example 1:

Input: nums = [3,1,5,4,2], k = 2
Output: 4
Explanation: After 4 operations, we collect elements 2, 4, 5, and 1, in this order. Our collection contains elements 1 and 2. Hence, the answer is 4.
Example 2:

Input: nums = [3,1,5,4,2], k = 5
Output: 5
Explanation: After 5 operations, we collect elements 2, 4, 5, 1, and 3, in this order. Our collection contains elements 1 through 5. Hence, the answer is 5.
Example 3:

Input: nums = [3,2,5,3,1], k = 3
Output: 4
Explanation: After 4 operations, we collect elements 1, 3, 5, and 2, in this order. Our collection contains elements 1 through 3. Hence, the answer is 4.
 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= nums.length
1 <= k <= nums.length
The input is generated such that you can collect elements 1, 2, ..., k.



*/



class Solution {  //myFirstApproach
public:
    int minOperations(vector<int>& nums, int k) {
        int n = sizeof(nums) / sizeof(nums[0]);  // Calculate no of elem

        //step1: makeReq range
        vector<int> reqRange;
        for(int i=0; i<=k; i++) {
            reqRange.push_back(i);
        }

        //step2: form collection 
        vector<int> collection;
        int countOp = 0;  //no of operation
        while(! nums.empty()) {
            int lastElem = nums[n - 1];
            collection.push_back(lastElem);
            countOp++; 
        }

        if(collection == reqRange) {
            return countOp;  
        }
    }
};






#include <unordered_set>
class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int n = nums.size();   

        unordered_set<int> reqElem;
        for (int i=1; i<=k; i++) {
            reqElem.insert(i);
        }

        unordered_set<int> collection;
        int countOp = 0;  
        
        // Iterate over the nums array in reverse (from last to first)
        for (int i=n-1; i >= 0; i--) {
            collection.insert(nums[i]);
            countOp++;
            
            // If collection contains allElem from 1 to k
            if (collection.size() == k) {
                return countOp;
            }
        }

        return countOp;   
    }
};




class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {  //tc=O(n), sc=O(k)
        int n = nums.size(); 

        vector<bool> seen(k, false);  // Boolean array to track collected elements
        int collected = 0;  
        int ops = 0;  

    
        for (int i=n-1; i>=0; i--) {
            ops++;
            
            int val = nums[i];
            
            // If the element is in the range [1, k] and hasn't been collected yet
            if (val <= k && !seen[val - 1]) {
                seen[val - 1] = true;  
                collected++;  
            }

            if (collected == k) {
                return ops;
            }
        }

        return ops;  
    }
};




