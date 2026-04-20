

/*

20th April 2026 (Monday)

qno 2078  https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/?envType=daily-question&envId=2026-04-20


2078. Two Furthest Houses With Different Colors
Solved
Easy
Topics

Companies
Hint
There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

Return the maximum distance between two houses with different colors.

The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

 

Example 1:


Input: colors = [1,1,1,6,1,1,1]
Output: 3
Explanation: In the above image, color 1 is blue, and color 6 is red.
The furthest two houses with different colors are house 0 and house 3.
House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
Note that houses 3 and 6 can also produce the optimal answer.
Example 2:


Input: colors = [1,8,3,8,3]
Output: 4
Explanation: In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
The furthest two houses with different colors are house 0 and house 4.
House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
Example 3:

Input: colors = [0,1]
Output: 1
Explanation: The furthest two houses with different colors are house 0 and house 1.
House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.
 

Constraints:

n == colors.length
2 <= n <= 100
0 <= colors[i] <= 100
Test data are generated such that at least two houses have different colors.
 
Discover more
Online programming courses
Seen this question in a real interview before?
1/6
Yes
No
Accepted
122,581/180K
Acceptance Rate
68.1%
Topics
Mid Level
Array
Greedy
Weekly Contest 268


*/



class Solution {
public:
    int maxDistance(vector<int>& colors) {  //tc=O(n^2), sc=O(1) oldSubmission 19th Dec 2025
        int n = colors.size();

        int maxDist = 0;
        for(int i=0; i<n; i++) {
            for(int j=n-1; j>i; j--) {
                if(colors[i] != colors[j]) {
                    int dist = abs(i - j);

                    maxDist = max(dist, maxDist);
                }
            }
        }

        return maxDist;
    }
};



class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        //take twoPointer and initilize 0, nextIdx  WRONG ans
        int i=0, j = 1;

        while(i <= colors.size()) {
            if(colors[i] != colors[j]) {  //twoDiffHuses
                int dist = abs(i - j);
                ans = max(ans, dist);  //maxVal
                i++;
                j++;
            }
        }

        return ans;
    }
};




class Solution {
public:
    int maxDistance(vector<int>& colors) {  //tcO(n^2) due to nestedLoop, sc=O(1) 
        int n = colors.size();
        int ans = 0;  //maxDist

        for(int i=0; i<n; i++) {
            for(int j=n-1; j>i; j--) {  //when j > i hoga tab tak
                if(colors[i] != colors[j]) {
                    ans = max(ans, abs(i - j)); 
                }
            }
        }

        return ans;
    }
};



//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (colors[i] != colors[j]) {
                    result = max(result, j - i);
                }
            }
        }
        return result;
    }
};

//Approach-2 (Improved Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n-1; j > i; j--) {
                if (colors[i] != colors[j]) {
                    result = max(result, j - i);
                    break;
                }
            }
        }
        return result;
    }
};



//Approach-3 (2 Pass Solution)
//T.C : O(2*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int result = 0;

        int i = 0;
        while(colors[i] == colors[n-1]) i++;

        result = max(result, abs(i - (n-1)));

        i = n-1;
        while(colors[0] == colors[i]) i--;

        result = max(result, i);

        return result;
    }
};

//Approach-4 (1 Pass Solution)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int result = 0;

       for(int i = 0; i < n; i++) {
            if(colors[i] != colors[0]) {
                result = max(result, i);
            }

            if(colors[i] != colors[n-1]) {
                result = max(result, abs(i - (n-1)));
            }
       }

       return result;
    }
};