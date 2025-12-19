




/*


19th Dec 2025 (Friday)


qno 2269  https://leetcode.com/problems/find-the-k-beauty-of-a-number/



2269. Find the K-Beauty of a Number
Easy
Topics

Companies
Hint
The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:

It has a length of k.
It is a divisor of num.
Given integers num and k, return the k-beauty of num.

Note:

Leading zeros are allowed.
0 is not a divisor of any value.
A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: num = 240, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "24" from "240": 24 is a divisor of 240.
- "40" from "240": 40 is a divisor of 240.
Therefore, the k-beauty is 2.
Example 2:

Input: num = 430043, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "43" from "430043": 43 is a divisor of 430043.
- "30" from "430043": 30 is not a divisor of 430043.
- "00" from "430043": 0 is not a divisor of 430043.
- "04" from "430043": 4 is not a divisor of 430043.
- "43" from "430043": 43 is a divisor of 430043.
Therefore, the k-beauty is 2.
 

Constraints:

1 <= num <= 109
1 <= k <= num.length (taking num as a string)




*/



class Solution {
public:
    int divisorSubstrings(int num, int k) {
        //bruteForceApproach
        int count = 0;

        //step1: formSubstr from nums whose length k

        //step2: check divisibility condition if pass, count++ and return 
    }
};



class Solution {
public:
    int divisorSubstrings(int num, int k) {  //tc=O(n * k) subst and conversion, sc=O(1)
        //first convert to str
        string s = to_string(num);
        int count = 0;

        for(int i=0; i+k <= s.size(); i++) {
            int val = stoi(s.substr(i, k));

            //0 is not divisor
            if(val != 0 && num % val == 0) {
                count++;
            }
        }

        return count; 
    }
};






/*


qno 2016  https://leetcode.com/problems/maximum-difference-between-increasing-elements/



2016. Maximum Difference Between Increasing Elements
Easy
Topics

Companies
Hint
Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.

 

Example 1:

Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
Example 2:

Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].
Example 3:

Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.
 

Constraints:

n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 109



*/



class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //twoPointer
        int maxDiff = -1;  //initilize

        for(int i=0; i<nums.size(); i++) {   //O(N^2) due to nestedLoop
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[i] < nums[j]) {
                    int diff = nums[j] - nums[i];
                    maxDiff = max(diff, maxDiff);
                }
            }
        }

        return maxDiff;
    }
};





/*


qno 1299  https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/


1299. Replace Elements with Greatest Element on Right Side
Solved
Easy
Topics

Companies
Hint
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
Example 2:

Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.
 

Constraints:

1 <= arr.length <= 104
1 <= arr[i] <= 105


*/


class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //nestedLoop approach

        for(int i=0; i<arr.size(); i++) {
            int maxRight = -1;
            for(int j=i+1; j<arr.size(); j++) {
                maxRight = max(maxRight, arr[j]);
            }
            arr[i] = maxRight;
        }

        return arr;
    }
};





/*



qno 2078  https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/


2078. Two Furthest Houses With Different Colors
Solved
Easy
Topics

Companies
Hint
There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

Return the maximum distance between two houses with different colors.

The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

 

Example 1:


Input: colors = [1,1,1,6,1,1,1]
Output: 3
Explanation: In the above image, color 1 is blue, and color 6 is red.
The furthest two houses with different colors are house 0 and house 3.
House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
Note that houses 3 and 6 can also produce the optimal answer.
Example 2:


Input: colors = [1,8,3,8,3]
Output: 4
Explanation: In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
The furthest two houses with different colors are house 0 and house 4.
House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
Example 3:

Input: colors = [0,1]
Output: 1
Explanation: The furthest two houses with different colors are house 0 and house 1.
House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.
 

Constraints:

n == colors.length
2 <= n <= 100
0 <= colors[i] <= 100
Test data are generated such that at least two houses have different colors.



*/


class Solution {
public:
    int maxDistance(vector<int>& colors) {  //tc=O(n^2), sc=O(1)
        int n = colors.size();

        int maxDist = 0;
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>i; j--) {
                if(colors[i] != colors[j]) {
                    int dist = abs(i - j);

                    maxDist = max(dist, maxDist);
                }
            }
        }

        return maxDist;
    }
};




/*


qno  1855  https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/


1855. Maximum Distance Between a Pair of Values
Solved
Medium
Topics

Companies
Hint
You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

 

Example 1:

Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
Example 2:

Input: nums1 = [2,2,2], nums2 = [10,10,1]
Output: 1
Explanation: The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
Example 3:

Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
Output: 2
Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 105
Both nums1 and nums2 are non-increasing.




*/



class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0; 

        //twoPointer
        int i = 0;
        int j = 0;
        while(i < nums1.size() &&  j < nums2.size()) {
            if(nums1[i] <= nums2[j]) {
                int dist = j-i;
                maxDist = max(dist, maxDist);
                j++;
            } else {
                i++;
            }
        }

        return maxDist;
    }
};