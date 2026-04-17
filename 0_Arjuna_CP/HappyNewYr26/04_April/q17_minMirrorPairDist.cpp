

/*

17th April 2026 (Friday)


qno  https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/?envType=daily-question&envId=2026-04-17


3761. Minimum Absolute Distance Between Mirror Pairs
Attempted
Medium
Topics

Companies
Hint
You are given an integer array nums.

A mirror pair is a pair of indices (i, j) such that:

0 <= i < j < nums.length, and
reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

If no mirror pair exists, return -1.

 

Example 1:

Input: nums = [12,21,45,33,54]

Output: 1

Explanation:

The mirror pairs are:

(0, 1) since reverse(nums[0]) = reverse(12) = 21 = nums[1], giving an absolute distance abs(0 - 1) = 1.
(2, 4) since reverse(nums[2]) = reverse(45) = 54 = nums[4], giving an absolute distance abs(2 - 4) = 2.
The minimum absolute distance among all pairs is 1.

Example 2:

Input: nums = [120,21]

Output: 1

Explanation:

There is only one mirror pair (0, 1) since reverse(nums[0]) = reverse(120) = 21 = nums[1].

The minimum absolute distance is 1.

Example 3:

Input: nums = [21,120]

Output: -1

Explanation:

There are no mirror pairs in the array.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109​​​​​​​
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
57,943/105.1K
Acceptance Rate
55.1%
Topics
Staff
Array
Hash Table
Math
Weekly Contest 478


*/



class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {  //myFirstAttempt wrongSol
        //bruteForce - twoPointer
        int i=0, j=1;

        int ans = -1;

        while(i < nums.size()) {
            if(nums[i] == reverse(nums[j] ) {
                ans += min(ans, abs(i - j));
                i++;
                j++;
            }
        }

        return ans;
    }
};



/*

Correct Idea (Optimal Approach)

Use a hash map to track previously seen numbers.

For each index j:

* Compute rev = reverse(nums[j])
* If rev was seen before at index i, update answer:
  ans = min(ans, j - i)
* Store/update the current number’s index

Key Insight

Instead of checking all pairs (O(n²)), we:

* Reverse the current number
* Check if its mirror already exists
* Keep the closest index only → ensures minimum distance


2 % 10 = 2

means remainder when 2 is divided by 10.
Since 2 is smaller than 10, it doesn't get divided even once, so the remainder is:

2
*/


#include <iostream>
using namespace std;

int main() {
    cout << (2 % 10);  //ans = 2
    return 0;
}



class Solution {
public:
    int reverseNum(int x) {  //helperFunct
        int rev = 0;
        while(x > 0) {
            rev = rev * 10 + (x % 10);  //rev + lastD
            x /= 10;  //removeLastD
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {  
        //take map to track seen elem
        unordered_map<int, int> mp;   //value -> last idx
        int ans = INT_MAX;

        for(int j=0; j < nums.size(); j++) {
            int rev = reverseNum(nums[j]);

            if(mp.find(rev) != mp.end() ) {  //when notEqual
                ans = min(ans, j - mp[rev]);
            }

            mp[nums[j]] = j;
        }

        return ans == INT_MAX ? -1 : ans;  //tc=O(n * digit), sc=O(n) due to map  not leading zero
    }
};



class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // reversed value -> index
        int ans = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            // Check if current number matches any previous reversed
            if (mp.find(nums[j]) != mp.end()) {
                ans = min(ans, j - mp[nums[j]]);
            }

            // Store reverse of current number
            int rev = reverseNum(nums[j]);
            mp[rev] = j;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};