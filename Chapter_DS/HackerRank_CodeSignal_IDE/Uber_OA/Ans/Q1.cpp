

/*

Problem Statement


In a bustling network of cities, a driver is tasked with completing a high-priority UberX delivery from a start city to an end city. 
However, challenges lurk along the way—certain cities are marked as unsafe due to disruptions caused by local criminal activity or 
thieves. These disruptions cast a shadow of influence over the surrounding region, making it risky for drivers to travel through 
these areas.

The influence of these disruptions is particularly challenging: each affected city has an influence radius k, which extends its 
control to neighboring cities within k roads (hops). For instance:

If a thief resides in a city with k=1, their influence makes their city and all directly connected cities unsafe.
If k=2, their menace spreads further, affecting their city, its neighbors, and the neighbors of those neighbors.
An UberX driver navigating these roads must carefully avoid unsafe areas, prioritizing their safety while ensuring the timely delivery of their service. Can the driver find a safe route through this network of roads and cities to successfully reach the destination without venturing into these unsafe zones?



eg1
Explanation:
If cities 1 and 2 are occupied by thieves, with k=1, and the journey starts at city 0 and aims to reach city 8, the truck cannot 
reach its destination. The thief in city 1 makes cities 0, 3, and 4 unsafe, while the thief in city 2 makes cities 0, 5, and 6 unsafe.



eg2
Explanation:
If cities 3 and 7 are occupied by thieves, with k=1, and the journey starts at city 0 and aims to reach city 8, the truck can reach its 
destination without traveling through any dangerous city. The thief in city 3 makes only city 1 unsafe, while the thief in city 7 
makes cities 4 and 5 unsafe. The truck can travel from 0 -> 2 -> 6 -> 8.



*/



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

// Function to mark unsafe cities based on thief influence
void markUnsafeCities(int n, const vector<vector<int>>& graph, unordered_set<int>& unsafeCities, const vector<int>& thieves, int k) {
    queue<pair<int, int>> q; // (current city, distance)
    unordered_set<int> visited;


    for (int thief : thieves) {
        q.push({thief, 0});
        visited.insert(thief);

        while (!q.empty()) {
            auto [current, distance] = q.front();
            q.pop();

            if (distance > k) continue;

            unsafeCities.insert(current);

            for (int neighbor : graph[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({neighbor, distance + 1});
                }
            }
        }
    }
}

// Function to find the shortest safe path using BFS
int findShortestPath(int n, const vector<vector<int>>& graph, const unordered_set<int>& unsafeCities, int start, int end) {
    queue<pair<int, int>> q; // (current city, distance)
    unordered_set<int> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [current, distance] = q.front();
        q.pop();

        if (current == end) {
            return distance;
        }

        for (int neighbor : graph[current]) {
            if (unsafeCities.find(neighbor) == unsafeCities.end() && visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, distance + 1});
            }
        }
    }

    return -1; // No safe path found
}

int solution(int n, vector<vector<int>> roads, vector<int> thieves, int k, int start, int end) {
    // Build the graph
    vector<vector<int>> graph(n);
    for (const auto& road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }

    // Mark unsafe cities
    unordered_set<int> unsafeCities;
    markUnsafeCities(n, graph, unsafeCities, thieves, k);

    // Find the shortest safe path
    return findShortestPath(n, graph, unsafeCities, start, end);
}

int main() {
    // Example 1
    int n = 9;
    vector<vector<int>> roads = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {4, 7}, {5, 7}, {6, 8}};
    vector<int> thieves = {1, 2};
    int k = 1, start = 0, end = 8;

    cout << solution(n, roads, thieves, k, start, end) << endl; // Output: -1

    // Example 2
    thieves = {3, 7};
    cout << solution(n, roads, thieves, k, start, end) << endl; // Output: 3

    return 0;
}



// Score = 139 / 150