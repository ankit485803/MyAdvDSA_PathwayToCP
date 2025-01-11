

// qno 2965   https://leetcode.com/problems/find-missing-and-repeated-values/description/


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {   //overal = O(n^2)
        vector<int> ans;
        unordered_set<int> s;  // To track the repeated number
        int n = grid.size();
        int repeated = -1, missing = -1;
        int actualSum = 0;

        // Calculate the actual sum of all elements in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];

                // Check if the value is repeated
                if (s.find(grid[i][j]) != s.end()) {
                    repeated = grid[i][j];
                }

                s.insert(grid[i][j]);
            }
        }

        // Expected sum of all numbers from 1 to n^2 (if all numbers were unique)
        int expSum = (n * n * (n * n + 1)) / 2;

        // The missing number can be calculated using the difference
        missing = expSum - actualSum + repeated;

        // Add repeated and missing values to the answer
        ans.push_back(repeated);
        ans.push_back(missing);

        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {1, 2, 3},
        {3, 4, 5},
        {6, 7, 8}
    };

    vector<int> result = solution.findMissingAndRepeatedValues(grid);

    cout << "Repeated value: " << result[0] << endl;
    cout << "Missing value: " << result[1] << endl;

    return 0;
}
