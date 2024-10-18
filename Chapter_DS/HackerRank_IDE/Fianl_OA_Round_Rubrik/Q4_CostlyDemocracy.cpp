

/* QUES

A town consists of N villages. There is a unique path from one village to any other village in the town. Village i consists of 
Ai people living in it. The mayor of the town wants to hold a town-wide meeting in one of the villages in the town. 
The cost of holding the meeting in a village i will be equal to the transportation cost of moving all the people from all other 
villages to village i. The transportation cost for moving one person from any village to its adjacent village is 1. The mayor wants to
 determine what will be the cost of holding the meeting in each of the villages i such that 1 <= i <= N.



Constraints
1 <= T <= 10000
0 <= A; <= 10^9
Sum of N over all test cases T does not exceed 2 * 10^5




CONCEPT req: Acyclic graph, tree, DP

*/
 

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
long long population[MAXN];  // Stores population of each village
long long subtree_population[MAXN];  // Stores population of the subtree rooted at each village
long long cost[MAXN];  // Stores the transportation cost for each village
long long total_population = 0;  // Total population of the entire town

// First DFS: Calculate subtree populations and the initial cost for the root node
void dfs1(int node, int parent) {
    subtree_population[node] = population[node];

    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            dfs1(neighbor, node);
            subtree_population[node] += subtree_population[neighbor];
            cost[1] += subtree_population[neighbor];  // Sum of distances to root (node 1)
        }
    }
}

// Second DFS: Re-rooting to calculate cost for all nodes
void dfs2(int node, int parent) {
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            // Re-root from `node` to `neighbor`
            cost[neighbor] = cost[node] + total_population - 2 * subtree_population[neighbor];
            dfs2(neighbor, node);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        // Reset global variables for each test case
        total_population = 0;
        for (int i = 1; i <= N; ++i) {
            tree[i].clear();
            population[i] = 0;
            subtree_population[i] = 0;
            cost[i] = 0;
        }

        // Read the populations of each village
        for (int i = 1; i <= N; ++i) {
            cin >> population[i];
            total_population += population[i];
        }

        // Read the edges of the tree
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // First DFS: Calculate subtree populations and the initial cost at the root (node 1)
        dfs1(1, -1);

        // Second DFS: Use re-rooting to calculate the cost for all villages
        dfs2(1, -1);

        // Print the cost for each village
        for (int i = 1; i <= N; ++i) {
            cout << cost[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

