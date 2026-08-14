/*

14th Aug 2026 (Friday) but 11th July is uploaded date 
Src Link: https://www.instagram.com/reel/DapujKTh7Vg/?utm_source=ig_web_copy_link



Problem Statement:
Given a sorted array and a target value, find the indices of
two numbers whose sum is equal to the target.

Example:
Array  = [2, 3, 5, 8, 11]
Target = 10

Output:
[0, 3]  // 2 + 8 = 10
*/

#include <iostream>
#include <vector>
using namespace std;


// Approach 1: Nested Loop tc=O(n^2), sc= O(1)
// Hint: Check every possible pair of elements.
// If their sum equals the target, return their indices.
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


// Approach 2: Two Pointer tc=O(n), sc= O(1)
// Hint: Since the array is sorted, use one pointer at the
// beginning and one at the end.
//
// If sum < target -> move left pointer.
// If sum > target -> move right pointer.
vector<int> twoSumTwoPointer(const vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int currentSum = nums[low] + nums[high];

        if (currentSum == target) {
            return {low, high};
        }
        else if (currentSum < target) {
            low++;
        }
        else {
            high--;
        }
    }

    return {};
}


int main() {
    vector<int> A = {2, 3, 5, 8, 11};
    int target = 10;

    // Approach 1
    vector<int> result1 = twoSumNestedLoop(A, target);

    cout << "Using Nested Loop: ";
    if (!result1.empty()) {
        cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    // Approach 2
    vector<int> result2 = twoSumTwoPointer(A, target);

    cout << "Using Two Pointer: ";
    if (!result2.empty()) {
        cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}



#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Using Nested Loop
// Hint: Check every possible pair of elements.
// If their sum equals the target, return their indices.
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


// Approach 2: Using Two Pointers
// Hint: Since the array is sorted, use one pointer at the
// beginning and one at the end.
// If sum < target -> move left pointer.
// If sum > target -> move right pointer.
vector<int> twoSumTwoPointer(const vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int currentSum = nums[low] + nums[high];

        if (currentSum == target) {
            return {low, high};
        }
        else if (currentSum < target) {
            low++;
        }
        else {
            high--;
        }
    }

    return {};
}


int main() {
    // Sorted array
    vector<int> A = {2, 3, 5, 8, 11};
    int target = 10;

    // Approach 1
    vector<int> result1 = twoSumNestedLoop(A, target);

    cout << "Using Nested Loop: ";
    if (!result1.empty()) {
        cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    // Approach 2
    vector<int> result2 = twoSumTwoPointer(A, target);

    cout << "Using Two Pointer: ";
    if (!result2.empty()) {
        cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}