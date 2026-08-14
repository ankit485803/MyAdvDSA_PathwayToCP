

/*
date of uploaded: 17th July 
src: https://www.instagram.com/reel/Da5Y5xPhkTn


Problem Statement:
Given an unsorted array and a target value, find the indices of two
numbers whose sum is equal to the target.

Example:
nums = [2, 11, 7, 15], target = 9
Output: [0, 2]

Approach 1: Nested Loop
- Check every possible pair.
- Time Complexity: O(n^2)
- Space Complexity: O(1)

Approach 2: Hash Map
- Store each number and its index while traversing the array.
- For every number, check whether its complement (target - nums[i])
  already exists in the map.
- Time Complexity: O(n)
- Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Nested Loop
vector<int> twoSumNestedLoop(const vector<int>& nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {};
}


// Approach 2: Hash Map
vector<int> twoSumHashMap(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }

        seen[nums[i]] = i;
    }

    return {};
}


int main() {
    vector<int> nums = {2, 11, 7, 15};
    int target = 9;

    // Approach 1
    vector<int> ans1 = twoSumNestedLoop(nums, target);

    // Approach 2
    vector<int> ans2 = twoSumHashMap(nums, target);

    cout << "Approach 1: ";
    for (int index : ans1) {
        cout << index << " ";
    }
    cout << endl;

    cout << "Approach 2: ";
    for (int index : ans2) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}