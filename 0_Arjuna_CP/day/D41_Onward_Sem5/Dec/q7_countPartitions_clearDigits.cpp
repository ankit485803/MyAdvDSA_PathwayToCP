



/*



9th Oct  2025  (Tuesday  -  (Happy Birthday - AmruthaDi))  


qno 3432   https://leetcode.com/problems/count-partitions-with-even-sum-difference/




3432. Count Partitions with Even Sum Difference
Easy
Topics

Companies
Hint
You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:

Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays is even.

 

Example 1:

Input: nums = [10,10,3,7,6]

Output: 4

Explanation:

The 4 partitions are:

[10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
[10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
[10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
[10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

No partition results in an even sum difference.

Example 3:

Input: nums = [2,4,6,8]

Output: 3

Explanation:

All partitions result in an even sum difference.

 

Constraints:

2 <= n == nums.length <= 100
1 <= nums[i] <= 100





*/



class Solution {
public:
    int countPartitions(vector<int>& nums) {   //myApproach
        //step1: makePossible pair
        int count = 0;
        //step2: calculateDiff, if diff % 2 ==0 -> count++; else 0;
    }
};





class Solution {
public:
    int countPartitions(vector<int>& nums) { //tc=O(n), sc=O(1) using prefixSum
        int totalS = 0;  
        int leftS = 0;    
        int count = 0; 

    
        for (int num : nums) {
            totalS += num;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            leftS += nums[i]; 
            int rightS = totalS - leftS;  

            // Check if diff is even
            if ((leftS - rightS) % 2 == 0) {
                count++;  
            }
        }

        return count;  
    }
};





/*


qno 2211  https://leetcode.com/problems/count-collisions-on-a-road/description/


2211. Count Collisions on a Road
Medium
Topics

Companies
Hint
There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:

When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
When a moving car collides with a stationary car, the number of collisions increases by 1.
After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.

Return the total number of collisions that will happen on the road.

 

Example 1:

Input: directions = "RLRSLL"
Output: 5
Explanation:
The collisions that will happen on the road are:
- Cars 0 and 1 will collide with each other. Since they are moving in opposite directions, the number of collisions becomes 0 + 2 = 2.
- Cars 2 and 3 will collide with each other. Since car 3 is stationary, the number of collisions becomes 2 + 1 = 3.
- Cars 3 and 4 will collide with each other. Since car 3 is stationary, the number of collisions becomes 3 + 1 = 4.
- Cars 4 and 5 will collide with each other. After car 4 collides with car 3, it will stay at the point of collision and get hit by car 5. The number of collisions becomes 4 + 1 = 5.
Thus, the total number of collisions that will happen on the road is 5. 
Example 2:

Input: directions = "LLRR"
Output: 0
Explanation:
No cars will collide with each other. Thus, the total number of collisions that will happen on the road is 0.
 

Constraints:

1 <= directions.length <= 105
directions[i] is either 'L', 'R', or 'S'.


*/



class Solution {
public:
    int countCollisions(string directions) {  //tc=O(n), sc=O(1)
        int n = directions.length();
        int collisions = 0;

        // Step1: Find the leftmost index where we no longer have 'L'
        int i = 0;  // left boundary
        while (i < n && directions[i] == 'L') {
            i++;
        }

        // Step2: Find the rightmost index where we no longer have 'R'
        int j = n - 1;  // right boundary
        while (j >= 0 && directions[j] == 'R') {
            j--;
        }

        // Step3: Count the collisions
        while (i <= j) {
            char c = directions[i];

            if (c != 'S') {
                collisions++;
            }

            i++;
        }

        return collisions;
    }
};




/*

qno 3174  https://leetcode.com/problems/clear-digits/


3174. Clear Digits
Easy
Topics

Companies
Hint
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.

 

Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".

 

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.



*/


#include <stack>
#include <cctype>  // for isdigit

class Solution {
public:
    string clearDigits(string s) {  //tc=O(n)=sc
        stack<char> stk;

        for (char c : s) {
            if (isdigit(c)) {
                // If char is a digit, pop the last non-digit char
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(c);
            }
        }


        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;  // prepend the char to result
            stk.pop();
        }

        return result;
    }
};




