




/*


21st Dec 2025 (Sunday - mylpgRefilling)


qno  1502    https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/


Code
Testcase
Testcase
Test Result
1502. Can Make Arithmetic Progression From Sequence
Solved
Easy
Topics

Companies
Hint
A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

 

Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
 

Constraints:

2 <= arr.length <= 1000
-106 <= arr[i] <= 106
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
303,784/437.6K
Acceptance Rate
69.4%
Topics
Array
Sorting
Weekly Contest 196




*/



class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];  //firstTwoDiff
        

        for(int i=2; i<arr.size(); i++) {
            if(arr[i] - arr[i-1]  != diff) {
                return false;
            } 
        }

        return true;
    }
};




/*


qno 3780  https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/






*/