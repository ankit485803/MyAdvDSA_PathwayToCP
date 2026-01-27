



/*

27th Jan 2026 (Tuesday)


qno  2144  https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/


2144. Minimum Cost of Buying Candies With Discount
Easy
Topics

Companies
Hint
A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.

The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.

For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

 

Example 1:

Input: cost = [1,2,3]
Output: 5
Explanation: We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.
Example 2:

Input: cost = [6,5,7,9,2,2]
Output: 23
Explanation: The way in which we can get the minimum cost is described below:
- Buy candies with costs 9 and 7
- Take the candy with cost 6 for free
- We buy candies with costs 5 and 2
- Take the last remaining candy with cost 2 for free
Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
Example 3:

Input: cost = [5,5]
Output: 10
Explanation: Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
Hence, the minimum cost to buy all candies is 5 + 5 = 10.
 

Constraints:

1 <= cost.length <= 100
1 <= cost[i] <= 100
 
Discover more
candies
Candies
candy
Seen this question in a real interview before?
1/5
Yes
No
Accepted
76,801/122.7K
Acceptance Rate
62.6%
Topics
Array
Greedy
Sorting
Biweekly Contest 70


*/


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int idx = 1;
        int minCost = 0;

        for(int i=cost.size()-1; i>=0; i--) {
            if(idx % 3 != 0) {
                minCost += cost[i];
            }
            idx++;
        }

        return minCost;
    }
};




/*


qno  2600  https://leetcode.com/problems/k-items-with-the-maximum-sum/


2600. K Items With the Maximum Sum
Easy
Topics

Companies
Hint
There is a bag that consists of items, each item has a number 1, 0, or -1 written on it.

You are given four non-negative integers numOnes, numZeros, numNegOnes, and k.

The bag initially contains:

numOnes items with 1s written on them.
numZeroes items with 0s written on them.
numNegOnes items with -1s written on them.
We want to pick exactly k items among the available items. Return the maximum possible sum of numbers written on the items.

 

Example 1:

Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
Output: 2
Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 2 items with 1 written on them and get a sum in a total of 2.
It can be proven that 2 is the maximum possible sum.
Example 2:

Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
Output: 3
Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 3 items with 1 written on them, and 1 item with 0 written on it, and get a sum in a total of 3.
It can be proven that 3 is the maximum possible sum.
 

Constraints:

0 <= numOnes, numZeros, numNegOnes <= 50
0 <= k <= numOnes + numZeros + numNegOnes
 
Discover more
Math
Mathematics
Seen this question in a real interview before?
1/5
Yes
No
Accepted
61,860/102.9K
Acceptance Rate
60.1%
Topics
Math
Greedy
Weekly Contest 338


*/



class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {  //tc=O(1)=sc
        int maxSum = 0;
        if(k <= numOnes) return k;

        // Take all 1s
        maxSum += numOnes;
        k -= numOnes;

        // Take 0s if possible
        if(k <= numZeros) {
            return maxSum;
        }

        // Remaining must be -1s
        k -= numZeros;
        return maxSum - k;
    }
};





/*

qno 3650  https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/?envType=daily-question&envId=2026-01-27


3650. Minimum Cost Path with Edge Reversals
Medium
Topics

Companies
Hint
You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.

The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

 

Example 1:

Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

Output: 5

Explanation:



Use the path 0 → 1 (cost 3).
At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
Total cost is 3 + 2 = 5.
Example 2:

Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]

Output: 3

Explanation:

No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
Total cost is 1 + 1 + 1 = 3.
 

Constraints:

2 <= n <= 5 * 104
1 <= edges.length <= 105
edges[i] = [ui, vi, wi]
0 <= ui, vi <= n - 1
1 <= wi <= 1000
 
Discover more
Online coding assessment platforms
Seen this question in a real interview before?
1/5
Yes
No
Accepted
52,187/89.2K
Acceptance Rate
58.5%
Topics
Graph Theory
Heap (Priority Queue)
Shortest Path
Biweekly Contest 163


*/



class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {  //tc=O((n+m) logN), sc=o(n+m)
        vector<vector<pair<int,int>>> adj(n);

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});        // normal edge
            adj[v].push_back({u, 2 * w});    // reversed edge option
        }

        // Dijkstra
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }
};
