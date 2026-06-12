

/*

12th June 2026 (Friday)

qno 3559  https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/?envType=daily-question&envId=2026-06-12

3559. Number of Ways to Assign Edge Weights II
Solved
Hard
Topics

Companies
Hint
There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.

Return an array answer, where answer[i] is the number of valid assignments for queries[i].

Since the answer may be large, apply modulo 109 + 7 to each answer[i].

Note: For each query, disregard all edges not in the path between node ui and vi.

 

Example 1:



Input: edges = [[1,2]], queries = [[1,1],[1,2]]

Output: [0,1]

Explanation:

Query [1,1]: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 → 2). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
Example 2:



Input: edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]

Output: [2,1,4]

Explanation:

Query [1,4]: The path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4). Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
Query [3,4]: The path from Node 3 to Node 4 consists of one edge (3 → 4). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
Query [2,5]: The path from Node 2 to Node 5 consists of three edges (2 → 1, 1 → 3, and 3 → 5). Assigning (1,2,2), (2,1,2), (2,2,1), or (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.
 

Constraints:

2 <= n <= 105
edges.length == n - 1
edges[i] == [ui, vi]
1 <= queries.length <= 105
queries[i] == [ui, vi]
1 <= ui, vi <= n
edges represents a valid tree.
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
32,206/46.2K
Acceptance Rate
69.7%
Topics
Senior Staff
Array
Math
Dynamic Programming
Bit Manipulation
Tree
Depth-First Search
Biweekly Contest 157  

*/


class Solution {
    static const int mod = 1000000007;
    vector<int> depth;
    unordered_map<int, vector<int>> hmap;
    vector<vector<int>> lift; // Binary lifting table

public:
    // Time:  O(n) build adjacency + O(n) BFS + O(n log n) lift table + O(q log n) queries
    // Space: O(n log n) for lift table, O(n) for depth/visited

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        depth.assign(n + 1, 0);
        hmap.clear();
        lift.assign(n + 1, vector<int>(18, 0)); // 2^18 > 10^5

        // Build undirected adjacency list
        for (auto& e : edges) {
            int s = e[0], d = e[1];
            hmap[s].push_back(d);
            hmap[d].push_back(s);
        }

        // BFS from root (node 1) to compute depth and direct parents
        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(1);
        visited[1] = true;
        lift[1][0] = 1; // Root's parent points to itself

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (hmap.find(curr) == hmap.end()) continue;

            for (int next : hmap[curr]) {
                if (visited[next]) continue;

                visited[next] = true;
                depth[next] = depth[curr] + 1;
                lift[next][0] = curr; // Direct parent
                q.push(next);
            }
        }

        // Build binary lifting table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 18; j++) {
                lift[i][j] = lift[lift[i][j - 1]][j - 1];
            }
        }

        // Answer queries
        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            int dist = depth[u] + depth[v] - 2 * depth[lca(u, v)];

            // Number of valid assignments = 2^(dist-1)
            ans[i] = (dist == 0) ? 0 : power(2, dist - 1);
        }

        return ans;
    }

private:
    // LCA via binary lifting
    int lca(int u, int v) {
        // Ensure u is deeper
        if (depth[u] < depth[v])
            return lca(v, u);

        // Bring u up to v's depth
        int diff = depth[u] - depth[v];

        for (int j = 0; j < 18; j++) {
            if (diff & 1)
                u = lift[u][j];
            diff >>= 1;
        }

        if (u == v) return u;

        // Move both up until ancestors diverge
        for (int j = 17; j >= 0; j--) {
            if (lift[u][j] != lift[v][j]) {
                u = lift[u][j];
                v = lift[v][j];
            }
        }

        return lift[u][0];
    }

    // Fast binary exponentiation under mod
    int power(int base, int exp) {
        long long res = 1;
        long long b = base % mod;

        while (exp > 0) {
            if (exp & 1)
                res = (res * b) % mod;

            b = (b * b) % mod;
            exp >>= 1;
        }

        return static_cast<int>(res);
    }
};