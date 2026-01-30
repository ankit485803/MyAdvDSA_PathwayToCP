



/*


30th Jan 2026 (Friday)


qno 2976  https://leetcode.com/problems/minimum-cost-to-convert-string-i/



2976. Minimum Cost to Convert String I
Medium
Topics

Companies
Hint
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.
 

Constraints:

1 <= source.length == target.length <= 105
source, target consist of lowercase English letters.
1 <= cost.length == original.length == changed.length <= 2000
original[i], changed[i] are lowercase English letters.
1 <= cost[i] <= 106
original[i] != changed[i]
 
Discover more
Programming skill enhancement
Seen this question in a real interview before?
1/5
Yes
No
Accepted
185,210/292K
Acceptance Rate
63.4%
Topics
Array
String
Graph Theory
Shortest Path
Weekly Contest 377




Floyd–Warshall is an algorithm to find the shortest path between every pair of nodes in a graph.
    Works for directed or undirected graphs
    Allows negative edges (but no negative cycles)
    Uses Dynamic Programming
    Time complexity: O(V³)


Floyd

*/


class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {  //tc=O(26^3 + source.size()),sc=O(26^2)
        
        const long long INF = 1e18;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        
        // Distance from a char to itself is 0
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        
        // Build graph with minimum edge cost
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        
        // Floyd–Warshall: all-pairs shortest paths
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        long long ans = 0;
        
        // Compute total cost
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            
            if (dist[s][t] == INF) {
                return -1;
            }
            ans += dist[s][t];
        }
        
        return ans;
    }
};





/*


qno 2977  https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/?envType=daily-question&envId=2026-01-30


2977. Minimum Cost to Convert String II
Hard
Topics

Companies
Hint
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English characters. You are also given two 0-indexed string arrays original and changed, and an integer array cost, where cost[i] represents the cost of converting the string original[i] to the string changed[i].

You start with the string source. In one operation, you can pick a substring x from the string, and change it to y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y. You are allowed to do any number of operations, but any pair of operations must satisfy either of these two conditions:

The substrings picked in the operations are source[a..b] and source[c..d] with either b < c or d < a. In other words, the indices picked in both operations are disjoint.
The substrings picked in the operations are source[a..b] and source[c..d] with a == c and b == d. In other words, the indices picked in both operations are identical.
Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert "abcd" to "acbe", do the following operations:
- Change substring source[1..1] from "b" to "c" at a cost of 5.
- Change substring source[2..2] from "c" to "e" at a cost of 1.
- Change substring source[2..2] from "e" to "b" at a cost of 2.
- Change substring source[3..3] from "d" to "e" at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28. 
It can be shown that this is the minimum possible cost.
Example 2:

Input: source = "abcdefgh", target = "acdeeghh", original = ["bcd","fgh","thh"], changed = ["cde","thh","ghh"], cost = [1,3,5]
Output: 9
Explanation: To convert "abcdefgh" to "acdeeghh", do the following operations:
- Change substring source[1..3] from "bcd" to "cde" at a cost of 1.
- Change substring source[5..7] from "fgh" to "thh" at a cost of 3. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation.
- Change substring source[5..7] from "thh" to "ghh" at a cost of 5. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation, and identical with indices picked in the second operation.
The total cost incurred is 1 + 3 + 5 = 9.
It can be shown that this is the minimum possible cost.
Example 3:

Input: source = "abcdefgh", target = "addddddd", original = ["bcd","defgh"], changed = ["ddd","ddddd"], cost = [100,1578]
Output: -1
Explanation: It is impossible to convert "abcdefgh" to "addddddd".
If you select substring source[1..3] as the first operation to change "abcdefgh" to "adddefgh", you cannot select substring source[3..7] as the second operation because it has a common index, 3, with the first operation.
If you select substring source[3..7] as the first operation to change "abcdefgh" to "abcddddd", you cannot select substring source[1..3] as the second operation because it has a common index, 3, with the first operation.
 

Constraints:

1 <= source.length == target.length <= 1000
source, target consist only of lowercase English characters.
1 <= cost.length == original.length == changed.length <= 100
1 <= original[i].length == changed[i].length <= source.length
original[i], changed[i] consist only of lowercase English characters.
original[i] != changed[i]
1 <= cost[i] <= 106
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
26,453/53.6K
Acceptance Rate
49.3%
Topics
Array
String
Dynamic Programming
Graph Theory
Trie
Shortest Path
Weekly Contest 377




*/



//Approach (Using Dijkstra's Algorithm and DP with Power of Memoization for both)
/*
N = length of sourceStr / targetStr
M = number of conversion rules (original.size())
L = number of distinct substring lengths
(L = lengthSet.size())
V = number of unique strings appearing in original and changed
E = number of edges in graph (E = M)
T.C : O(
          M                           // graph build
          + M log L                     // lengthSet
          + N² × L                      // DP overhead
          + M² × (V + E) log V          // Dijkstra
        )
  S.C : O(M² + V + E + N)
*/
class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;
    ll BIG_VALUE = 1e10;
    unordered_map<string, vector<pair<string, ll>>> adj; //Graph

    //start -> end -> anser
    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

    vector<ll> dpMemo;

    string sourceStr;
    string targetStr;
    set<int> validLengths;
    
    ll dijkstra(string& start, string& end) {

        if(dijkstraMemo[start].count(end)) {
            return dijkstraMemo[start][end];
        }

        //{cost, string}
        priority_queue<P, vector<P>, greater<P>> pq;
        //vector<int> result(n, INT_MAX)
        unordered_map<string, ll> result; //source to string ka cost stored
        result[start] = 0;
        pq.push({0, start});

        while(!pq.empty()) {
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();

            if(node == end) {
                break;
            }

            for(auto &edge : adj[node]) {
                string adjNode = edge.first;
                ll edgeCost = edge.second;

                if(!result.count(adjNode) || currCost + edgeCost < result[adjNode]) {
                    result[adjNode] = currCost + edgeCost;
                    pq.push({currCost+edgeCost, adjNode});
                }
            }
        }

        ll finalCost = result.count(end) ? result[end] : BIG_VALUE;

        return dijkstraMemo[start][end] = finalCost;

    }
}




class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string> P;

    const ll BIG_VALUE = 1e10;

    // Graph: string -> [(nextString, cost)]
    unordered_map<string, vector<pair<string, ll>>> adj;

    // Memo for shortest path between two strings
    unordered_map<string, unordered_map<string, ll>> dijkstraMemo;

    // DP memo for index in source
    vector<ll> dpMemo;

    string sourceStr, targetStr;
    set<int> validLengths;

    // Dijkstra from start to end
    ll dijkstra(const string& start, const string& end) {
        if (dijkstraMemo[start].count(end)) {
            return dijkstraMemo[start][end];
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        unordered_map<string, ll> dist;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currCost, node] = pq.top();
            pq.pop();

            if (node == end) break;
            if (currCost > dist[node]) continue;

            for (auto& edge : adj[node]) {
                string next = edge.first;
                ll w = edge.second;

                if (!dist.count(next) || currCost + w < dist[next]) {
                    dist[next] = currCost + w;
                    pq.push({currCost + w, next});
                }
            }
        }

        ll ans = dist.count(end) ? dist[end] : BIG_VALUE;
        return dijkstraMemo[start][end] = ans;
    }

    // DP over index
    ll solve(int i) {
        if (i == sourceStr.size()) return 0;
        if (dpMemo[i] != -1) return dpMemo[i];

        ll ans = BIG_VALUE;

        // Option 1: characters already match
        if (sourceStr[i] == targetStr[i]) {
            ans = solve(i + 1);
        }

        // Option 2: try all valid substring lengths
        for (int len : validLengths) {
            if (i + len > sourceStr.size()) continue;

            string sSub = sourceStr.substr(i, len);
            string tSub = targetStr.substr(i, len);

            ll cost = dijkstra(sSub, tSub);
            if (cost == BIG_VALUE) continue;

            ans = min(ans, cost + solve(i + len));
        }

        return dpMemo[i] = ans;
    }

    long long minimumCost(string source,
                          string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        sourceStr = source;
        targetStr = target;

        int M = original.size();

        // Build graph
        for (int i = 0; i < M; i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
            validLengths.insert(original[i].size());
        }

        dpMemo.assign(source.size(), -1);

        ll ans = solve(0);
        return ans >= BIG_VALUE ? -1 : ans;
    }
};
