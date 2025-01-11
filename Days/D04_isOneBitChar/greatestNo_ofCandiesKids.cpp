
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/


#include <vector>
#include <algorithm> // For std::max_element
#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end()); // Find the maximum 

        vector<bool> result(candies.size()); // Initialize the result vector

        for (int i = 0; i < candies.size(); i++) {
            // Check if the current kid can have the greatest number of candies
            if(candies[i] + extraCandies >= maxCandies) {
                result[i] = true;
            } else {
                result[i] = false;
            }

        }

        return result;
    }
};

//brute force approach
// time complexity = O(n), spcae = O(1)
