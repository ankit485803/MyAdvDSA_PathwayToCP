

// qno 287   leetcode.com/problems/find-the-duplicate-number
// Floyd's Tortoise and Hare 

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {  //TC=O(n), SC = (n)
        
        unordered_set<int> s;

        for(int val : nums) {
            if(s.find(val) != s.end()) {
                return val;
            }

            s.insert(val);

        }

        return -1;
    }
};



#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Phase 1: Detect cycle using slow and fast pointers
        do {
            slow = nums[slow];          // Move slow pointer by 1 step
            fast = nums[nums[fast]];    // Move fast pointer by 2 steps
        } while (slow != fast);          // Continue until they meet

        // Phase 2: Find the entry point to the cycle (duplicate number)
        slow = nums[0];                   // Reset slow pointer to the start of the array

        while (slow != fast) {
            slow = nums[slow];            // Move slow pointer by 1 step
            fast = nums[fast];            // Move fast pointer by 1 step
        }

        return slow;                      // The duplicate number
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 4, 2, 2};
    
    cout << "Duplicate number: " << solution.findDuplicate(nums) << endl;
    
    return 0;
}

//TC=O(N), SC = O(1) , using Slow-Fast approach