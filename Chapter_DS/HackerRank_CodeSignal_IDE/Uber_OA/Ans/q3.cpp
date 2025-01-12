

/*

Uber has introduced a new metric to determine the optimal locations for opening new cab zones. One of the key parameters in this metric is the minimum cost required to connect all existing cab zones.

After some pre-computation, the coordinates of all cab zones are converted into integer points on a 2D-plane represented by an array points where points[i] = [xi, yi]

The cost of connecting two such cab zones - Zone i as [xi, yi] and Zone j as [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Devise an algorithm to return the minimum cost to connect all the cab zones. All the zones are connected if there is exactly one simple path between any two points.

Note: All coordinates (xi, yi) are distinct.

Sample Input 1
points = [[0,0],[2,2],[3,10],[5,2],[7,0]]

*/



#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

// Disjoint Set Union (DSU) or Union-Find Data Structure
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);  // Initially, each node is its own parent
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);  // Path compression
        return parent[u];
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

// Function to calculate the Manhattan distance between two points
int manhattanDistance(const vector<int>& p1, const vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

int solution(vector<vector<int>> points) {
    int n = points.size();
    vector<pair<int, pair<int, int>>> edges;  // Store (cost, (point1, point2))

    // Step 1: Generate all possible edges with their Manhattan distances
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cost = manhattanDistance(points[i], points[j]);
            edges.push_back({cost, {i, j}});
        }
    }

    // Step 2: Sort all edges by cost (Manhattan distance)
    sort(edges.begin(), edges.end());

    // Step 3: Use Union-Find to add edges to the MST
    UnionFind uf(n);
    int totalCost = 0;
    int edgesAdded = 0;

    for (const auto& edge : edges) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        // If the points are in different sets, add this edge to the MST
        if (uf.unite(u, v)) {
            totalCost += cost;
            edgesAdded++;
        }

        // If we've added n-1 edges, we have a spanning tree
        if (edgesAdded == n - 1) {
            break;
        }
    }

    return totalCost;
}

int main() {
    // Sample Input 1
    vector<vector<int>> points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << "Minimum Cost to Connect All Points (Sample 1): " << solution(points1) << endl;

    // Sample Input 2
    vector<vector<int>> points2 = {{3, 12}, {-2, 5}, {-4, 1}};
    cout << "Minimum Cost to Connect All Points (Sample 2): " << solution(points2) << endl;

    return 0;
}



// Score = 300/300, testCase = 