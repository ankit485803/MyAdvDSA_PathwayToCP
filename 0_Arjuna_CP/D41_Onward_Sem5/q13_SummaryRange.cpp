


/*

20th Oct 2025 (Monday - Happy Diwali  Sem5 III year IITP)


qno 228   https://leetcode.com/problems/summary-ranges/description/



228. Summary Ranges
Solved
Easy
Topics

Companies
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
 

Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.


*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {  //TC=(n), sc=O(1)
        vector<string> ranges;
        if (nums.empty()) return ranges;

        int n = nums.size();
        int start = nums[0];

        for (int i = 0; i < n; i++) {
            // Check if it's the last element or if the next element is not consecutive
            if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                // If start equals current number, it's a single number
                if (start == nums[i]) {
                    ranges.push_back(to_string(start));
                } else {
                    ranges.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                // Update start for the next potential range
                if (i < n - 1) {
                    start = nums[i + 1];
                }
            }
        }
        return ranges;
    }
};



/*

qno 34  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/


34. Find First and Last Position of Element in Sorted Array
Solved
Medium
Topics

Companies
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109



*/

class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        int first = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                first = mid;       // possible answer
                end = mid - 1;     // but keep searching left
            } 
            else if (nums[mid] < target) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        int last = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                last = mid;        // possible answer
                st = mid + 1;      // but keep searching right
            } 
            else if (nums[mid] < target) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};


/*

Time Complexity: O(log n) (two binary searches).
Space Complexity: O(1) (only variables used).

*/



/*

qno 349  https://leetcode.com/problems/intersection-of-two-arrays/description/


349. Intersection of Two Arrays
Attempted
Easy
Topics

Companies
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000

*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { //TC=O(nLogN), sc=O(n)
        
        //step1: sortArr
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        //step2 - intilize who store commanElem
        vector<int> ans; 
        int i=0, j=0;

        //step3: checkElemCommon and store in ans using twoPointerApproach
        while(i<nums1.size()  &&  j<nums2.size()) {
            if(nums1[i] == nums2[j]) {
                // Add the element to result if it's not already in ans
                if(ans.empty()  ||  ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);  //or hm nums2[j] bhi kar sakte because equal
                }
                i++;
                j++;

            } else if(nums1[i]  <  nums2[j]) {
                i++;
            } else{
                j++;
            }
        }

        return ans;  
    }
};



/*


qno 2215  https://leetcode.com/problems/find-the-difference-of-two-arrays/description/

2215. Find the Difference of Two Arrays
Easy
Topics

Companies
Hint
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000

*/


#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {  //tc=O(n) = sc
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> first, second;
        
        // Find elements in nums1 not in nums2
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                first.push_back(num);
            }
        }
        
        // Find elements in nums2 not in nums1
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                second.push_back(num);
            }
        }
        
        return {first, second};
    }
};



/*

qno 1625  https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/

1625. Lexicographically Smallest String After Applying Operations
Medium
Topics

Companies
Hint
You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.

You can apply either of the following two operations any number of times and in any order on s:

Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.

 

Example 1:

Input: s = "5525", a = 9, b = 2
Output: "2050"
Explanation: We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
Add:    "5121"
Rotate: "2151"
Add:    "2050"​​​​​
There is no way to obtain a string that is lexicographically smaller than "2050".
Example 2:

Input: s = "74", a = 5, b = 1
Output: "24"
Explanation: We can apply the following operations:
Start:  "74"
Rotate: "47"
​​​​​​​Add:    "42"
​​​​​​​Rotate: "24"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller than "24".
Example 3:

Input: s = "0011", a = 4, b = 2
Output: "0011"
Explanation: There are no sequence of operations that will give us a lexicographically smaller string than "0011".
 

Constraints:

2 <= s.length <= 100
s.length is even.
s consists of digits from 0 to 9 only.
1 <= a <= 9
1 <= b <= s.length - 1

*/

#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        // Step 1: Function to apply the "add a" operation to odd indices
        auto addA = [&a](string &s) {
            for (int i = 1; i < s.size(); i += 2) {
                s[i] = (s[i] - '0' + a) % 10 + '0';  // add 'a' and take modulo 10
            }
        };

        // Step 2: Function to rotate the string by 'b' positions to the right
        auto rotateB = [&b](string &s) {
            int n = s.size();
            b %= n;  // In case b is larger than the string length, we use the modulus
            reverse(s.begin(), s.end());
            reverse(s.begin(), s.begin() + b);
            reverse(s.begin() + b, s.end());
        };
        
        string minString = s;  // Initialize the minimum string with the original string
        string current = s;
        
        // Step 3: Try all rotations of the string
        for (int i = 0; i < s.size(); ++i) {
            // For each rotation, apply the "add a" operation multiple times
            string rotated = current;
            addA(rotated);
            
            // After each add operation, check if it's the smallest lexicographically
            minString = min(minString, rotated);
            
            // Apply rotateB and try all rotations
            for (int j = 0; j < s.size(); ++j) {
                rotateB(rotated);
                addA(rotated); // Add a after each rotation
                minString = min(minString, rotated);  // Update the minimum string
            }
            
            // Rotate the string for the next possible rotation
            rotateB(current);
        }
        
        // Step 4: Return the lexicographically smallest string
        return minString;
    }
};

//TC=O(n^2)
//SC= O(n) for storing the string and auxiliary variables like rotated and minString


#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to rotate the string by b positions to the right
    string rotate(const string &s, int b) {
        int n = s.length();
        b %= n;  // Ensure b is within the string length range
        string rotated = s;
        reverse(rotated.begin(), rotated.end());  // Reverse the whole string
        reverse(rotated.begin(), rotated.begin() + b);  // Reverse the first part
        reverse(rotated.begin() + b, rotated.end());  // Reverse the second part
        return rotated;
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        // BFS Setup
        unordered_set<string> visited;  // Set to track visited strings
        queue<string> q;  // Queue for BFS
        string smallestString = s;  // Initialize the smallest string as the original one
        
        q.push(s);  // Start BFS with the original string
        visited.insert(s);  // Mark the original string as visited
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            // Update smallestString if the current string is lexicographically smaller
            if (curr < smallestString) {
                smallestString = curr;
            }

            // Add 'a' to all digits at odd indices
            string added = curr;
            for (int i = 1; i < added.length(); i += 2) {
                added[i] = (added[i] - '0' + a) % 10 + '0';  // Add a and wrap around using modulo 10
            }
            // If this new string hasn't been visited yet, enqueue it
            if (visited.find(added) == visited.end()) {
                visited.insert(added);
                q.push(added);
            }

            // Rotate the string by b positions
            string rotated = rotate(curr, b);
            // If the rotated string hasn't been visited yet, enqueue it
            if (visited.find(rotated) == visited.end()) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return smallestString;
    }
};