

/*

25th Aug 2026 (Tuesday)

qno 3718  https://leetcode.com/problems/smallest-missing-multiple-of-k/?envType=daily-question&envId=2026-08-25

Code
Testcase
Testcase
Test Result
3718. Smallest Missing Multiple of K
Easy
Topics

Companies
Hint
Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.

A multiple of k is any positive integer divisible by k.

 

Example 1:

Input: nums = [8,2,3,4,6], k = 2

Output: 10

Explanation:

The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

Example 2:

Input: nums = [1,4,7,10,15], k = 5

Output: 5

Explanation:

The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
127,951/184.7K
Acceptance Rate
69.3%
Topics
Mid Level
Array
Hash Table
Weekly Contest 472

*/




class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        //approach1: simple simulation jaisa bol raha h wah kar do; tc=O(n), sc=O(1)
        //iterate to each elem find min missing multiple
        int min = k;  //ans
        for(int i=0; i < nums.size(); i++) {
            if((arr[i] != k) && arr[i] % k == 0) {  //muliple and missing check

            }
        }
    }
};

//approch2: store the possible multipe of k till arrSize and then return minium missing k, tc=sc=O(n)



class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {  //simple simulation sc=O(1), tc=O(n * m)
        int multiple = k;

        while (true) {
            bool found = false;

            for (int x : nums) {
                if (x == multiple) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return multiple;

            multiple += k;
        }
    }
};


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {  //tc=O(n) = sc using hash set
        unordered_set<int> st(nums.begin(), nums.end());

        for (int multiple = k; ; multiple += k) {
            if (!st.count(multiple))
                return multiple;
        }
    }
};
