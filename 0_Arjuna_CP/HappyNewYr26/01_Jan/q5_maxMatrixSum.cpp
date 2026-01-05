


/*


5th Jan 2026 (Monday - shreGanesha firstMondayOfthisYr)


qno 1975   https://leetcode.com/problems/maximum-matrix-sum/?envType=daily-question&envId=2026-01-05

es problem mai DP concepts used ho raha hai




1975. Maximum Matrix Sum
Medium
Topics

Companies
Hint
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:


Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
Example 2:


Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
 

Constraints:

n == matrix.length == matrix[i].length
2 <= n <= 250
-105 <= matrix[i][j] <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
161,536/242.7K
Acceptance Rate
66.5%
Topics
Array
Greedy
Matrix
Biweekly Contest 59



*/



class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {  //tcO(n*n), sc=O(1)
        long long totalSum = 0;  
        long long minAbsVal = LONG_MAX;  
        int negativeCount = 0; 
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                int num = matrix[i][j];
                totalSum += abs(num);
                minAbsVal = min(minAbsVal, (long long)abs(num));  // Cast abs(num) to long long
                if (num < 0) {
                    negativeCount++;
                }
            }
        }
        
        // If we have an odd count of negative numbers, one negative number must remain
        if (negativeCount % 2 == 1) {
            totalSum -= 2 * minAbsVal;
        }
        
        return totalSum;
    }
};



