

// Qno 42  https://leetcode.com/problems/trapping-rain-water/


// concept: PREFIX Array kismai pahle hi hm two array ke liye two vector lete h Auxiliary Space array


//method1: Naive 
//method2: better -- TC=O(n) = SC  using two pointer approach
class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            if (n == 0) return 0; // Handle edge case where height is empty
    
            vector<int> lmax(n, 0);
            vector<int> rmax(n, 0);
    
            // Initialize left max and right max values
            lmax[0] = height[0];
            rmax[n-1] = height[n-1];
    
            // Fill in the left maximum values
            for (int i = 1; i < n; i++) {
                lmax[i] = max(lmax[i-1], height[i]);
            }
    
            // Fill in the right maximum values
            for (int i = n-2; i >= 0; i--) {
                rmax[i] = max(rmax[i+1], height[i]);
            }
    
            // Calculate the total water trapped
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += min(lmax[i], rmax[i]) - height[i];
            }
    
            return ans;
        }
    };
    

    /*

 Naive typically refers to the simplest, unoptimized solution.
Brute force refers specifically to an exhaustive, combinatorial approach that tries all possibilities.
    

    */



//method3: optimal (two pointer)

class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            if (n == 0) return 0;
    
            int left = 0, right = n - 1;
            int left_max = 0, right_max = 0;
            int ans = 0;
    
            while (left <= right) {
                if (height[left] < height[right]) {
                    if (height[left] >= left_max) {
                        left_max = height[left];
                    } else {
                        ans += left_max - height[left];
                    }
                    left++;
                } else {
                    if (height[right] >= right_max) {
                        right_max = height[right];
                    } else {
                        ans += right_max - height[right];
                    }
                    right--;
                }
            }
    
            return ans;
        }
    };
    