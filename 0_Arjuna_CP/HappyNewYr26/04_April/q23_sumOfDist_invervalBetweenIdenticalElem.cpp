


/*

23rd April 2026 (Thursday)


qno 2615  https://leetcode.com/problems/sum-of-distances/description/?envType=daily-question&envId=2026-04-23

2615. Sum of Distances
Medium
Topics

Companies
Hint
You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.

 

Example 1:

Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation: 
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2. 

Example 2:

Input: nums = [0,5,3]
Output: [0,0,0]
Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
 

Note: This question is the same as 2121: Intervals Between Identical Elements.

 
Discover more
Coding practice platform
Seen this question in a real interview before?
1/6
Yes
No
Accepted
40,271/107.2K
Acceptance Rate
37.6%
Topics
Senior
Array
Hash Table
Prefix Sum
Weekly Contest 340


*/

my fist approach: bruteForce using twoPointer
int i = 0; j = 1;
vector<int> ans;
if(num[i] == num[j]) the calclate diff then j ++ 



class Solution {
public:
    vector<long long> distance(vector<int>& nums) {  //bruteForce approach O(n^2) tc, sc=O(1) give TLE
        int n = nums.size();
        vector<long long> ans(n, 0);

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] == nums[j]) {
                    sum += abs(i - j);
                }
            }
            
            ans[i] = sum;
        }

        return ans;
    }
};




class Solution {
public:
    typedef long long ll;
    vector<ll> distance(vector<int>& nums) {  //O(N) = tc = sc
        int n = nums.size();
        vector<ll> arr(n, 0);

        unordered_map<int, ll> idxSum;  //nums[i] -> sum of 1's
        unordered_map<int, ll> idxCount;  //nums[i] -> freq

        //left to right LHS  
        for(int i = 0; i < n; i++) {
            ll freq = idxCount[nums[i]];
            ll sum = idxSum[nums[i]];

            //yahi formula banaye the
            arr[i] += freq * i - sum;

            idxCount[nums[i]] += 1;
            idxSum[nums[i]] += i;
        }

        //pahle clearMap
        idxSum.clear();
        idxCount.clear();

        //righToLeft  RHS
        for(int i = n-1; i >= 0; i--) {
            ll freq = idxCount[nums[i]];
            ll sum = idxSum[nums[i]];

            //formula
            arr[i] += sum - freq * i;

            idxCount[nums[i]] += 1;
            idxSum[nums[i]] += i;
        }

        return arr;
    }
};



/* qno 2121  https://leetcode.com/problems/intervals-between-identical-elements/description/


2121. Intervals Between Identical Elements
Medium
Topics

Companies
Hint
You are given a 0-indexed array of n integers arr.

The interval between two elements in arr is defined as the absolute difference between their indices. More formally, the interval between arr[i] and arr[j] is |i - j|.

Return an array intervals of length n where intervals[i] is the sum of intervals between arr[i] and each element in arr with the same value as arr[i].

Note: |x| is the absolute value of x.

 

Example 1:

Input: arr = [2,1,3,1,2,3,3]
Output: [4,2,7,2,4,4,5]
Explanation:
- Index 0: Another 2 is found at index 4. |0 - 4| = 4
- Index 1: Another 1 is found at index 3. |1 - 3| = 2
- Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
- Index 3: Another 1 is found at index 1. |3 - 1| = 2
- Index 4: Another 2 is found at index 0. |4 - 0| = 4
- Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
- Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5
Example 2:

Input: arr = [10,5,10,10]
Output: [5,0,3,4]
Explanation:
- Index 0: Two more 10s are found at indices 2 and 3. |0 - 2| + |0 - 3| = 5
- Index 1: There is only one 5 in the array, so its sum of intervals to identical elements is 0.
- Index 2: Two more 10s are found at indices 0 and 3. |2 - 0| + |2 - 3| = 3
- Index 3: Two more 10s are found at indices 0 and 2. |3 - 0| + |3 - 2| = 4
 

Constraints:

n == arr.length
1 <= n <= 105
1 <= arr[i] <= 105
 

Note: This question is the same as 2615: Sum of Distances.

 
Discover more
Programming Interview Prep
Seen this question in a real interview before?
1/6
Yes
No
Accepted
27,798/60.4K
Acceptance Rate
46.0%
Topics
Staff
Array
Hash Table
Prefix Sum
Weekly Contest 273

*/



class Solution {
public:
    typedef long long ll;

    vector<ll> getDistances(vector<int>& arr) {  //tc=O(n)=sc
        int n = arr.size();
        vector<ll> ans(n, 0);

        unordered_map<int, ll> idxSum;
        unordered_map<int, ll> idxCount;

        // Left → Right
        for (int i = 0; i < n; i++) {
            ll freq = idxCount[arr[i]];
            ll sum = idxSum[arr[i]];

            ans[i] += freq * i - sum;

            idxCount[arr[i]]++;
            idxSum[arr[i]] += i;
        }

        // Clear maps
        idxSum.clear();
        idxCount.clear();

        // Right → Left
        for (int i = n - 1; i >= 0; i--) {
            ll freq = idxCount[arr[i]];
            ll sum = idxSum[arr[i]];

            ans[i] += sum - freq * i;

            idxCount[arr[i]]++;
            idxSum[arr[i]] += i;
        }

        return ans;
    }
};