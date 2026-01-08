

/*


5th Oct 2025 (Sunday) weekly contest 470  C:\Users\sanja\Desktop\GitProj\MyAdvDSA_PathwayToCP\01_LeetCode\WeeklyContest\wc_470\q1_ComputeAlternativeSum.cpp





6th Oct 2025 (Monday)
qno 2357    https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/


no of operations will be equal to the number of distinct positive no and zero not affect




2357. Make Array Zero by Subtracting Equal Amounts
Easy
Topics

Companies
Hint
You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.

 



Example 1:
Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].


Example 2:
Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.
 

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 100



*/


//mini Elem in arr
#include <algorithm> // Required for std::min_element


int main() {
    std::vector<int> arr = {5, 2, 8, 1, 9, 3};

    // Find an iterator to the smallest element
    auto min_it = std::min_element(arr.begin(), arr.end());

    // Dereference the iterator to get the value
    int smallest_element = *min_it;

    std::cout << "Smallest element: " << smallest_element << std::endl;

    
    return 0;
}


//using Iterative 
#include <limits> // Required for std::numeric_limits

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min_val = std::numeric_limits<int>::max(); 

    
    
    for (int i = 0; i < n; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    std::cout << "Smallest element: " << min_val << std::endl;

    return 0;
}


/*

solution using set

*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {  // using set - TC=O(n) = sc

        set<int> distinctPositives;
        
        // Insert all positive numbers into the set (automatically removes duplicates)
        for (int num : nums) {
            if (num > 0) {
                distinctPositives.insert(num);
            }
        }
        
        // The number of distinct positive numbers is the number of operations needed
        return distinctPositives.size();
    }
};




class Solution {
public:
    int minimumOperations(vector<int>& nums) {  //TC=O(n LogN, sc=O(1))
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Count distinct positive numbers
        int operations = 0;
        int lastSeen = 0; // last seen positive number

        for (int num : nums) {
            // Only consider positive numbers and make sure it's distinct
            if (num > 0 && num != lastSeen) {
                operations++;
                lastSeen = num;  // Update last seen to the current number
            }
        }

        return operations;
    }
};


