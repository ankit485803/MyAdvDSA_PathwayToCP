


/*

10th March 2026 (Tuesday - landRegistry)


3130. Find All Possible Stable Binary Arrays II
Hard
Topics

Companies
Hint
You are given 3 positive integers zero, one, and limit.

A binary array arr is called stable if:

The number of occurrences of 0 in arr is exactly zero.
The number of occurrences of 1 in arr is exactly one.
Each subarray of arr with a size greater than limit must contain both 0 and 1.
Return the total number of stable binary arrays.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: zero = 1, one = 1, limit = 2

Output: 2

Explanation:

The two possible stable binary arrays are [1,0] and [0,1].

Example 2:

Input: zero = 1, one = 2, limit = 1

Output: 1

Explanation:

The only possible stable binary array is [1,0,1].

Example 3:

Input: zero = 3, one = 3, limit = 2

Output: 14

Explanation:

All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].

 

Constraints:

1 <= zero, one, limit <= 1000
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
10,909/25.8K
Acceptance Rate
42.3%
Topics
Principal
Dynamic Programming
Prefix Sum
Biweekly Contest 129


*/



//Approach-1 (Recursion + Memoization - Derived from Part-I)
//T.C : O(one * zero)
//S.C : O(one * zero)
class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<vector<int>>> t;

    int solve(int i, int j, int last, int limit) {

        // Base: no elements
        if (i == 0 && j == 0) 
            return 0;

        // Base: only zeros left
        if (j == 0) {
            if (last == 1) return 0; 
            return (i <= limit) ? 1 : 0;
        }

        // Base: only ones left
        if (i == 0) {
            if (last == 0) return 0; 
            return (j <= limit) ? 1 : 0;
        }

        if (t[i][j][last] != -1)
            return t[i][j][last];

        int result = 0;

        if (last == 0) {
            result = (solve(i-1, j, 0, limit) + solve(i-1, j, 1, limit)) % M;

            if (i-1 >= limit)
                result = (result - solve(i-1-limit, j, 1, limit) + M) % M;

        } else {
            result = (solve(i, j-1, 0, limit) + solve(i, j-1, 1, limit)) % M;

            if (j-1 >= limit)
                result = (result - solve(i, j-1-limit, 0, limit) + M) % M;
        }

        return t[i][j][last] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        t.assign(zero+1, vector<vector<int>>(one+1, vector<int>(2, -1)));

        return (solve(zero, one, 0, limit) + solve(zero, one, 1, limit)) % M;
    }
};


//Approach-2 (Bottom Up - Derived from Part-I)
//T.C : O(one * zero)
//S.C : O(one * zero)
class Solution {
public:
    int M = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        //t[zero+1][one+1][2] 
        vector<vector<vector<int>>> t(zero+1, vector<vector<int>>(one+1, vector<int>(2, 0)));

        for(int i = 0; i <= min(zero, limit); i++)
            t[i][0][0] = 1;
        
        for(int j = 0; j <= min(one, limit); j++) {
            t[0][j][1] = 1;
        }

        for(int i = 0; i <= zero; i++) { //i = # 0s
            for(int j = 0; j <= one; j++) { //j = # 1s

                if(i == 0 || j == 0)
                    continue;

                t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % M;
                
                if(j-1 >= limit) {
                    t[i][j][1] = (t[i][j][1] - t[i][j-1-limit][0] + M) % M;
                }

                t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % M;
                
                if(i-1 >= limit) {
                    t[i][j][0] = (t[i][j][0] - t[i-1-limit][j][1] + M) % M;
                }
            }
        }

        return (t[zero][one][0] + t[zero][one][1]) % M;
    }
};





/*

qno 3861   https://leetcode.com/problems/minimum-capacity-box/


3861. Minimum Capacity Box
Attempted
Easy
Topics

Companies
Hint
You are given an integer array capacity, where capacity[i] represents the capacity of the ith box, and an integer itemSize representing the size of an item.

The ith box can store the item if capacity[i] >= itemSize.

Return an integer denoting the index of the box with the minimum capacity that can store the item. If multiple such boxes exist, return the smallest index.

If no box can store the item, return -1.

 

Example 1:

Input: capacity = [1,5,3,7], itemSize = 3

Output: 2

Explanation:

The box at index 2 has a capacity of 3, which is the minimum capacity that can store the item. Thus, the answer is 2.

Example 2:

Input: capacity = [3,5,4,3], itemSize = 2

Output: 0

Explanation:

The minimum capacity that can store the item is 3, and it appears at indices 0 and 3. Thus, the answer is 0.

Example 3:

Input: capacity = [4], itemSize = 5

Output: -1

Explanation:

No box has enough capacity to store the item, so the answer is -1.

 

Constraints:

1 <= capacity.length <= 100
1 <= capacity[i] <= 100
1 <= itemSize <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
42,559/59K
Acceptance Rate
72.1%
Topics
Mid Level
Array
Weekly Contest 492


*/


class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {  //bruteForce tc=O(n logN), sc=O(1) WRONG
        vector<int> ans;  //store idx

        for(int i=0; i<capacity.size(); i++) {
            if(capacity[i] >= itemSize) {  //storingCondition
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());  //sorted in ascendingOrder
        return ans[0];  //smallest idx
    }
};






/*


qno 785   https://leetcode.com/problems/is-graph-bipartite/



785. Is Graph Bipartite?
Medium
Topics

Companies
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 

Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
850,579/1.4M
Acceptance Rate
59.0%
Topics
Senior Staff
Depth-First Search
Breadth-First Search
Union-Find
Graph Theory
Weekly Contest 72


we use the idea of 2-coloring the graph.
A graph is bipartite if we can color all nodes with two colors such that no adjacent nodes share the same color.
    Because the graph may be disconnected, we must start BFS/DFS from every unvisited node.



*/



class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {  //tc=O(V + E), sc=O(V)
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] != -1) continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int nei : graph[node]) {
                    if(color[nei] == -1) {
                        color[nei] = 1 - color[node];
                        q.push(nei);
                    }
                    else if(color[nei] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};