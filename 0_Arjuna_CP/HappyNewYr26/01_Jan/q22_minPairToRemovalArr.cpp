


/*


22nd Jan 2026 (Thursday)



qno 3507  https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/?envType=daily-question&envId=2026-01-22

3507. Minimum Pair Removal to Sort Array I
Easy
Topics

Companies
Hint
Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

The array nums is already sorted.

 

Constraints:

1 <= nums.length <= 50
-1000 <= nums[i] <= 1000




*/



class Solution {
public:
    bool isNonDecreasing(const vector<int>& nums) {  //tc=O(n^3), sc=O(n)

        for (int i = 1; i < nums.size(); i++) { //O(n^2)
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int idx = 0;

            // Find leftmost adjacent pair with minimum sum
            for (int i = 0; i + 1 < nums.size(); i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // Replace the pair with their sum
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            ops++;
        }

        return ops;
    }
};






/*

qno 3510   https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/


3510. Minimum Pair Removal to Sort Array II
Hard
Topics

Companies
Hint
Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

The array nums is already sorted.

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
4,351/28K
Acceptance Rate
15.6%
Topics
Array
Hash Table
Linked List
Heap (Priority Q



*/




class Solution {
public:
    struct Pair {
        long long sum;
        int i;
        bool operator>(const Pair& other) const {
            return sum > other.sum;
        }
    };

    int minimumPairRemoval(vector<int>& nums) {  //tc=O(nlogN), sc=O(1)
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> val(nums.begin(), nums.end());
        vector<int> prev(n), next(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = (i + 1 < n ? i + 1 : -1);
        }

        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({val[i] + val[i + 1], i});
        }

        int violations = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (val[i] > val[i + 1]) violations++;
        }

        int ops = 0;

        while (violations > 0) {
            auto [s, i] = pq.top();
            pq.pop();

            if (!alive[i]) continue;
            int j = next[i];
            if (j == -1 || !alive[j]) continue;
            if (val[i] + val[j] != s) continue;

            // Fix violations before merge
            if (prev[i] != -1 && val[prev[i]] > val[i]) violations--;
            if (val[i] > val[j]) violations--;
            if (next[j] != -1 && val[j] > val[next[j]]) violations--;

            // Merge i and j
            val[i] += val[j];
            alive[j] = false;

            next[i] = next[j];
            if (next[j] != -1) prev[next[j]] = i;

            // Add new violations after merge
            if (prev[i] != -1 && val[prev[i]] > val[i]) violations++;
            if (next[i] != -1 && val[i] > val[next[i]]) violations++;

            // Push new adjacent sums
            if (prev[i] != -1) {
                pq.push({val[prev[i]] + val[i], prev[i]});
            }
            if (next[i] != -1) {
                pq.push({val[i] + val[next[i]], i});
            }

            ops++;
        }

        return ops;
    }
};
