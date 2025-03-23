

/* 23rd March 2025 (Sunday) OA round of chargebee Ltd 

TQ = 4






Cleaning House
You are given a house floor represented as a one-dimensional sequence of N cells, where each cell can be of three types:

F: A cell that contains food.
D: A dirty cell.
Hash - : An empty cell.

Your objective is to group all food cells into consecutive positions while minimizing the cost, following these rules:
Moving food from one cell to an adjacent empty cell costs x coins.
Cleaning a dirty cell (D) to make it an empty cell (-) costs y coins.

You are given Q queries, where each query provides values of x and y. For each query, determine the minimum number of coins required to group all food cells together in a consecutive sequence.

Function Description
Implement the function solve(N, Q, S, queries), where:

N: The length of the string S representing the floor layout.
Q: The number of queries.
S: A string of length N, consisting of F, D, and - characters.
queries: A list of Q pairs, where each pair consists of (x, y), representing the cost of moving food and the cost of cleaning dirt, respectively.

For each query, return the minimum cost required to make all food (F) cells consecutive.

Input Format
If using custom input testing, follow this format:

The first line contains two space-separated integers N and Q, representing the number of cells and the number of queries, respectively.
The second line contains a string S of length N, which represents the layout of the house.

The next Q lines each contain two space-separated integers x and y, where:

x is the cost to move food to an adjacent empty cell.
y is the cost to clean a dirty (D) cell.

Output Format
For each query, output the minimum number of coins required to make all food cells (F) consecutive.

Constraints





*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to compute the minimum cost for each query
void solve(int N, int Q, string S, vector<pair<int, int>> &queries) {
    vector<int> food_positions; // Stores the indices of 'F'
    
    // Collect all positions of 'F' in the string
    for (int i = 0; i < N; i++) {
        if (S[i] == 'F') {
            food_positions.push_back(i);
        }
    }

    // Iterate over each query
    for (auto &[x, y] : queries) {
        if (food_positions.empty()) {
            cout << "0\n"; // No food to move
            continue;
        }

        // Cleaning all 'D' cells before moving food
        ll cleaning_cost = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == 'D') {
                cleaning_cost += y; // Cost to clean dirty cell
            }
        }

        // Finding the optimal range to place all food contiguously
        int m = food_positions.size();
        int median_pos = food_positions[m / 2]; // Optimal center position
        ll moving_cost = 0;
        
        // Move left-side food towards median
        for (int i = 0; i < m / 2; i++) {
            moving_cost += (median_pos - (m / 2 - i) + i - food_positions[i]) * x;
        }

        // Move right-side food towards median
        for (int i = m / 2; i < m; i++) {
            moving_cost += (food_positions[i] - median_pos - (i - m / 2)) * x;
        }

        // Print the minimum total cost for this query
        cout << (cleaning_cost + moving_cost) << "\n";
    }
}

// Main function
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    solve(N, Q, S, queries);
    return 0;
}
