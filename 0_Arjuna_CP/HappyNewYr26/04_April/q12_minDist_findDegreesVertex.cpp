

/*

12th April 2026 (Sunday)


qno 1320  https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/?envType=daily-question&envId=2026-04-12

1320. Minimum Distance to Type a Word Using Two Fingers
Attempted
Hard
Topics

Companies
Hint

You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.

For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
Given the string word, return the minimum total distance to type such string using only two fingers.

The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

 

Example 1:

Input: word = "CAKE"
Output: 3
Explanation: Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -> cost = 0 
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -> cost = 0 
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3
Example 2:

Input: word = "HAPPY"
Output: 6
Explanation: Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -> cost = 0
Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -> cost = 0
Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
 

Constraints:

2 <= word.length <= 300
word consists of uppercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
48,321/76K
Acceptance Rate
63.6%
Topics
Principal
String
Dynamic Programming
Weekly Contest 171


Line 24: Char 13: error: reference to overloaded function could not be resolved; did you mean to call it?
   24 |             next[j] = min(next[j], dp[j] + dist(prev, curr) );
      |             ^~~~
/usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_iterator_base_funcs.h:232:5: note: possible target for call
  223 |     next(_InputIterator __x, typename
      |     ^


🔴 Root Cause

next is also a standard function in C++ (std::next from <iterator>).
When you write:So when you later use next[j], it doesn't clearly resolve to your vector.

*/

class Solution {
public:
    int dist(int a, int b) {  //helperFunct
        if(a == b || b == 26) return 0;
        return abs(a/6 - b/6) + abs(a%6 - b%6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        const int INF = 1e9;
        vector<int> dp(27, INF);
        dp[26] = 0;

        for(int i=1; i<n; i++) {
            vector<int> dpNext(27, INF);
            int prev = word[i-1] - 'A';
            int curr = word[i] - 'A';
        }

        for(int j=0; j<=26; j++) {
            if(dp[j] == INF) continue;

            //moveSameFinger
            dpNext[j] = min(dpNext[j], dp[j] + dist(prev, curr) );

            //move to otherFinger
            dpNext[prev] = min(dpNext[prev], dp[j] + dist(j, curr) ); 
        }
        dp = dpNext;

        return *min_element(dp.begin(), dp.end());
    }
};



/*

qno 3898 https://leetcode.com/problems/find-the-degree-of-each-vertex/


3898. Find the Degree of Each Vertex
Easy

Companies
Hint
You are given a 2D integer array matrix of size n x n representing the adjacency matrix of an undirected graph with n vertices labeled from 0 to n - 1.

matrix[i][j] = 1 indicates that there is an edge between vertices i and j.
matrix[i][j] = 0 indicates that there is no edge between vertices i and j.
The degree of a vertex is the number of edges connected to it.

Return an integer array ans of size n where ans[i] represents the degree of vertex i.

 

Example 1:



Input: matrix = [[0,1,1],[1,0,1],[1,1,0]]

Output: [2,2,2]

Explanation:

Vertex 0 is connected to vertices 1 and 2, so its degree is 2.
Vertex 1 is connected to vertices 0 and 2, so its degree is 2.
Vertex 2 is connected to vertices 0 and 1, so its degree is 2.
Thus, the answer is [2, 2, 2].

Example 2:



Input: matrix = [[0,1,0],[1,0,0],[0,0,0]]

Output: [1,1,0]

Explanation:

Vertex 0 is connected to vertex 1, so its degree is 1.
Vertex 1 is connected to vertex 0, so its degree is 1.
Vertex 2 is not connected to any vertex, so its degree is 0.
Thus, the answer is [1, 1, 0].

Example 3:

Input: matrix = [[0]]

Output: [0]

Explanation:

There is only one vertex and it has no edges connected to it. Thus, the answer is [0].

 

Constraints:

1 <= n == matrix.length == matrix[i].length <= 100​​​​​​​
​​​​​​​matrix[i][i] == 0
matrix[i][j] is either 0 or 1
matrix[i][j] == matrix[j][i]
 
Discover more
Technical interview prep
Seen this question in a real interview before?
1/5
Yes
No
Accepted
27,709/30.1K
Acceptance Rate
91.9%
Topics
Weekly Contest 497


🔑 Key Insight
👉 Degree of a node = number of 1s in its row
Because: Each 1 means one connection (edge)


*/


class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {  //tc=O(n^2) due to nestedLoop
        int n = matrix.size();
        vector<int> ans(n, 0);  //sc=O(n)

        for(int i=0; i<n; i++) {  //outerLoop- selectNode
            int deg = 0; 
            for(int j=0; j<n; j++) {  //innerLoop-count its connections n*n works
                if(matrix[i][j] == 1) {
                    deg++;
                }
            }
            ans[i] = deg;  //reassig to ans
        }

        return ans;
    }
};