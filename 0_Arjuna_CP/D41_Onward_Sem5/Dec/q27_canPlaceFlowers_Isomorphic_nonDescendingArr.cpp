




/*


27th Dec 2025 (Satursday)



qno 605  https://leetcode.com/problems/can-place-flowers/


605. Can Place Flowers
Easy
Topics

Companies
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length




*/



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        
        int count = 0;  
        
        for (int i = 0; i < flowerbed.size(); ++i) {
            // Check if we can plant a flower at position i
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                
                // Plant the flower
                flowerbed[i] = 1;
                count++;
                
                // If we've planted enough flowers, return true
                if (count >= n) {
                    return true;
                }
            }
        }
        
        return false;
    }
};






/*



qno 849  https://leetcode.com/problems/maximize-distance-to-closest-person/description/



849. Maximize Distance to Closest Person
Medium
Topics

Companies
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

 

Example 1:


Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Example 3:

Input: seats = [0,1]
Output: 1
 

Constraints:

2 <= seats.length <= 2 * 104
seats[i] is 0 or 1.
At least one seat is empty.
At least one seat is occupied.





*/


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {  //tc=O(n), s=O(1)
        int n = seats.size();
        int last = -1;
        int maxDist = 0;

        for(int i=0; i<n; i++) {
            if(seats[i] == 1) {
                if(last == -1) {
                    maxDist = i;
                } else {
                    maxDist = max(maxDist, (i - last)/2 );
                }
                last = i;
            }
        }
        if(seats[n-1] == 0) {
            maxDist = max(maxDist, n-1 - last);
        }

        return maxDist;
    }
};




/*


qno 674  https://leetcode.com/problems/longest-continuous-increasing-subsequence/



674. Longest Continuous Increasing Subsequence
Solved
Easy
Topics

Companies
Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5] with length 3.
Even though [1,3,5,7] is an increasing subsequence, it is not continuous as elements 5 and 7 are separated by element
4.
Example 2:

Input: nums = [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2] with length 1. Note that it must be strictly
increasing.
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109



*/



class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //if empty
        if(nums.empty()) return 0;

        //initilize pointer
        int maxLength = 1, currLength = 1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {  //when Left > right
                currLength ++;
            }
            else {
                maxLength = max(currLength, maxLength);
                currLength = 1;
            }
        }
        //final comparison
        maxLength = max(currLength, maxLength);
        return maxLength;

        
    }
};

//Brute force aproach
// time complex = O(n), spcace = O(1)




/*


qno 665  https://leetcode.com/problems/non-decreasing-array/description/

665. Non-decreasing Array
Attempted
Medium
Topics

Companies
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:

Input: nums = [4,2,1]
Output: false
Explanation: You cannot get a non-decreasing array by modifying at most one element.
 

Constraints:

n == nums.length
1 <= n <= 104
-105 <= nums[i] <= 105


*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
                if (cnt > 1) return false;

                if (i < 2 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }
};



/*


qno 205  https://leetcode.com/problems/isomorphic-strings/description/




205. Isomorphic Strings
Easy
Topics

Companies
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.



*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            // Check s -> t mapping
            if (mp1.count(a) && mp1[a] != b) return false;

            // Check t -> s mapping
            if (mp2.count(b) && mp2[b] != a) return false;

            mp1[a] = b;
            mp2[b] = a;
        }

        return true;
    }
};





class Solution {
public:
    bool isIsomorphic(string s, string t) {   //ASCII, approach 
        int m1[256] = {0}, m2[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};


