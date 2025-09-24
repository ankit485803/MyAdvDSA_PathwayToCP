



/*

25th Sep 2025 (Wednesday - thirdDay Puja Navratri)

qno 1858   https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

concept req: Sliding window 
an efficient method to process continuous subsets of data, typically arrays or strings, by maintaining a "window" of elements that moves through the data


step1: Sort nums.

step2: Maintain a window [l..r]:
cost = (nums[r]×(r−l+1)) − sum of window

If cost > k, shrink from the left (l++).


step3:  Track the maximum window length.





*/



class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;  // sum of current window
        int l = 0, ans = 1;   // ans will store the max frequency, l = left pointer and r = right pointer window

        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];

            // shrink window if cost > k
            while ((long long)nums[r] * (r - l + 1) - total > k) {
                total -= nums[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};




/*  Use Window Sliding concepts

Sorting: O(n log n)
Sliding window: O(n)

Total: O(n log n)
Space: O(1)


*/