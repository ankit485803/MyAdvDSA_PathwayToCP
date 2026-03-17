


/*


17th March 2026 (Tuesday)


qno 1727  https://leetcode.com/problems/largest-submatrix-with-rearrangements/?envType=daily-question&envId=2026-03-17


1727. Largest Submatrix With Rearrangements
Medium
Topics

Companies
Hint
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

 

Example 1:


Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
Example 2:


Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
Example 3:

Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m * n <= 105
matrix[i][j] is either 0 or 1.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
80,928/107.2K
Acceptance Rate
75.5%
Topics
Staff
Array
Greedy
Sorting
Matrix
Weekly Contest 224



Key Idea
Build heights matrix
For each cell, count consecutive 1s above it.
If matrix[i][j] == 1 → height[i][j] = height[i-1][j] + 1
Else height = 0.

For each row
Sort the heights descending (simulate optimal column rearrangement).

For each column j, compute area:
area=height[j]×(j+1)

Track the maximum area.
*/


// bruteForce
// step1: sortMatrix so that 1s will come to onePlace and if not make TRANSFORMATION cols wise
// step2: define int l = total no of rows, b = toal cols, in submatrix
// step3: return ar = l*b


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {  //tc=O(m* nLogN), sc=O(n)
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] && i > 0) {
                    matrix[i][j] += matrix[i-1][j];   //heightMatrix
                }
            }

            vector<int> row = matrix[i];
            sort(row.begin(), row.end(), greater<int>());

            for(int j=0; j<n; j++) {
                ans = max(ans, row[j] * (j + 1)); //greedy about Area = height[j] * [j+1]
            }
        }

        return ans;
    }
};




/*

qno 3866  https://leetcode.com/problems/first-unique-even-element/

3866. First Unique Even Element
Easy

Companies
You are given an integer array nums.

Return an integer denoting the first even integer (earliest by array index) that appears exactly once in nums. If no such integer exists, return -1.

An integer x is considered even if it is divisible by 2.

 

Example 1:

Input: nums = [3,4,2,5,4,6]

Output: 2

Explanation:

Both 2 and 6 are even and they appear exactly once. Since 2 occurs first in the array, the answer is 2.

Example 2:

Input: nums = [4,4]

Output: -1

Explanation:

No even integer appears exactly once, so return -1.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
36,034/54.7K
Acceptance Rate
65.9%
Topics
Mid Level
Biweekly Contest 178


*/


class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {  //myFirsttime
        vector<int> even;
        for(int i=0; i<nums.size(); i++) {
            int freq = 1;  //countFreq of eachElem

            if(nums[i] % 2 == 0) {
                even.push_back(nums[i]);
            }
        }
    }
};





class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++) {  //tc=O(n^2) dueToNestedLoop, sc=O(1)
            if(nums[i] % 2 == 0) {
                int freq = 0;

                for(int j=0; j<nums.size(); j++) {
                    if(nums[i] == nums[j]) {  //twoElem eq
                        freq++;
                    }
                }

                if(freq == 1) {
                    return nums[i];
                }
            }
        }

        return -1;
    }
};




class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {  //tc=O(n), sc=O(101)

        vector<int> freq(101, 0);

        for(int num : nums)
            freq[num]++;

        for(int num : nums) {
            if(num % 2 == 0 && freq[num] == 1)
                return num;
        }

        return -1;
    }
};



class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {  //tc=O(logN), sc=O(1)
        int n = nums.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(int x:nums){
            if(x%2==0 && mp[x]==1){
                return x;
            }
        }
        return -1;
    }
};





/*


qno 3867  https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/




3867. Sum of GCD of Formed Pairs
Medium

Companies
Hint
You are given an integer array nums of length n.

Construct an array prefixGcd where for each index i:

Let mxi = max(nums[0], nums[1], ..., nums[i]).
prefixGcd[i] = gcd(nums[i], mxi).
After constructing prefixGcd:

Sort prefixGcd in non-decreasing order.
Form pairs by taking the smallest unpaired element and the largest unpaired element.
Repeat this process until no more pairs can be formed.
For each formed pair, compute the gcd of the two elements.
If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
Return an integer denoting the sum of the GCD values of all formed pairs.

The term gcd(a, b) denotes the greatest common divisor of a and b.
 

Example 1:

Input: nums = [2,6,4]

Output: 2

Explanation:

Construct prefixGcd:

i	nums[i]	mxi	prefixGcd[i]
0	2	2	2
1	6	6	6
2	4	6	2
prefixGcd = [2, 6, 2]. After sorting, it forms [2, 2, 6].

Pair the smallest and largest elements: gcd(2, 6) = 2. The remaining middle element 2 is ignored. Thus, the sum is 2.

Example 2:

Input: nums = [3,6,2,8]

Output: 5

Explanation:

Construct prefixGcd:

i	nums[i]	mxi	prefixGcd[i]
0	3	3	3
1	6	6	6
2	2	6	2
3	8	8	8
prefixGcd = [3, 6, 2, 8]. After sorting, it forms [2, 3, 6, 8].

Form pairs: gcd(2, 8) = 2 and gcd(3, 6) = 3. Thus, the sum is 2 + 3 = 5.

 

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= 10​​​​​​​9
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
26,532/40.9K
Acceptance Rate
64.8%
Topics
Senior
Biweekly Contest 178


*/




class Solution {
public:
    long long gcdSum(vector<int>& nums) { //tc=O(n logN), sc=O(n)

        int n = nums.size();
        vector<long long> prefixGcd(n);

        long long mx = 0;

        // build prefixGcd
        for(int i = 0; i < n; i++) {
            mx = max(mx, (long long)nums[i]);
            prefixGcd[i] = __gcd((long long)nums[i], mx);
        }

        // sort
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int l = 0, r = n - 1;

        while(l < r) {
            ans += __gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};