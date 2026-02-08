



/*


8th Feb 2026 (Sunday - gate CSIT paper today near AIIMS patna)

prob from weekyContest 488 perSunday  https://leetcode.com/contest/weekly-contest-488/



qno 2124  https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/


2124. Check if All A's Appears Before All B's
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

 

Example 1:

Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
Example 2:

Input: s = "abab"
Output: false
Explanation:
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.
Example 3:

Input: s = "bbb"
Output: true
Explanation:
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
 

Constraints:

1 <= s.length <= 100
s[i] is either 'a' or 'b'.
 
Discover more
Software development tools IDEs
coding
Seen this question in a real interview before?
1/5
Yes
No
Accepted
120,603/165.2K
Acceptance Rate
73.0%
Topics
Mid Level
String
Weekly Contest 274


*/



class Solution {
public:
    bool checkString(string s) {

        for(int i=0; i<s.size(); i++) {
            char ch1 = s[i];
            char ch2 = s[i+1];  //nextChar alikely b on rightSide

            if(ch1 == 'b' && ch2 == 'a') {
                return false;
            }
        }

        return true;
    }
};



class Solution {
public:
    bool checkString(string s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == 'b' && s[i + 1] == 'a') {
                return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    bool checkString(string s) {
        bool seenB = false;
        for (char c : s) {
            if (c == 'b') seenB = true;
            if (seenB && c == 'a') return false;
        }
        return true;
    }
};




/*


qno 3833  https://leetcode.com/problems/count-dominant-indices/


3833. Count Dominant Indices
Easy

Companies
Hint
You are given an integer array nums of length n.

An element at index i is called dominant if: nums[i] > average(nums[i + 1], nums[i + 2], ..., nums[n - 1])

Your task is to count the number of indices i that are dominant.

The average of a set of numbers is the value obtained by adding all the numbers together and dividing the sum by the total number of numbers.

Note: The rightmost element of any array is not dominant.

 

Example 1:

Input: nums = [5,4,3]

Output: 2

Explanation:

At index i = 0, the value 5 is dominant as 5 > average(4, 3) = 3.5.
At index i = 1, the value 4 is dominant over the subarray [3].
Index i = 2 is not dominant as there are no elements to its right. Thus, the answer is 2.
Example 2:

Input: nums = [4,1,2]

Output: 1

Explanation:

At index i = 0, the value 4 is dominant over the subarray [1, 2].
At index i = 1, the value 1 is not dominant.
Index i = 2 is not dominant as there are no elements to its right. Thus, the answer is 1.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100​​​​​​​


*/



class Solution {
public:
    int dominantIndices(vector<int>& nums) {  //tc=O(n^2) working because size 100 sc=O(1)
        int n = nums.size();
        int count = 0;  //which count dominant Idx

        for(int i=0; i<n-1; i++) {  //last rightmost not dominant
            int sum = 0;
            int element = n-i-1;

            for(int j=i+1; j<n; j++) {
                sum += nums[j];
            }

            double avg = (double)sum / element;

            if(nums[i] > avg) {
                count++;
            }
        }

        return count;
    }
};





/*


qno 3834  https://leetcode.com/problems/merge-adjacent-equal-elements/


3834. Merge Adjacent Equal Elements
Medium

Companies
Hint
You are given an integer array nums.

You must repeatedly apply the following merge operation until no more changes can be made:

If any two adjacent elements are equal, choose the leftmost such adjacent pair in the current array and replace them with a single element equal to their sum.
After each merge operation, the array size decreases by 1. Repeat the process on the updated array until no more changes can be made.

Return the final array after all possible merge operations.

 

Example 1:

Input: nums = [3,1,1,2]

Output: [3,4]

Explanation:

The middle two elements are equal and merged into 1 + 1 = 2, resulting in [3, 2, 2].
The last two elements are equal and merged into 2 + 2 = 4, resulting in [3, 4].
No adjacent equal elements remain. Thus, the answer is [3, 4].
Example 2:

Input: nums = [2,2,4]

Output: [8]

Explanation:

The first two elements are equal and merged into 2 + 2 = 4, resulting in [4, 4].
The first two elements are equal and merged into 4 + 4 = 8, resulting in [8].
Example 3:

Input: nums = [3,7,5]

Output: [3,7,5]

Explanation:

There are no adjacent equal elements in the array, so no operations are performed.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105​​​​​​​


*/


class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {  //tc=O(n)=sc
        vector<long long> res;

        for (int x : nums) {
            res.push_back(x);

            // keep merging while last two are equal
            while (res.size() >= 2) {
                int n = res.size();
                if (res[n - 1] == res[n - 2]) {
                    long long merged = res[n - 1] + res[n - 2];
                    res.pop_back();
                    res.pop_back();
                    res.push_back(merged);
                } else {
                    break;
                }
            }
        }

        return res;
    }
};
