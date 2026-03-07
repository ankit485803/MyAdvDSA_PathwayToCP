

/*




https://www.hackerrank.com/contests/codebash-iit-patna/challenges/reachable-nodes-1


You are given an undirected graph with N nodes labeled 1..N and M edges. Starting from node S, determine how many distinct nodes are reachable (including S) by traversing edges.

Input Format

First line: N M

Next M lines: u v (an undirected edge between u and v)

Last line: S

Constraints

1 <= N <= 2 * 10^5

0 <= M <= 2 * 10^5

1 <= u, v, S <= N

Graph may be disconnected

No guarantee of unique edges (handle duplicates safely)

Output Format

Print one integer: number of reachable nodes from S

Sample Input 0

7 6
1 2
2 3
4 5
5 6
6 4
3 7
2
Sample Output 0

4
Explanation 0

From S = 2, reachable nodes are {2,1,3,7} → 4 nodes.


*/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for(int i = 0; i < M; i++){   //tc=O(N + M) = sc
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int S;
    cin >> S;

    vector<bool> visited(N + 1, false);
    queue<int> q;

    q.push(S);
    visited[S] = true;

    int count = 0;

    while(!q.empty()){  
        int node = q.front();
        q.pop();
        count++;

        for(int nei : adj[node]){
            if(!visited[nei]){
                visited[nei] = true;
                q.push(nei);
            }
        }
    }

    cout << count << "\n";

    return 0;
}
