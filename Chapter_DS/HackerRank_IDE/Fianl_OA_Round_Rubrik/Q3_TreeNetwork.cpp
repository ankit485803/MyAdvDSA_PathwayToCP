
/* QUES

We define a K-star as a pair of:

a center vertex C
an unordered K-tuple of corner vertices (V1, V2, ..., VK). which satisfies the following conditions:
d(C, v₁) = d(C, vj) ≠ 0
2 * d(C, v₁) = d(vi, vj) V(i, j) such that 1 <= i, j <= K and i ≠ j Here d(x, y) denotes the distance between nodes x and y on the given tree. Given the value K, count the number of K-stars in the given tree consisting of N vertices. Since this number may be huge, 

print the answer modulo 998244353. Constraints:
3 ≤ N ≤ 5000
2 ≤ K ≤ N-1
1 ≤ ui, vi ≤ N




CONCEPT req: K-Star Tree problem, DFS / BFS,  


*/





//sumitted sol
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MOD = 998244353;
const int MAXN = 5005;

int N, K;
vector<int> tree[MAXN];
int dist[MAXN][MAXN];  // Stores distances between all pairs of nodes

// Function to perform BFS and calculate distances from a given start node
void bfs(int start) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(N + 1, false);
    visited[start] = true;
    dist[start][start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : tree[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[start][neighbor] = dist[start][node] + 1;
                q.push(neighbor);
            }
        }
    }
}

// Function to precompute binomial coefficients (n choose k) % MOD
vector<vector<long long>> binomial_coeff(int n) {
    vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    return C;
}

int main() {
    cin >> N >> K;

    // Read the tree edges
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Calculate all-pairs shortest paths using BFS from each node
    for (int i = 1; i <= N; ++i) {
        bfs(i);
    }

    // Precompute binomial coefficients
    vector<vector<long long>> C = binomial_coeff(N);

    long long result = 0;

    // Iterate over all possible centers
    for (int c = 1; c <= N; ++c) {
        // Group nodes by their distance from the current center
        unordered_map<int, vector<int>> groups;
        for (int v = 1; v <= N; ++v) {
            if (v != c) {
                groups[dist[c][v]].push_back(v);
            }
        }



        // For each distance group, count valid K-stars
        for (auto& [d, nodes] : groups) {
            int size = nodes.size();
            if (size >= K) {
                // Add the number of ways to choose K nodes from this group
                result = (result + C[size][K]) % MOD;
            }
        }
    }



    cout << result << endl;
    return 0;
}
