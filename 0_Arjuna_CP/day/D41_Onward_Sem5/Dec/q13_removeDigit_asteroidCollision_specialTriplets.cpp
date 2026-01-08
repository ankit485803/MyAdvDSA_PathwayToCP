



/*




13th Dec 2025  (Satursday)


qno 2259  https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/


2259. Remove Digit From Number to Maximize Result
Easy
Topics

Companies
Hint
You are given a string number representing a positive integer and a character digit.

Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.

 

Example 1:

Input: number = "123", digit = "3"
Output: "12"
Explanation: There is only one '3' in "123". After removing '3', the result is "12".
Example 2:

Input: number = "1231", digit = "1"
Output: "231"
Explanation: We can remove the first '1' to get "231" or remove the second '1' to get "123".
Since 231 > 123, we return "231".
Example 3:

Input: number = "551", digit = "5"
Output: "51"
Explanation: We can remove either the first or second '5' from "551".
Both result in the string "51".
 

Constraints:

2 <= number.length <= 100
number consists of digits from '1' to '9'.
digit is a digit from '1' to '9'.
digit occurs at least once in number.







*/

class Solution {
public:
    string removeDigit(string number, char digit) {  //myWrongApproach
        int n = number.size();
        //calculateFreq of digit in numb
        int freq = 1;

        for(int i=0; i<n; i++) {
            //case1: if freq is ONE
            if(freq == 1) {
                number.drop(digit);
            } else {
                //drop digit and compare MAX 

            }

        }

        return number;  //updated
    }
};




class Solution {
public:
    string removeDigit(string numb, char digit) { //tc=O(n), sc=O(1)
        int n = numb.size();

        //firstLoop: find firstDigit that is smaller than nextOne
        for(int i=0; i<n-1; i++) {
            if(numb[i] == digit && numb[i] < numb[i + 1]) {
                // If digit is smaller than the next digit, remove it
                return numb.substr(0, i) + numb.substr(i + 1);
            }
        }

        //secondLoop: if no such condition found, remove last occurrence of digit
        for(int i=n-1; i>=0; i--) {
            if(numb[i] == digit) {
                return numb.substr(0, i) + numb.substr(i + 1);
            }
        }

        return numb;  //if no removal, return originalNum
    }
};






/*




qno 735  https://leetcode.com/problems/asteroid-collision/


735. Asteroid Collision
Medium
Topics

Companies
Hint
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0



*/



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {  //tc=O(n)=sc
        vector<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // Collision only when last is moving right and current is moving left
            while (!st.empty() && st.back() > 0 && a < 0) {
                if (abs(st.back()) < abs(a)) {
                    // stack top explodes
                    st.pop_back();
                    continue;
                } 
                else if (abs(st.back()) == abs(a)) {
                    // both explode
                    st.pop_back();
                }

                // current asteroid explodes
                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push_back(a);
            }
        }

        return st;
    }
};




/*


qno 41   https://leetcode.com/problems/first-missing-positive/ 




41. First Missing Positive
Hard
Topics

Companies
Hint
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1


the smallest positive integer (starting from 1) that does NOT appear


*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Place each number x at index x-1
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find first index where nums[i] != i+1
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        // Step 3: If all 1..n are present
        return n + 1;
    }
};




/*


qno  3583  https://leetcode.com/problems/count-special-triplets/




3583. Count Special Triplets
Medium
Topics

Companies
Hint
You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [6,3,6]

Output: 1

Explanation:

The only special triplet is (i, j, k) = (0, 1, 2), where:

nums[0] = 6, nums[1] = 3, nums[2] = 6
nums[0] = nums[1] * 2 = 3 * 2 = 6
nums[2] = nums[1] * 2 = 3 * 2 = 6
Example 2:

Input: nums = [0,1,0,0]

Output: 1

Explanation:

The only special triplet is (i, j, k) = (0, 2, 3), where:

nums[0] = 0, nums[2] = 0, nums[3] = 0
nums[0] = nums[2] * 2 = 0 * 2 = 0
nums[3] = nums[2] * 2 = 0 * 2 = 0
Example 3:

Input: nums = [8,4,2,8,4]

Output: 2

Explanation:

There are exactly two special triplets:

(i, j, k) = (0, 1, 3)
nums[0] = 8, nums[1] = 4, nums[3] = 8
nums[0] = nums[1] * 2 = 4 * 2 = 8
nums[3] = nums[1] * 2 = 4 * 2 = 8
(i, j, k) = (1, 2, 4)
nums[1] = 4, nums[2] = 2, nums[4] = 4
nums[1] = nums[2] * 2 = 2 * 2 = 4
nums[4] = nums[2] * 2 = 2 * 2 = 4
 

Constraints:

3 <= n == nums.length <= 105
0 <= nums[i] <= 105

*/



class Solution {
public:
    int specialTriplets(vector<int>& nums) {  //tc=O(n)
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;   //sc=O(n)

        // Fill right freqMap
        for (int x : nums) {
            right[x]++;
        }

        long long ans = 0;

        // j is the middle index
        for (int j = 0; j < nums.size(); j++) {
            int mid = nums[j];
            right[mid]--;  // remove current j from right side

            int target = mid * 2;
            if (left.count(target) && right.count(target)) {
                ans = (ans + left[target] * right[target]) % MOD;
            }

            left[mid]++;   //add current j to left side
        }

        return ans;
    }
};





/*  This is a counting topological order problem.


qno 3577  https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/


Code
Testcase
Testcase
Test Result
3577. Count the Number of Computer Unlocking Permutations
Medium
Topics

Companies
Hint
You are given an array complexity of length n.

There are n locked computers in a room with labels from 0 to n - 1, each with its own unique password. The password of the computer i has a complexity complexity[i].

The password for the computer labeled 0 is already decrypted and serves as the root. All other computers must be unlocked using it or another previously unlocked computer, following this information:

You can decrypt the password for the computer i using the password for computer j, where j is any integer less than i with a lower complexity. (i.e. j < i and complexity[j] < complexity[i])
To decrypt the password for computer i, you must have already unlocked a computer j such that j < i and complexity[j] < complexity[i].
Find the number of permutations of [0, 1, 2, ..., (n - 1)] that represent a valid order in which the computers can be unlocked, starting from computer 0 as the only initially unlocked one.

Since the answer may be large, return it modulo 109 + 7.

Note that the password for the computer with label 0 is decrypted, and not the computer with the first position in the permutation.

 

Example 1:

Input: complexity = [1,2,3]

Output: 2

Explanation:

The valid permutations are:

[0, 1, 2]
Unlock computer 0 first with root password.
Unlock computer 1 with password of computer 0 since complexity[0] < complexity[1].
Unlock computer 2 with password of computer 1 since complexity[1] < complexity[2].
[0, 2, 1]
Unlock computer 0 first with root password.
Unlock computer 2 with password of computer 0 since complexity[0] < complexity[2].
Unlock computer 1 with password of computer 0 since complexity[0] < complexity[1].
Example 2:

Input: complexity = [3,3,3,4,4,4]

Output: 0

Explanation:

There are no possible permutations which can unlock all computers.

 

Constraints:

2 <= complexity.length <= 105
1 <= complexity[i] <= 109



*/



class Solution {
public:
    int countPermutations(vector<int>& complexity) {  //wrongApproach
        int n = complexity.size();
        // int M = le9 + 7;
        int M = 1e9 + 7;

        long ans = 1;
        for(int i=0; i<n; i++) {
            if(complexity[i] <= complexity[0]) {
                return 0;
            }

            ans = (ans * i) % M;
        }

        return (int) ans;
    }
};




class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        const int MOD = 1e9 + 7;

        long long ans = 1;

        for (int i = 1; i < n; i++) {
            // If any computer cannot be unlocked by computer 0
            if (complexity[i] <= complexity[0]) {
                return 0;
            }

            ans = (ans * i) % MOD;  // multiply choices
        }

        return (int)ans;
    }
};
