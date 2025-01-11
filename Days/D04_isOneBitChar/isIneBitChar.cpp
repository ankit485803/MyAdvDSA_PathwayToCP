

// https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
// Qno = 717

// approach = Greedy apprach + arrary

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        // Traverse the bits array
        while (i < bits.size() - 1) {
            // Move forward: if bits[i] is 0, move 1 step; if 1, move 2 steps
            i += bits[i] + 1;
        }
        // If we end on the last bit, it's a one-bit character
        return i == bits.size() - 1;
    }
};

// greedy approach effectively determines whether the last character is a one-bit character by iterating through the bits with simple conditions, making it both efficient and easy to understand.

// time complex = O(n), space = O(1)
