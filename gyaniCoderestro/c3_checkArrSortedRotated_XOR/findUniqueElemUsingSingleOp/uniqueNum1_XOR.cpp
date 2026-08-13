

// 2nd June 2026 (Tuesday)
Link: https://www.instagram.com/reel/DZFU4vdh_c0/?utm_source=ig_web_copy_link


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach 1: Using unordered_map tc=sc= O(n)

int findUniqueUsingMap(const vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    for (auto& [num, count] : freq) {
        if (count == 1) {
            return num;
        }
    }

    return -1;
}

// Approach 2: Using XOR tc= O(n), sc=O(1)
int findUniqueUsingXOR(const vector<int>& nums) {
    int ans = 0;

    for (int num : nums) {
        ans ^= num;
    }

    return ans;
}

int main() {
    vector<int> A = {2, 3, 4, 3, 2};

    cout << "Using Map: " << findUniqueUsingMap(A) << endl;
    cout << "Using XOR: " << findUniqueUsingXOR(A) << endl;

    return 0;
}