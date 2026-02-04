


/*


4th Feb 2026 (Wednesday)


qno 3200  https://leetcode.com/problems/maximum-height-of-a-triangle/


3200. Maximum Height of a Triangle
Easy
Topics

Companies
Hint
You are given two integers red and blue representing the count of red and blue colored balls. You have to arrange these balls to form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.

All the balls in a particular row should be the same color, and adjacent rows should have different colors.

Return the maximum height of the triangle that can be achieved.

 

Example 1:

Input: red = 2, blue = 4

Output: 3

Explanation:



The only possible arrangement is shown above.

Example 2:

Input: red = 2, blue = 1

Output: 2

Explanation:


The only possible arrangement is shown above.

Example 3:

Input: red = 1, blue = 1

Output: 1

Example 4:

Input: red = 10, blue = 1

Output: 2

Explanation:


The only possible arrangement is shown above.

 

Constraints:

1 <= red, blue <= 100
 
Discover more
Developer Community Forum
Seen this question in a real interview before?
1/5
Yes
No
Accepted
43,629/98.9K
Acceptance Rate
44.1%
Topics
Mid Level
Array
Enumeration
Weekly Contest 404


*/



class Solution {
public:
    int simulate(int red, int blue, bool startRed) {
        int height = 0;
        int row = 1;
        bool isRed = startRed;

        while (true) {
            if (isRed) {
                if (red < row) break;
                red -= row;
            } else {
                if (blue < row) break;
                blue -= row;
            }
            height++;
            row++;
            isRed = !isRed;
        }
        return height;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(simulate(red, blue, true),
                   simulate(red, blue, false));
    }
};





class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int r1 = red, b1 = blue;
        int r2 = red, b2 = blue;

        // Case 1: blue on odd levels, red on even levels
        int i = 1;
        while (true) {
            if (i % 2 == 0) {
                if (r1 < i) break;
                r1 -= i;
            } else {
                if (b1 < i) break;
                b1 -= i;
            }
            i++;
        }

        // Case 2: red on odd levels, blue on even levels
        int j = 1;
        while (true) {
            if (j % 2 == 0) {
                if (b2 < j) break;
                b2 -= j;
            } else {
                if (r2 < j) break;
                r2 -= j;
            }
            j++;
        }

        return max(i - 1, j - 1);
    }
};



/*

qno 3640  https://leetcode.com/problems/trionic-array-ii/?envType=daily-question&envId=2026-02-04



3640. Trionic Array II
Hard
Topics

Companies
Hint
You are given an integer array nums of length n.

A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:

nums[l...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...r] is strictly increasing.
Return the maximum sum of any trionic subarray in nums.

 

Example 1:

Input: nums = [0,-2,-1,-3,0,2,-1]

Output: -4

Explanation:

Pick l = 1, p = 2, q = 3, r = 5:

nums[l...p] = nums[1...2] = [-2, -1] is strictly increasing (-2 < -1).
nums[p...q] = nums[2...3] = [-1, -3] is strictly decreasing (-1 > -3)
nums[q...r] = nums[3...5] = [-3, 0, 2] is strictly increasing (-3 < 0 < 2).
Sum = (-2) + (-1) + (-3) + 0 + 2 = -4.
Example 2:

Input: nums = [1,4,2,7]

Output: 14

Explanation:

Pick l = 0, p = 1, q = 2, r = 3:

nums[l...p] = nums[0...1] = [1, 4] is strictly increasing (1 < 4).
nums[p...q] = nums[1...2] = [4, 2] is strictly decreasing (4 > 2).
nums[q...r] = nums[2...3] = [2, 7] is strictly increasing (2 < 7).
Sum = 1 + 4 + 2 + 7 = 14.
 

Constraints:

4 <= n = nums.length <= 105
-109 <= nums[i] <= 109
It is guaranteed that at least one trionic subarray exists.
 
Discover more
Data structures and algorithms books
Seen this question in a real interview before?
1/5
Yes
No
Accepted
39,763/95.9K
Acceptance Rate
41.5%
Topics
Senior Staff
Array
Dynamic Programming
Weekly Contest 461


*/



//Approach (Recursion + Memoization)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> memo;

    ll solve(int i, int trend, vector<int>& nums) {
        if(i == n) {
            if(trend == 3) {
                return 0; //no more elements, you reached out of bound
            } else {
                return LLONG_MIN/2; //invalid small value
            }
        }

        if(memo[i][trend] != LLONG_MIN) {
            return memo[i][trend];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        //skip
        if(trend == 0) {
            skip = solve(i+1, 0, nums);
        }

        //i am at trend 3 and i can now end at nums[i]
        if(trend == 3) {
            take = nums[i]; //finish it here
        }

        if(i+1 < n) {
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && next > curr) {
                take = max(take, curr + solve(i+1, 1, nums));
            } else if(trend == 1) {
                if(next > curr) {
                    take = max(take, curr + solve(i+1, 1, nums));
                } else if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                }
            } else if(trend == 2) {
                if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                } else if(next > curr) {
                    take = max(take, curr + solve(i+1, 3, nums));
                }
            } else if(trend == 3 && next > curr) {
                take = max(take, curr + solve(i+1, 3, nums));
            }
        }
        
        return memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        memo.assign(n+1, vector<ll>(4, LLONG_MIN));

        return solve(0, 0, nums); //solve(i, trend = 0)
    }
};
