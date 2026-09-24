

// 24th Sep 2026 (Thursday)
qno 3550 https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index

class Solution {
public:
    // Helper function to calculate sum of digits
    int getDigitSum(int num) { // tc=O(no of digits in nums * no of elem in nums), sc=O(1)
        int sum = 0;

        while (num > 0) {
            int last = num % 10;
            sum += last;
            num /= 10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {

            // Calculate digit sum of nums[i]
            int sum = getDigitSum(nums[i]);

            // Check if digit sum is equal to index
            if (sum == i) {
                return i;
            }
        }

        return -1;
    }
};




//check smallest
class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int ans = -1;

        for (int i = 0; i < nums.size(); i++) {
            int sum = getDigitSum(nums[i]);

            if (sum == i) {
                if (ans == -1) {
                    ans = i;
                }
                else {
                    ans = min(ans, i);
                }
            }
        }

        return ans;
    }
};

