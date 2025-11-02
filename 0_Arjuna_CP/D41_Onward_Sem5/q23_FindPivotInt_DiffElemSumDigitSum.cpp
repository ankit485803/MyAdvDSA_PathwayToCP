


/*

2nd Oct 2025 (Sunday)


qno 2535 https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/



2535. Difference Between Element Sum and Digit Sum of an Array
Easy
Topics

Companies
Hint
You are given a positive integer array nums.

The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.

 

Example 1:

Input: nums = [1,15,6,3]
Output: 9
Explanation: 
The element sum of nums is 1 + 15 + 6 + 3 = 25.
The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
The absolute difference between the element sum and digit sum is |25 - 16| = 9.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Explanation:
The element sum of nums is 1 + 2 + 3 + 4 = 10.
The digit sum of nums is 1 + 2 + 3 + 4 = 10.
The absolute difference between the element sum and digit sum is |10 - 10| = 0.
 

Constraints:

1 <= nums.length <= 2000
1 <= nums[i] <= 2000

*/



class Solution {
public:
    int differenceOfSum(vector<int>& nums) {  //TC=O(n), sc=O(1)
        int ElemSum = 0;
        int DigitSum = 0;

        for (int num : nums) {
            ElemSum += num;

            // Extract digits and add to DigitSum
            int n = num;
            while (n > 0) {
                DigitSum += n % 10;
                n /= 10;
            }
        }

        return abs(ElemSum - DigitSum);
    }
};



/*

qno  2160  https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/



2160. Minimum Sum of Four Digit Number After Splitting Digits
Easy
Topics

Companies
Hint
You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.

For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
Return the minimum possible sum of new1 and new2.

 

Example 1:

Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
Example 2:

Input: num = 4009
Output: 13
Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
 

Constraints:

1000 <= num <= 9999



*/

class Solution {
public:
    int minimumSum(int num) {  //TC=O(1) = sc
        vector<int> digits;
        
        // Extract digits
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        // Sort digits in ascending order
        sort(digits.begin(), digits.end());
        
        // Form two numbers using alternate digits
        int new1 = digits[0] * 10 + digits[2];
        int new2 = digits[1] * 10 + digits[3];

        return new1 + new2;
    }
};




/*


qno 2455  https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/


2455. Average Value of Even Numbers That Are Divisible by Three
Easy
Topics

Companies
Hint
Given an integer array nums of positive integers, return the average value of all even integers that are divisible by 3.

Note that the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.

 

Example 1:

Input: nums = [1,3,6,10,12,15]
Output: 9
Explanation: 6 and 12 are even numbers that are divisible by 3. (6 + 12) / 2 = 9.
Example 2:

Input: nums = [1,2,4,7,10]
Output: 0
Explanation: There is no single number that satisfies the requirement, so return 0.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000


*/

class Solution {
public:
    int averageValue(vector<int>& nums) {  //myRoughApproach
        
        vector<int> evenNo;

        for(int i=0; i<nums.size(); i++) {
            //step1: fidnd evenNo
            if(nums[i] % 2 == 0) {
                evenNo.push_back(nums[i]);  //store in arr if evenNo found
            }

            //step2: calcuate avg and check divisibility by 3
            while(i < evenNo.size()) {  //O(1)
                int sumElemInEven += evenNo[i];
                int n = nums.size();

                int avg = sumElemInEven / n;

                if(avg % 3 == 0) return avg; else 0;
            }
        }
        
    }
};



class Solution {
public:
    int averageValue(vector<int>& nums) {  //TC=O(n), SC=O(1)
        int sum = 0;
        int count = 0;

        for (int num : nums) {
            if (num % 6 == 0) { // divisible by both 2 and 3
                sum += num;
                count++;
            }
        }

        if (count == 0)
            return 0;

        return sum / count; // integer division automatically rounds down
    }
};






/*

qno 2469  https://leetcode.com/problems/convert-the-temperature/description/


2469. Convert the Temperature
Attempted
Easy
Topics

Companies
Hint
You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius.

You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit].

Return the array ans. Answers within 10-5 of the actual answer will be accepted.

Note that:

Kelvin = Celsius + 273.15
Fahrenheit = Celsius * 1.80 + 32.00
 

Example 1:

Input: celsius = 36.50
Output: [309.65000,97.70000]
Explanation: Temperature at 36.50 Celsius converted in Kelvin is 309.65 and converted in Fahrenheit is 97.70.
Example 2:

Input: celsius = 122.11
Output: [395.26000,251.79800]
Explanation: Temperature at 122.11 Celsius converted in Kelvin is 395.26 and converted in Fahrenheit is 251.798.
 

Constraints:

0 <= celsius <= 1000


*/


class Solution {
public:
    vector<double> convertTemperature(double celsius) {  //TC=O(1) = SC
        double kelvin = celsius + 273.15;          
        double fahrenheit = celsius * 1.80 + 32.00; // Correct conversion

        // Return both values in arrFormat
        return {kelvin, fahrenheit};               
    }
};




/*

qno 2485  https://leetcode.com/problems/find-the-pivot-integer/description/



2485. Find the Pivot Integer
Easy
Topics

Companies
Hint
Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

 

Example 1:

Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
Example 3:

Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
 

Constraints:

1 <= n <= 1000


*/


class Solution {
public:
    int pivotInteger(int n) {

        //approach1: BruteForce, TC=O(n*n), sc=O(1)

        for (int x = 1; x <= n; x++) {
            int leftSum = 0, rightSum = 0;

            // Calculate sum from 1 to x
            for (int i = 1; i <= x; i++) {
                leftSum += i;
            }

            // Calculate sum from x to n
            for (int i = x; i <= n; i++) {
                rightSum += i;
            }

            // If both sums are equal, x is the pivot
            if (leftSum == rightSum)
                return x;
        }

        // If no pivot found
        return -1;
    }
};



class Solution {
public:
    int pivotInteger(int n) {
        //approach2: mathetical direct with TC=O(1)=SC

        int totalSum = n * (n + 1) / 2;   // Sum of first n natural numbers (formula)

        int x = sqrt(totalSum);            // Find possible pivot (if totalSum is a perfect square)

        if (x * x == totalSum)             // CheckPerfectSq condition
            return x;                       
        return -1;                         
    }
};




/*


qno 81  https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

81. Search in Rotated Sorted Array II
Medium
Topics

Companies
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates.
 Would this affect the runtime complexity? How and why?



*/ 


class Solution {
public:
    bool search(vector<int>& nums, int target) {  //TC=O(logN) BS aprroach, SC=O(1)
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Found target
            if (nums[mid] == target)
                return true;


            // ➤ Handle duplicates: can't decide which part is sorted
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // ➤ Left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;  // Target in left half
                else
                    left = mid + 1;   // Target in right half
            }
            // ➤ Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;   // Target in right half
                else
                    right = mid - 1;  // Target in left half
            }
        }

        return false;  
    }
};
