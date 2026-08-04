

/*

4th Aug 2026 (Tuesday)

qno 3731  https://leetcode.com/problems/find-missing-elements/?envType=daily-question&envId=2026-08-04

3731. Find Missing Elements
Solved
Easy
Topics

Companies
Hint
You are given an integer array nums consisting of unique integers.

Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.

The smallest and largest integers of the original range are still present in nums.

Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

 

Example 1:

Input: nums = [1,4,2,5]

Output: [3]

Explanation:

The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

Example 2:

Input: nums = [7,8,6,9]

Output: []

Explanation:

The smallest integer is 6 and the largest is 9, so the full range is [6,7,8,9]. All integers are already present, so no integer is missing.

Example 3:

Input: nums = [5,1]

Output: [2,3,4]

Explanation:

The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.

 

Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 100
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
192,633/218.6K
Acceptance Rate
88.1%
Topics
Mid Level
Array
Hash Table
Sorting
Weekly Contest 474


*/


class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {  //tc=O(logN + totalElem), sc=O(1)
        sort(nums.begin(), nums.end());

        int curr = nums[0];
        vector<int> ans;

        for(int i=0; i < nums.size(); ) {
            if(curr < nums[i]) {
                ans.push_back(curr);
            } else {
                i++;
            }
            curr++;
        }

        return ans;
    }
};


//Approach-2
//T.C : O(n + T), T = total number of elements between maxEl and minEl
//S.C : O(1)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        //constraints : 1 <= nums[i] <= 100
        vector<bool> present(101, false);
       //or you can use unordered_set<int>

        int maxEl = nums[0];
        int minEl = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            maxEl = max(maxEl, nums[i]);
            minEl = min(minEl, nums[i]);
            present[nums[i]] = true;
        }

        vector<int> result;

        for(int curr = minEl; curr <= maxEl; curr++) {
            if(!present[curr]) {
                result.push_back(curr);
            }
        }

        return result;
    }
};