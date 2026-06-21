https://repos.ecosyste.ms/hosts/GitHub/owners/ankit485803

/*

21st June 2026 (Sunday - after endSem6)  happyFather's Day

https://leetcode.com/contest/weekly-contest-507/

q1 https://leetcode.com/contest/weekly-contest-507/problems/maximum-manhattan-distance-after-all-moves/

probNo 3968  https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/description/


3968. Maximum Manhattan Distance After All Moves
Medium
premium lock icon
Companies
You are given a string moves consisting of the characters 'U', 'D', 'L', 'R', and '_'.

Starting from the origin (0, 0), each character represents one move on a 2D plane:

'U': Move up by 1 unit.
'D': Move down by 1 unit.
'L': Move left by 1 unit.
'R': Move right by 1 unit.
'_': Can be independently replaced with any one of 'U', 'D', 'L', or 'R'.
Return the maximum Manhattan distance from the origin that can be achieved after all moves have been performed.

The Manhattan distance between two points (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

 

Example 1:

Input: moves = "L_D_"

Output: 4

Explanation:

One optimal choice is:

'L': (0, 0) -> (-1, 0)
'_' treated as 'D': (-1, 0) -> (-1, -1)
'D': (-1, -1) -> (-1, -2)
'_' treated as 'L': (-1, -2) -> (-2, -2)
The final Manhattan distance from the origin is |0 - (-2)| + |0 - (-2)| = 4.

Example 2:

Input: moves = "U_R"

Output: 3

Explanation:

One optimal choice is:

'U': (0, 0) -> (0, 1)
'_' treated as 'U': (0, 1) -> (0, 2)
'R': (0, 2) -> (1, 2)
The final Manhattan distance from the origin is |0 - 1| + |0 - 2| = 3.

 

Constraints:

1 <= moves.length <= 105
moves consists of only 'U', 'D', 'L', 'R', and '_'.
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
24,912/40.1K
Acceptance Rate
62.1%
Topics
Weekly Contest 507

*/


step1: coverrt all the moves and find

step2: st point (x1, y1) and endPt (x2, y2)

step3: apply marathonDist formla


class Solution {
public:
    int maxDistance(string moves) {
        int U = 0, D = 0, L = 0, R = 0, k = 0;

        for (char c : moves) {
            if (c == 'U') U++;
            else if (c == 'D') D++;
            else if (c == 'L') L++;
            else if (c == 'R') R++;
            else k++; // '_'
        }

        return abs(R - L) + abs(U - D) + k;
    }
};



class Solution {
public:
    int maxDistance(string moves) {  //tc=O(n), sc=(1)
        
        //approach: x = R-L, y = U-D mod values, ans = x + y + k
        //k means no of -

        int U = 0, D = 0, L = 0, R = 0, k = 0;

        for(char c : moves) {
            if(c == 'U') U++;
            else if(c == 'D') D++;
            else if(c == 'L') L++;
            else if(c == 'R') R++;
            else k++;  //this is for -
            
        }

        int ans = abs(R - L) + abs(U - D) + k;
        return ans;
    }
};


class Solution {
public:
    int maxDistance(string moves) {  //tc=O(n), sc=(1)
        
        //approach: x = R-L, y = U-D mod values, ans = x + y + k
        //k means no of -

        int U = 0, D = 0, L = 0, R = 0, k = 0;

        for(char c : moves) {
            if(c == 'U') U++;
            else if(c == 'D') D++;
            else if(c == 'L') L++;
            else if(c == 'R') R++;
            else k++;  //this is for -
            
        }

        int ans = abs(R - L) + abs(U - D) + k;
        return ans;
    }
};