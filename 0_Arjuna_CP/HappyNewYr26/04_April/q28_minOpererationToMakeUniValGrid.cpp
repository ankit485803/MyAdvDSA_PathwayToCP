

/*

28th April 2026 (Tuesday)


qno 2033 https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2026-04-28

2033. Minimum Operations to Make a Uni-Value Grid
Solved
Medium
Topics

Companies
Hint
You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

 

Example 1:


Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
Example 2:


Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
Example 3:


Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
1 <= x, grid[i][j] <= 104
 
Discover more
Programming challenge rewards prizes
Seen this question in a real interview before?
1/6
Yes
No
Accepted
171,878/249.2K
Acceptance Rate
69.0%
Topics
Senior
Array
Math
Sorting
Matrix
Weekly Contest 262


*/



class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> vec;
        for(int i=0; i < m; i++) {
            for(int j=0; j < n; j++) {
                vec.push_back(grid[i][j]);
            }
        }

        int L = vec.size();  //m * n

        sort(begin(vec), end(vec));  //tc=O(L logL)

        int target = vec[L/2];
        int result = 0;
        for(int &num : vec) {  //O(m*n)
            if(num % x != target % x) {
                return -1; //notPossible
            }

            result += abs(target - num) / x;
        }

        return result;
    }
};


//optimized kar sakte hai partial sort karke, pur arrary ko sort nahi karo
   nth_element(begin(vec), begin(vec) + L/2, end(vec)); //O(L)

//Approach (Using Median and Maths)
//T.C : O(m*nlog(m*n))
//S.C : O(m*n)
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> vec;
        //O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vec.push_back(grid[i][j]);
            }
        }

        int L = vec.size(); //m*n

        //sort(begin(vec), end(vec)); //O(LlogL)
        nth_element(begin(vec), begin(vec) + L/2, end(vec)); //O(L)
        //{4, 2, 8, 6}
        //{4, 2, 6, 8} - nth_element
        //{2, 4, 6, 8} - complete sorting

        int target = vec[L/2];
        int result = 0;
        for(int &num : vec) { //O(m*n)
            if(num%x != target%x) {
                return -1;
            }

            result += abs(target-num)/x;
        }

        return result;
    }
};