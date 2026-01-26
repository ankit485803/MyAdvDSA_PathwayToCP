



/*


26th Jan 2026 (MOnday - happyRepublicDay)

from from weekly contest https://leetcode.com/contest/weekly-contest-486/



qno 3819   https://leetcode.com/problems/rotate-non-negative-elements/


3819. Rotate Non Negative Elements
Medium

Companies
Hint
You are given an integer array nums and an integer k.

Rotate only the non-negative elements of the array to the left by k positions, in a cyclic manner.

All negative elements must stay in their original positions and must not move.

After rotation, place the non-negative elements back into the array in the new order, filling only the positions that originally contained non-negative values and skipping all negative positions.

Return the resulting array.

 

Example 1:

Input: nums = [1,-2,3,-4], k = 3

Output: [3,-2,1,-4]

Explanation:​​​​​​​

The non-negative elements, in order, are [1, 3].
Left rotation with k = 3 results in:
[1, 3] -> [3, 1] -> [1, 3] -> [3, 1]
Placing them back into the non-negative indices results in [3, -2, 1, -4].
Example 2:

Input: nums = [-3,-2,7], k = 1

Output: [-3,-2,7]

Explanation:

The non-negative elements, in order, are [7].
Left rotation with k = 1 results in [7].
Placing them back into the non-negative indices results in [-3, -2, 7].
Example 3:

Input: nums = [5,4,-9,6], k = 2

Output: [6,5,-9,4]

Explanation:

The non-negative elements, in order, are [5, 4, 6].
Left rotation with k = 2 results in [6, 5, 4].
Placing them back into the non-negative indices results in [6, 5, -9, 4].
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
0 <= k <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
30,758/64.6K
Acceptance Rate
47.6%
Topics
Weekly Contest 486


*/



class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {  //tc=O(n)=sc
        vector<int> nonNeg;
        
        //step1: collect non-negative elements
        for (int x : nums) {
            if (x >= 0) {
                nonNeg.push_back(x);
            }
        }

        int m = nonNeg.size();
        if (m == 0) return nums;

        //step2: handle large k
        k %= m;
        if (k == 0) return nums;

        //step3: left rotate non-negative elements
        vector<int> rotated;
        for (int i = k; i < m; i++)
            rotated.push_back(nonNeg[i]);
        for (int i = 0; i < k; i++)
            rotated.push_back(nonNeg[i]);

        //step4: place back into original array
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = rotated[idx++];
            }
        }

        return nums;
    }
};







/*


qno 3821  https://leetcode.com/problems/find-nth-smallest-integer-with-k-one-bits/


3821. Find Nth Smallest Integer With K One Bits
Hard

Companies
Hint
You are given two positive integers n and k.

Return an integer denoting the nth smallest positive integer that has exactly k ones in its binary representation. It is guaranteed that the answer is strictly less than 250.

 

Example 1:

Input: n = 4, k = 2

Output: 9

Explanation:

The 4 smallest positive integers that have exactly k = 2 ones in their binary representations are:

3 = 112
5 = 1012
6 = 1102
9 = 10012
Example 2:

Input: n = 3, k = 1

Output: 4

Explanation:

The 3 smallest positive integers that have exactly k = 1 one in their binary representations are:

1 = 12
2 = 102
4 = 1002
 

Constraints:

1 <= n <= 250
1 <= k <= 50
The answer is strictly less than 250.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
6,064/19.8K
Acceptance Rate
30.7%
Topics
Weekly Contest 486



Strategy (Combinatorics + Greedy)
Precompute combinations C[n][r] (Pascal triangle).


*/



class Solution {
public:
    long long C[55][55];

    void buildCombinations() {
        for (int i = 0; i <= 50; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    long long nthSmallest(long long n, int k) {  //tc=O(n*50), sc=O(50 * 50)
        buildCombinations();

        long long ans = 0;
        int bitsLeft = k;

        // we go from highest possible bit down to 0
        for (int pos = 50; pos >= 0; pos--) {
            if (bitsLeft == 0) break;

            // count numbers if we DON'T set this bit
            long long count = C[pos][bitsLeft];

            if (count < n) {
                // we must set this bit
                ans |= (1LL << pos);
                n -= count;
                bitsLeft--;
            }
            // else: keep bit 0 and move on
        }

        return ans;
    }
};



/*


qno 881 https://leetcode.com/problems/boats-to-save-people/description/


881. Boats to Save People
Solved
Medium
Topics

Companies
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
 

Constraints:

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
536,581/876.7K
Acceptance Rate
61.2%
Topics
Array
Two Pointers
Greedy
Sorting
Weekly Contest 96



*/



class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int i=0;
        int j = people.size()-1;

        int boats = 0;  //reqNo

        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                i++;  // lightest is paired
            }
            j--;  //every time → heaviest always boards a boat
            boats++;
        }

        return boats;
    }
};




/*

qno 2335  https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/


2335. Minimum Amount of Time to Fill Cups
Easy
Topics
premium lock icon
Companies
Hint
You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.

 

Example 1:

Input: amount = [1,4,2]
Output: 4
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.
Example 2:

Input: amount = [5,4,4]
Output: 7
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup, and a hot cup.
Second 2: Fill up a cold cup, and a warm cup.
Second 3: Fill up a cold cup, and a warm cup.
Second 4: Fill up a warm cup, and a hot cup.
Second 5: Fill up a cold cup, and a hot cup.
Second 6: Fill up a cold cup, and a warm cup.
Second 7: Fill up a hot cup.
Example 3:

Input: amount = [5,0,0]
Output: 5
Explanation: Every second, we fill up a cold cup.
 

Constraints:

amount.length == 3
0 <= amount[i] <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
65,777/109.8K
Acceptance Rate
59.9%
Topics
Array
Greedy
Sorting
Heap (Priority Queue)
Weekly Contest 301



*/



class Solution {
public:
    int fillCups(vector<int>& amount) {  //tc=O(1)=sc
        int sum = amount[0] + amount[1] + amount[2];
        int mx = max({amount[0], amount[1], amount[2]});

        return max(mx, (sum + 1) / 2);
    }
};





/*


qno 1200  https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26


1200. Minimum Absolute Difference
Solved
Easy
Topics

Companies
Hint
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 

Constraints:

2 <= arr.length <= 105
-106 <= arr[i] <= 106
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
291,268/405.7K
Acceptance Rate
71.8%
Topics
Array
Sorting
Weekly Contest 155



*/



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {  //tc=O(n logN), sc=O(n) due ans vector
        sort(arr.begin(), arr.end()); 

        int minDiff = INT_MAX;
        vector<vector<int>> ans;

        for (int i = 1; i < arr.size(); ++i) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                // Found a new minimum difference
                minDiff = diff;
                ans.clear();  
                ans.push_back({arr[i - 1], arr[i]});
            } else if (diff == minDiff) {
                // Same as the current minimum, so add this pair
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};
