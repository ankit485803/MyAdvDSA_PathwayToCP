


/*


30th Dec 2025 (Tuesday)


qno 1351  https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/


1351. Count Negative Numbers in a Sorted Matrix
Solved
Easy
Topics

Companies
Hint
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
 

Follow up: Could you find an O(n + m) solution?





*/


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {  //O(m*n), sc=O(1)
        int m = grid.size();
        int n = grid[0].size();  //firstBox

        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] < 0) {   //whenNegative
                    count++;
                } else {
                    break;
                }
            }
        }

        return count;
    }
};






class Solution {  //O(m+ n)
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        int row = 0, col = n - 1;
        
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += (n - col); // All elements to the left of grid[row][col] are negative
                row++; // Move down to the next row
            } else {
                col--; // Move left if the current element is non-negative
            }
        }
        
        return count;
    }
};





/*


qno 84  https://leetcode.com/problems/largest-rectangle-in-histogram/description/


4. Largest Rectangle in Histogram
Solved
Hard
Topics

Companies
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
 
Discover more
Algorithm and data structure guides
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,410,048/2.9M
Acceptance Rate
48.9%
Topics
Array
Stack
Monotonic Stack



*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);  //left smaller nearest
        vector<int> right(n, 0); //right smaller nearest
        stack<int> s;


        //RIGHT smaller start karo BACKWARD loop
        for(int i=n-1; i>=0; i--) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()) {
            s.pop();
        }


        //left smaller
        for(int i=0; i<n; i++) {  //O(n )
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        
        return ans;
    }
};

// TC = O(n), SC = O(n)





/*

qno 3   https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


3. Longest Substring Without Repeating Characters
Medium
Topics

Companies
Hint
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
8,674,849/22.8M
Acceptance Rate
38.1%
Topics
Hash Table
String
Sliding Window




*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIdx(256, -1);  // stores last seen index of characters
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            // If character was seen and is inside curr window
            if (lastIdx[s[right]] >= left) {
                left = lastIdx[s[right]] + 1;
            }

            lastIdx[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};





/*



qno 2760   https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/


2760. Longest Even Odd Subarray With Threshold
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums and an integer threshold.

Find the length of the longest subarray of nums starting at index l and ending at index r (0 <= l <= r < nums.length) that satisfies the following conditions:

nums[l] % 2 == 0
For all indices i in the range [l, r - 1], nums[i] % 2 != nums[i + 1] % 2
For all indices i in the range [l, r], nums[i] <= threshold
Return an integer denoting the length of the longest such subarray.

Note: A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [3,2,5,4], threshold = 5
Output: 3
Explanation: In this example, we can select the subarray that starts at l = 1 and ends at r = 3 => [2,5,4]. This subarray satisfies the conditions.
Hence, the answer is the length of the subarray, 3. We can show that 3 is the maximum possible achievable length.
Example 2:

Input: nums = [1,2], threshold = 2
Output: 1
Explanation: In this example, we can select the subarray that starts at l = 1 and ends at r = 1 => [2]. 
It satisfies all the conditions and we can show that 1 is the maximum possible achievable length.
Example 3:

Input: nums = [2,3,4,5], threshold = 4
Output: 3
Explanation: In this example, we can select the subarray that starts at l = 0 and ends at r = 2 => [2,3,4]. 
It satisfies all the conditions.
Hence, the answer is the length of the subarray, 3. We can show that 3 is the maximum possible achievable length.
 

Constraints:

1 <= nums.length <= 100 
1 <= nums[i] <= 100 
1 <= threshold <= 100



*/



class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) { //greedy tc=O(n), sc=O(1) 
        int maxLen = 0;
        int currLen = 0;
        int prevParity = -1; // 0 = even, 1 = odd

        for (int num : nums) {
            if (num > threshold) {
                // Cannot include this number
                currLen = 0;
                prevParity = -1;
                continue;
            }

            int parity = num % 2;

            if (currLen == 0) {
                // Start only if the number is even
                if (parity == 0) {
                    currLen = 1;
                    prevParity = parity;
                    maxLen = max(maxLen, currLen);
                }
            } else {
                // Check alternating parity
                if (parity != prevParity) {
                    currLen++;
                    prevParity = parity;
                    maxLen = max(maxLen, currLen);
                } else {
                    // Restart if current number is even
                    if (parity == 0) {
                        currLen = 1;
                        prevParity = parity;
                        maxLen = max(maxLen, currLen);
                    } else {
                        currLen = 0;
                        prevParity = -1;
                    }
                }
            }
        }

        return maxLen;
    }
};
