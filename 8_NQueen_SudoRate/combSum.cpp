

// qno 39  https://leetcode.com/problems/combination-sum/


#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    set<vector<int>> s; // To store unique combinations

    void getAllCombinations(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combin) {
        // Base case
        if (idx == arr.size() || target < 0) {
            return;
        }

        if (target == 0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        // Include the current element (single occurrence)
        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx + 1, target - arr[idx], ans, combin);

        // Include the current element (multiple occurrences)
        getAllCombinations(arr, idx, target - arr[idx], ans, combin);

        // Backtrack
        combin.pop_back();

        // Exclude the current element
        getAllCombinations(arr, idx + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(arr, 0, target, ans, combin);

        // Final answer
        return ans;
    }
};
