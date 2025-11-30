


/*

30th Nov 2025 (Sunday)


qno  2418  https://leetcode.com/problems/sort-the-people/


2418. Sort the People
Easy
Topics

Companies
Hint
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.




*/


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {  //tc=O(n logN), sc=O(1)
        int n = names.size();
        vector<pair<int, string>> v;  // height, name

        for (int i = 0; i < n; i++) {
            v.push_back({heights[i], names[i]});
        }

        // Sort by height descending
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        vector<string> ans;
        for (auto &p : v) {
            ans.push_back(p.second);
        }
        return ans;
    }
};




/*

qno 3512  https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/


3512. Minimum Operations to Make Array Sum Divisible by K
Solved
Easy
Topics

Companies
Hint
You are given an integer array nums and an integer k. You can perform the following operation any number of times:

Select an index i and replace nums[i] with nums[i] - 1.
Return the minimum number of operations required to make the sum of the array divisible by k.

 

Example 1:

Input: nums = [3,9,7], k = 5

Output: 4

Explanation:

Perform 4 operations on nums[1] = 9. Now, nums = [3, 5, 7].
The sum is 15, which is divisible by 5.
Example 2:

Input: nums = [4,1,3], k = 4

Output: 0

Explanation:

The sum is 8, which is already divisible by 4. Hence, no operations are needed.
Example 3:

Input: nums = [3,2], k = 6

Output: 5

Explanation:

Perform 3 operations on nums[0] = 3 and 2 operations on nums[1] = 2. Now, nums = [0, 0].
The sum is 0, which is divisible by 6.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
1 <= k <= 100
 
Discover more
Math
Mathematics
Seen this question in a real interview before?
1/5
Yes
No
Accepted
145,181/156.7K
Acceptance Rate
92.7%
Topics
Array
Math
Biweekly Contest 154



*/


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {  //tc=O(n), sc=O(1)
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        return sum % k;  //remainder will be our ans
    }
};



/*


qno 1636  https://leetcode.com/problems/sort-array-by-increasing-frequency/description/


1636. Sort Array by Increasing Frequency
Easy
Topics

Companies
Hint
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100


*/


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {  //tc=O(logN), sc=O(n)
        unordered_map<int, int> freq;

        // Count frequencies
        for (int x : nums) {
            freq[x]++;
        }

        // Sort with custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) 
                return a > b; // decreasing order for same freq
            return freq[a] < freq[b]; // increasing order of freq
        });

        return nums;
    }
};





/*



qno 1464 https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/


1464. Maximum Product of Two Elements in an Array
Solved
Easy
Topics

Companies
Hint
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
 

Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3


*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {  //tc=O(n logN), sc=O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int prod = (nums[n-1] -1) * (nums[n-2] -1);
        return prod;
    }
};




class Solution {
public:
    int maxProduct(vector<int>& nums) { //tc=O(n), sc=O(1)
        int max1 = 0, max2 = 0;

        for (int x : nums) {  //iterative way to find max
            if (x >= max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};




/*


qno 1491  https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/


1491. Average Salary Excluding the Minimum and Maximum Salary
Attempted
Easy
Topics

Companies
Hint
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
 

Constraints:

3 <= salary.length <= 100
1000 <= salary[i] <= 106
All the integers of salary are unique.



*/


class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();

        // Sort so the smallest is at index 0 and the largest at index n-1
        sort(salary.begin(), salary.end());

        double sum = 0;

        // Only add salaries from index 1 to n-2
        // This automatically excludes:
        // salary[0]  -> minimum salary
        // salary[n-1] -> maximum salary
        for (int i = 1; i < n - 1; i++) {
            sum += salary[i];  // adding only the middle values
        }

        // Divide by (n - 2) because we removed two elements (min and max)
        return sum / (n - 2);
    }
};



class Solution {
public:
    double average(vector<int>& salary) {  //tc=O(n logN), sc=O(1)
        int n = salary.size();

        sort(salary.begin(), salary.end());

        double sum = 0;

        // Only add salaries from index 1 to n-2
        // This automatically excludes:
        // salary[0]  -> minimum salary
        // salary[n-1] -> maximum salary
        for (int i = 1; i < n - 1; i++) {
            sum += salary[i]; 
        }

        return sum / (n - 2);
    }
};




class Solution {
public:
    double average(vector<int>& salary) {  //without sorting
        int mn = INT_MAX, mx = INT_MIN;
        double sum = 0;

        for (int x : salary) {
            mn = min(mn, x);
            mx = max(mx, x);
            sum += x;
        }

        return (sum - mn - mx) / (salary.size() - 2);
    }
};



/*

qno 3760  https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/


3760. Maximum Substrings With Distinct Start
Medium

Companies
Hint
You are given a string s consisting of lowercase English letters.

Return an integer denoting the maximum number of substrings you can split s into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).

 

Example 1:

Input: s = "abab"

Output: 2

Explanation:

Split "abab" into "a" and "bab".
Each substring starts with a distinct character i.e 'a' and 'b'. Thus, the answer is 2.
Example 2:

Input: s = "abcd"

Output: 4

Explanation:

Split "abcd" into "a", "b", "c", and "d".
Each substring starts with a distinct character. Thus, the answer is 4.
Example 3:

Input: s = "aaaa"

Output: 1

Explanation:

All characters in "aaaa" are 'a'.
Only one substring can start with 'a'. Thus, the answer is 1.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.


*/


class Solution {
public:
    int maxDistinct(string s) {  //tc=O(n), sc=O(1) only 26 alphabets
        unordered_set<char> used;
        // Each substring must start with a unique character.
        // So the maximum number of substrings = number of distinct chars in s.

        for (char c : s) {
            used.insert(c);
        }

        return used.size();
    }
};



class Solution {
public:
    int maxDistinct(string s) {  //tc=O(n), sc=O(1)
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a'] = 1;   // mark character as present
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            count += freq[i];    // count distinct chars
        }

        return count;  // max substrings = distinct chars
    }
};
