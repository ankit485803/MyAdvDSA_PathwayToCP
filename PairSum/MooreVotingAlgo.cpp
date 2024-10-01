#include <iostream>
#include <vector>
using namespace std;

// Function to find the majority element using Moore's Voting Algorithm
int majorityElement(const vector<int>& nums) {
    int count = 0, candidate = 0;

    // Phase 1: Find a candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Phase 2: Confirm the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    return (count > nums.size() / 2) ? candidate : -1; // Return -1 if no majority element found
}

int main() {
    vector<int> nums = {3, 2, 3}; // Example input
    int result = majorityElement(nums);
    cout << "Majority Element: " << result << endl;
    return 0;
}
