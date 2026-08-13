// 7th June 2026 (Sunday)
link: https://www.instagram.com/reel/DZSPqZ0Bqjn


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach 1: Using Map
// Hint: Count the frequency of every element.
// The elements with frequency = 1 are the two unique numbers.
void uniqueNum2UsingMap(const vector<int>& nums) {
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    cout << "Using Map: ";

    for (auto& [num, count] : freq) {
        if (count == 1) {
            cout << num << " ";
        }
    }

    cout << endl;
}


// Approach 2: Using XOR Operator
// Hint:
// 1. XOR all elements -> duplicate numbers cancel each other.
// 2. The result contains the XOR of the two unique numbers.
// 3. Find the rightmost set bit to separate them into two groups.
// 4. XOR each group separately to get the two unique numbers.
void uniqueNum2UsingXOR(const vector<int>& nums) {
    int xorAll = 0;

    // Step 1: XOR all elements
    for (int num : nums) {
        xorAll ^= num;
    }

    // Step 2: Find the rightmost set bit
    int mask = xorAll & (-xorAll);

    int first = 0;
    int second = 0;

    // Step 3: Divide elements into two groups
    for (int num : nums) {
        if (num & mask) {
            first ^= num;
        } else {
            second ^= num;
        }
    }

    cout << "Using XOR: " << first << " " << second << endl;
}


int main() {
    vector<int> A = {1, 2, 3, 4, 7, 3, 2, 1};

    uniqueNum2UsingMap(A);
    uniqueNum2UsingXOR(A);

    return 0;
}