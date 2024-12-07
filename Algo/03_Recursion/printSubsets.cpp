

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>



void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
    if (i == arr.size()) {
        // Print the current subset stored in 'ans'
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // Include arr[i] in the subset
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    // Exclude arr[i] from the subset (backtrack)
    ans.pop_back();  
    printSubsets(arr, ans, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;   // store subsets

    printSubsets(arr, ans, 0);
    return 0;
}



//qno 78  https://leetcode.com/problems/subsets/

class Solution {
public:

    // Backtracking function to generate all subsets
    void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets) {
        if(i == nums.size()) {
            // Store the current subset
            allSubsets.push_back(ans);
            return;
        }

        // Include the current element in the subset
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, allSubsets);

        // Backtrack by excluding the current element
        ans.pop_back();
        
        // Exclude the current element from the subset
        getAllSubsets(nums, ans, i+1, allSubsets);
    }

    // Function to generate all subsets of nums
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;  // Store all subsets
        vector<int> ans;  // Temporary vector to store a single subset

        getAllSubsets(nums, ans, 0, allSubsets);
        
        return allSubsets;
    }
};


// TC = O(n * 2^n) using backtracking


//qno 90     https://leetcode.com/problems/subsets-ii/


class Solution {
public:

    // Backtracking function to generate subsets
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        // Base case: when we reach the end of the array
        if (i == nums.size()) {
            allSubsets.push_back(ans);  // Add the current subset to the result
            return;
        }

        // Include the current element
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);  // Recurse to the next element

        // Backtrack: exclude the current element
        ans.pop_back();

        // Skip over duplicates: only include nums[i] if it's the first occurrence
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;  // Skip the duplicate
        }

        // Exclude the current element and continue to the next unique element
        getAllSubsets(nums, ans, i + 1, allSubsets);  // Recurse to the next element
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to easily handle duplicates
        vector<vector<int>> allSubsets;  // To store all subsets
        vector<int> ans;  // To store the current subset

        getAllSubsets(nums, ans, 0, allSubsets);  // Start recursion from index 0
        return allSubsets;
    }
};


// TC = O(2^n * n)