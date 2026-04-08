

/*


8th April 2026 (Wednesday)


qno 3653  https://leetcode.com/problems/xor-after-range-multiplication-queries-i/?envType=daily-question&envId=2026-04-08


3653. XOR After Range Multiplication Queries I
Solved
Medium
Topics

Companies
Hint
You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

For each query, you must apply the following operations in order:

Set idx = li.
While idx <= ri:
Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
Set idx += ki.
Return the bitwise XOR of all elements in nums after processing all queries.

 

Example 1:

Input: nums = [1,1,1], queries = [[0,2,1,4]]

Output: 4

Explanation:

A single query [0, 2, 1, 4] multiplies every element from index 0 through index 2 by 4.
The array changes from [1, 1, 1] to [4, 4, 4].
The XOR of all elements is 4 ^ 4 ^ 4 = 4.
Example 2:

Input: nums = [2,3,1,5,4], queries = [[1,4,2,3],[0,2,1,2]]

Output: 31

Explanation:

The first query [1, 4, 2, 3] multiplies the elements at indices 1 and 3 by 3, transforming the array to [2, 9, 1, 15, 4].
The second query [0, 2, 1, 2] multiplies the elements at indices 0, 1, and 2 by 2, resulting in [4, 18, 2, 15, 4].
Finally, the XOR of all elements is 4 ^ 18 ^ 2 ^ 15 ^ 4 = 31.​​​​​​​​​​​​​​
 

Constraints:

1 <= n == nums.length <= 103
1 <= nums[i] <= 109
1 <= q == queries.length <= 103
queries[i] = [li, ri, ki, vi]
0 <= li <= ri < n
1 <= ki <= n
1 <= vi <= 105
 
Discover more
Programming Project Templates
Seen this question in a real interview before?
1/5
Yes
No
Accepted
79,657/109K
Acceptance Rate
73.1%
Topics
Senior
Array
Divide and Conquer
Simulation
Weekly Contest 463


*/


class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7; // modulus to avoid overflow during multiplication

        // Process each query one by one
        for (auto &q : queries) {
            int li = q[0]; // left index of range
            int ri = q[1]; // right index of range
            int ki = q[2]; // step size
            int vi = q[3]; // multiplier value

            // Update every ki-th index in range [li, ri]
            for (int idx = li; idx <= ri; idx += ki) {
                // Use 1LL to promote to long long before multiplication
                nums[idx] = (1LL * nums[idx] * vi) % MOD;
            }
        }

        // After applying all queries, calculate XOR of entire array
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};



// TC=O(n * query), SC=O(1) 



class Solution {
public:
    int M = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) { //tc=O(q * n) because smallConstaint 1000
    
        for(auto &query : queries) { //O(query)
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];

            while(l <= r) {  //O(n)
                nums[l] = (1LL * nums[l] * v) % M;
                l += k;
            }
        }

        int result = 0;
        for(int &num : nums) {
            result ^= num;
        }

        return result;
    }
};