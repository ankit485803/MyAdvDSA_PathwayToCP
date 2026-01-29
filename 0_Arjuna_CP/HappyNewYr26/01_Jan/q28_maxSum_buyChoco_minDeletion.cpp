
nums.erase(nums.begin() + index);  //delete elem at i index  tc=O(n), sc=O(1)
int mx = *max_element(nums.begin(), nums.end());   //maxElem find  tc=O(n), sc=O(1)
sort(nums.begin(), nums.end());   //sortArr using c++ STL  tc=O(nLogN), sc=O(logN) due to recurssive Quick + Heap + Insertion sort




/*


28th Jan 2026 (Wednesday)


qno 2656   https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/


2656. Maximum Sum With Exactly K Elements 
Easy
Topics

Companies
You are given a 0-indexed integer array nums and an integer k. Your task is to perform the following operation exactly k times in order to maximize your score:

Select an element m from nums.
Remove the selected element m from the array.
Add a new element with a value of m + 1 to the array.
Increase your score by m.
Return the maximum score you can achieve after performing the operation exactly k times.

 

Example 1:

Input: nums = [1,2,3,4,5], k = 3
Output: 18
Explanation: We need to choose exactly 3 elements from nums to maximize the sum.
For the first iteration, we choose 5. Then sum is 5 and nums = [1,2,3,4,6]
For the second iteration, we choose 6. Then sum is 5 + 6 and nums = [1,2,3,4,7]
For the third iteration, we choose 7. Then sum is 5 + 6 + 7 = 18 and nums = [1,2,3,4,8]
So, we will return 18.
It can be proven, that 18 is the maximum answer that we can achieve.
Example 2:

Input: nums = [5,5,5], k = 2
Output: 11
Explanation: We need to choose exactly 2 elements from nums to maximize the sum.
For the first iteration, we choose 5. Then sum is 5 and nums = [5,5,6]
For the second iteration, we choose 6. Then sum is 5 + 6 = 11 and nums = [5,5,7]
So, we will return 11.
It can be proven, that 11 is the maximum answer that we can achieve.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100



*/


class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {  //tc=O(n), sc=O(1)
        int mx = *max_element(nums.begin(), nums.end());
        int sum = 0;

        for(int i=0; i<k; i++) {
            sum += mx;
            mx++;
        }

        return sum;
    }
};



class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();

        // Find maximum element
        int mx = *max_element(nums.begin(), nums.end());

        // Range of numbers we will add:
        // mx + (mx+1) + ... + (mx+k-1)
        int m = mx + k - 1;
        int min = mx - 1;

        // Sum using n naturalNumber formula
        int result = (m * (m + 1)) / 2 - (min * (min + 1)) / 2;

        return result;
    }
};


//method3-usingGauss summationFormula
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());

        // Gauss summation formula
        return (2 * mx + k - 1) * k / 2;
    }
};







/*


qno 2706  https://leetcode.com/problems/buy-two-chocolates/


2706. Buy Two Chocolates
Solved
Easy
Topics

Companies
Hint
You are given an integer array prices representing the prices of various chocolates in a store. You are also given a single integer money, which represents your initial amount of money.

You must buy exactly two chocolates in such a way that you still have some non-negative leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.

Return the amount of money you will have leftover after buying the two chocolates. If there is no way for you to buy two chocolates without ending up in debt, return money. Note that the leftover must be non-negative.

 

Example 1:

Input: prices = [1,2,2], money = 3
Output: 0
Explanation: Purchase the chocolates priced at 1 and 2 units respectively. You will have 3 - 3 = 0 units of money afterwards. Thus, we return 0.
Example 2:

Input: prices = [3,2,3], money = 3
Output: 3
Explanation: You cannot buy 2 chocolates without going in debt, so we return 3.
 

Constraints:

2 <= prices.length <= 50
1 <= prices[i] <= 100
1 <= money <= 100


*/



class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {  //tc=O(nlogN), sc=O(1)
        sort(prices.begin(), prices.end());

        int first = prices[0];
        int second = prices[1];

        if(first + second > money) {
            return money;
        }

        return money - (first + second);
    }
};



/*

qno 3545  https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/


3545. Minimum Deletions for At Most K Distinct Characters
Easy
Topics

Companies
Hint
You are given a string s consisting of lowercase English letters, and an integer k.

Your task is to delete some (possibly none) of the characters in the string so that the number of distinct characters in the resulting string is at most k.

Return the minimum number of deletions required to achieve this.

 

Example 1:

Input: s = "abc", k = 2

Output: 1

Explanation:

s has three distinct characters: 'a', 'b' and 'c', each with a frequency of 1.
Since we can have at most k = 2 distinct characters, remove all occurrences of any one character from the string.
For example, removing all occurrences of 'c' results in at most k distinct characters. Thus, the answer is 1.
Example 2:

Input: s = "aabb", k = 2

Output: 0

Explanation:

s has two distinct characters ('a' and 'b') with frequencies of 2 and 2, respectively.
Since we can have at most k = 2 distinct characters, no deletions are required. Thus, the answer is 0.
Example 3:

Input: s = "yyyzz", k = 1

Output: 2

Explanation:

s has two distinct characters ('y' and 'z') with frequencies of 3 and 2, respectively.
Since we can have at most k = 1 distinct character, remove all occurrences of any one character from the string.
Removing all 'z' results in at most k distinct characters. Thus, the answer is 2.
 

Constraints:

1 <= s.length <= 16
1 <= k <= 16
s consists only of lowercase English letters.

 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
40,589/55.7K
Acceptance Rate
72.9%
Topics
Hash Table
String
Greedy
Sorting
Counting
Weekly Contest 449


*/



class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> freq;

        // Step 1: frequency count
        for (char c : s) {
            freq[c]++;
        }

        // If already within limit
        if (freq.size() <= k) return 0;

        // Step 2: collect frequencies
        vector<int> counts;
        for (auto &p : freq) {
            counts.push_back(p.second);
        }

        // Step 3: sort descending
        sort(counts.begin(), counts.end(), greater<int>());

        // Step 4 & 5: delete all except top k
        int deletions = 0;
        for (int i = k; i < counts.size(); i++) {
            deletions += counts[i];
        }

        return deletions;
    }
};





/*

qno 3651  https://leetcode.com/problems/minimum-cost-path-with-teleportations/?envType=daily-question&envId=2026-01-28



3651. Minimum Cost Path with Teleportations
Hard
Topics
premium lock icon
Companies
Hint
You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottom‐right cell (m - 1, n - 1).

There are two types of moves available:

Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.

Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.

Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).

 

Example 1:

Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2

Output: 7

Explanation:

Initially we are at (0, 0) and cost is 0.

Current Position	Move	New Position	Total Cost
(0, 0)	Move Down	(1, 0)	0 + 2 = 2
(1, 0)	Move Right	(1, 1)	2 + 5 = 7
(1, 1)	Teleport to (2, 2)	(2, 2)	7 + 0 = 7
The minimum cost to reach bottom-right cell is 7.

Example 2:

Input: grid = [[1,2],[2,3],[3,4]], k = 1

Output: 9

Explanation:

Initially we are at (0, 0) and cost is 0.

Current Position	Move	New Position	Total Cost
(0, 0)	Move Down	(1, 0)	0 + 2 = 2
(1, 0)	Move Right	(1, 1)	2 + 3 = 5
(1, 1)	Move Down	(2, 1)	5 + 4 = 9
The minimum cost to reach bottom-right cell is 9.

 

Constraints:

2 <= m, n <= 80
m == grid.length
n == grid[i].length
0 <= grid[i][j] <= 104
0 <= k <= 10
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
10,162/33.4K
Acceptance Rate
30.4%
Topics
Array
Dynamic Programming
Matrix
Biweekly Contest 163


*/



class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));
        
        // Min-heap: {cost, i, j, teleport_used}
        using T = tuple<int,int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        
        dp[0][0][0] = 0;
        pq.push({0,0,0,0});
        
        vector<int> dirs = {0,1,1,0}; // right/down directions
        
        while(!pq.empty()) {
            auto [cost,i,j,t] = pq.top(); pq.pop();
            
            if(dp[i][j][t] < cost) continue; // already visited better
            
            // Normal moves
            for(int d=0; d<2; d++) {
                int ni = i + dirs[d], nj = j + dirs[d+2];
                if(ni < m && nj < n) {
                    int nc = cost + grid[ni][nj];
                    if(nc < dp[ni][nj][t]) {
                        dp[ni][nj][t] = nc;
                        pq.push({nc, ni, nj, t});
                    }
                }
            }
            
            // Teleport moves
            if(t < k) {
                for(int x=0; x<m; x++) {
                    for(int y=0; y<n; y++) {
                        if(grid[x][y] <= grid[i][j]) {
                            if(cost < dp[x][y][t+1]) {
                                dp[x][y][t+1] = cost;
                                pq.push({cost, x, y, t+1});
                            }
                        }
                    }
                }
            }
        }
        
        // Answer: minimum over all teleport counts at target
        int ans = INT_MAX;
        for(int t=0; t<=k; t++) ans = min(ans, dp[m-1][n-1][t]);
        return ans;
    }
};


// this give TLE error


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // store all cell coordinates
        vector<pair<int,int>> cells;
        cells.reserve(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells.emplace_back(i, j);
            }
        }

        // sort cells by grid value
        sort(cells.begin(), cells.end(),
             [&](const pair<int,int>& a, const pair<int,int>& b) {
                 return grid[a.first][a.second] < grid[b.first][b.second];
             });

        // cost to reach destination from each cell
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        // repeat k+1 times
        for (int t = 0; t <= k; t++) {

            // teleportation update
            int mincost = INT_MAX;
            int start = 0;

            for (int i = 0; i < (int)cells.size(); i++) {
                int x = cells[i].first;
                int y = cells[i].second;

                mincost = min(mincost, cost[x][y]);

                if (i + 1 < (int)cells.size() &&
                    grid[x][y] == grid[cells[i + 1].first][cells[i + 1].second]) {
                    continue;
                }

                // update all cells with same grid value
                for (int j = start; j <= i; j++) {
                    cost[cells[j].first][cells[j].second] = mincost;
                }
                start = i + 1;
            }

            // DP from bottom-right to top-left
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        cost[i][j] = 0;
                    }

                    // move down
                    if (i != m - 1) {
                        cost[i][j] = min(cost[i][j],
                                          grid[i + 1][j] + cost[i + 1][j]);
                    }

                    // move right
                    if (j != n - 1) {
                        cost[i][j] = min(cost[i][j],
                                          grid[i][j + 1] + cost[i][j + 1]);
                    }
                }
            }
        }

        return cost[0][0];
    }
};

