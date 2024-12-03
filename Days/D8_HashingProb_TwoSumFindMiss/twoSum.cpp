
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>


// Two sum prob, concept used -- Hashing (set + map)

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

solution: 1. Brute force approach -- O(n^2)
2. Better -- two pointer apprach - using sorting -- O(nlogn)
3. optimal - HASHING


*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];  
            
            //  the next element to avoid using the same element twice
            for (int j = i + 1; j < nums.size(); j++) {
                int second = nums[j];  // Second number
                
                // If the sum equals the target, return the indices
                int sum = first + second;
                if (sum == target) {
                    return {i, j};  // Indices of the two numbers
                }
            }
        }
        
        // If no solution is found, return an empty vector (although problem guarantees a solution)
        return {};
    }
};

//using Brute force approach - O(n^2)


//method2: better - Two pointer approach



#include <iostream>
#include <vector>
#include <algorithm>  // for std::sort
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a vector of pairs to store the value and its original index
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndex.push_back({nums[i], i});
        }

        // Sort the array based on the values, maintaining original indices
        sort(numsWithIndex.begin(), numsWithIndex.end());

        // Two-pointer technique
        int st = 0, end = numsWithIndex.size() - 1;

        while (st < end) {
            int sum = numsWithIndex[st].first + numsWithIndex[end].first;

            if (sum == target) {
                // Return the original indices
                return {numsWithIndex[st].second, numsWithIndex[end].second};
            } else if (sum < target) {
                st++;
            } else {
                end--;
            }
        }
        
        // If no solution is found, return an empty vector (although problem guarantees a solution)
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> arr = {5, 2, 11, 7, 15};
    int target = 9;
    
    vector<int> result = solution.twoSum(arr, target);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}

// complex: Sorting arr takes = O(nlogn), two-pointer scan through arr = O(n), overall == O(nlogn) due to the sorting step



//method3: Hashing
// HASTING (map, set) -- jiska kam h Complex ko O(1) CONSTANT bana dena when m.find()

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {  //overall complex = O(n) using HASHING 
        
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i=0; i<arr.size(); i++) { // O(n)
            int first = arr[i];
            int second = tar - first;

            if(m.find(second) != m.end()) {  //O(1)
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }

            //if not break, then store map with its index value
            m[first] = i;
        }

        return ans;
    }
};


