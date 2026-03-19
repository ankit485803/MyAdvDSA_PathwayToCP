


/*


18th March 2026 (Wednesdaty)


qno 3070  https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/?envType=daily-question&envId=2026-03-18


3070. Count Submatrices with Top-Left Element and Sum Less Than k
Medium
Topics

Companies
You are given a 0-indexed integer matrix grid and an integer k.

Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

 

Example 1:


Input: grid = [[7,6,3],[6,6,1]], k = 18
Output: 4
Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
Example 2:


Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
Output: 6
Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
 

Constraints:

m == grid.length 
n == grid[i].length
1 <= n, m <= 1000 
0 <= grid[i][j] <= 1000
1 <= k <= 109
 
Discover more
Coding bootcamps
Seen this question in a real interview before?
1/5
Yes
No
Accepted
34,250/57K
Acceptance Rate
60.0%
Topics
Senior
Array
Matrix
Prefix Sum
Weekly Contest 387



*/



class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {  //tc=O(m^2 * n^2) bruteForce but give TLE, sc=O(1)
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;

        // Fix bottom-right corner (i, j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long sum = 0;

                // Compute sum of submatrix from (0,0) to (i,j)   This brute-force recomputes the sum every time
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        sum += grid[x][y];
                    }
                }

                // Check condition
                if (sum <= k) {
                    count++;
                }
            }
        }

        return count;
    }
};



class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {  //tc=O(m*n), sc=O(1)
    //prefix[i][j] = sum of rectangle from (0,0) to (i,j)
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> prefix(m, vector<long long>(n, 0) );
        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                prefix[i][j] = grid[i][j];

                if(i>0) prefix[i][j] += prefix[i-1][j];
                if(j>0) prefix[i][j] += prefix[i][j-1];
                if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];

                if(prefix[i][j] <= k) count++;
            }
        }

        return count;
    }
};



//Approach-1 (Brute Force)
//T.C : O(m^2 * n^2)
//S.C : O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        // Fix the bottom-right corner at (i, j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Sum from (0,0) to (i,j)
                int sum = 0;
                for (int m1 = 0; m1 <= i; m1++) {
                    for (int n1 = 0; n1 <= j; n1++) {
                        sum += grid[m1][n1];
                    }
                }

                if (sum <= k) count++;
            }
        }

        return count;
    }
};



//Approach-2 (Using precomputed results)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if (i > 0) 
                  grid[i][j] += grid[i - 1][j];
                if (j > 0) 
                  grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0) 
                  grid[i][j] -= grid[i - 1][j - 1];
                
                if(grid[i][j] <= k)
                    count++;
                else 
                    break;
            }
        }

        return count;
    }
};




/*


qno 3868  https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/


3868. Minimum Cost to Equalize Arrays Using Swaps
Medium
Topics

Companies
Hint
You are given two integer arrays nums1 and nums2 of size n.

You can perform the following two operations any number of times on these two arrays:

Swap within the same array: Choose two indices i and j. Then, choose either to swap nums1[i] and nums1[j], or nums2[i] and nums2[j]. This operation is free of charge.
Swap between two arrays: Choose an index i. Then, swap nums1[i] and nums2[i]. This operation incurs a cost of 1.
Return an integer denoting the minimum cost to make nums1 and nums2 identical. If this is not possible, return -1.

 

Example 1:

Input: nums1 = [10,20], nums2 = [20,10]

Output: 0

Explanation:

Swap nums2[0] = 20 and nums2[1] = 10.
nums2 becomes [10, 20].
This operation is free of charge.
nums1 and nums2 are now identical. The cost is 0.
Example 2:

Input: nums1 = [10,10], nums2 = [20,20]

Output: 1

Explanation:

Swap nums1[0] = 10 and nums2[0] = 20.
nums1 becomes [20, 10].
nums2 becomes [10, 20].
This operation costs 1.
Swap nums2[0] = 10 and nums2[1] = 20.
nums2 becomes [20, 10].
This operation is free of charge.
nums1 and nums2 are now identical. The cost is 1.
Example 3:

Input: nums1 = [10,20], nums2 = [30,40]

Output: -1

Explanation:

It is impossible to make the two arrays identical. Therefore, the answer is -1.

 

Constraints:

2 <= n == nums1.length == nums2.length <= 8 * 104
1 <= nums1[i], nums2[i] <= 8 * 104
 
Discover more
Computer programming
Seen this question in a real interview before?
1/5
Yes
No
Accepted
21,237/44.5K
Acceptance Rate
47.7%
Topics
Senior
Array
Hash Table
Greedy
Counting
Biweekly Contest 178


*/



class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {  
        //twoPointerApproach

        int cost = -1;
        //case1: swap wihtin sameArr cost=0


        //case2: swap b/w twoArr, cost++

    }
};


Your intuition is partially right, but not complete enough to solve this problem correctly.

❌ Where your idea falls short

You wrote:

// case1: swap within sameArr cost=0
// case2: swap b/w twoArr, cost++

That’s true, but the core difficulty is:
👉 When do we need cross swaps?
👉 How many minimum swaps are required?

This is not a two-pointer problem.



/* pseudocode


1. Create freq map for all elements

2. Count frequency in nums1 and nums2

3. For each element:
       total = freq1[x] + freq2[x]
       if total is odd → return -1

4. Count mismatches:
       For each element:
           diff = abs(freq1[x] - freq2[x])
           add diff to total_diff

5. return total_diff / 4




🤯 Why /4 ?

diff counts extra elements
Each swap fixes 2 elements in nums1 and 2 in nums2
👉 So divide by 4


cost = total extra elements in nums1 / 2

*/


class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {  
        // tc = O(n), sc = O(n)

        unordered_map<int, int> freq1, freq2;

        // count frequencies
        for (int x : nums1) freq1[x]++;
        for (int x : nums2) freq2[x]++;

        int totalDiff = 0;

        // check feasibility + count differences
        unordered_set<int> keys;
        for (auto &p : freq1) keys.insert(p.first);
        for (auto &p : freq2) keys.insert(p.first);

        for (int x : keys) {
            int f1 = freq1[x];
            int f2 = freq2[x];

            // if total frequency is odd → impossible
            if ((f1 + f2) % 2 != 0) return -1;

            // count extra elements in nums1
            if (f1 > f2) {
                totalDiff += (f1 - f2);
            }
        }

        // each swap fixes 2 elements
        return totalDiff / 2;
    }
};