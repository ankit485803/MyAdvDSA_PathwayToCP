

/*


3rd April 2026 (Friday)


qno 3661  https://leetcode.com/problems/maximum-walls-destroyed-by-robots/?envType=daily-question&envId=2026-04-03

3661. Maximum Walls Destroyed by Robots
Solved
Hard
Topics

Companies
Hint
There is an endless straight line populated with some robots and walls. You are given integer arrays robots, distance, and walls:
robots[i] is the position of the ith robot.
distance[i] is the maximum distance the ith robot's bullet can travel.
walls[j] is the position of the jth wall.
Every robot has one bullet that can either fire to the left or the right at most distance[i] meters.

A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it immediately stops at that robot and cannot continue.

Return the maximum number of unique walls that can be destroyed by the robots.

Notes:

A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
Robots are not destroyed by bullets.
 

Example 1:

Input: robots = [4], distance = [3], walls = [1,10]

Output: 1

Explanation:

robots[0] = 4 fires left with distance[0] = 3, covering [1, 4] and destroys walls[0] = 1.
Thus, the answer is 1.
Example 2:

Input: robots = [10,2], distance = [5,1], walls = [5,2,7]

Output: 3

Explanation:

robots[0] = 10 fires left with distance[0] = 5, covering [5, 10] and destroys walls[0] = 5 and walls[2] = 7.
robots[1] = 2 fires left with distance[1] = 1, covering [1, 2] and destroys walls[1] = 2.
Thus, the answer is 3.
Example 3:
Input: robots = [1,2], distance = [100,1], walls = [10]

Output: 0

Explanation:

In this example, only robots[0] can reach the wall, but its shot to the right is blocked by robots[1]; thus the answer is 0.

 

Constraints:

1 <= robots.length == distance.length <= 105
1 <= walls.length <= 105
1 <= robots[i], walls[j] <= 109
1 <= distance[i] <= 105
All values in robots are unique
All values in walls are unique
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
28,179/68.3K
Acceptance Rate
41.3%
Topics
Senior Staff
Array
Binary Search
Dynamic Programming
Sorting
Weekly Contest 464


*/


//Approach (Recursion + Memoization + Binary Search)
//T.C : O(n * log(w) + nlogn + wlogw), n = robots.size(), w = walls.size()
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> t;

    int countWalls(vector<int>& walls, int l, int r) {
        int left  = lower_bound(begin(walls), end(walls), l) - begin(walls);
        int right = upper_bound(begin(walls), end(walls), r) - begin(walls);

        return right - left;

    }

    int solve(vector<int>& walls, vector<P>& roboDist, vector<P>& range, int i, int prevDir) {

        if(i == roboDist.size())
            return 0;
        
        if(t[i][prevDir] != -1)
            return t[i][prevDir];

        int leftStart = range[i].first;

        if(prevDir == 1) { //prev robot fired bullet rtowards right
            leftStart = max(leftStart, range[i-1].second + 1);
        }

        int leftTake = countWalls(walls, leftStart, roboDist[i].first) 
                        + solve(walls, roboDist, range, i+1, 0);
                    
        int rightTake = countWalls(walls, roboDist[i].first, range[i].second) 
                        + solve(walls, roboDist, range, i+1, 1);

        
        return t[i][prevDir] = max(leftTake, rightTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<P> roboDist(n);
        for (int i = 0; i < n; i++) {
            roboDist[i] = {robots[i], distance[i]};
        }

        sort(begin(roboDist), end(roboDist));
        sort(begin(walls), end(walls));

        //Prepare range vector for each robot
        vector<P> range(n);

        for(int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int d   = roboDist[i].second;

            int leftLimit  = (i == 0)   ? 1   : roboDist[i-1].first+1;
            int rightLimit = (i == n-1) ? 1e9 : roboDist[i+1].first-1;

            int L = max(pos - d, leftLimit);
            int R = min(pos + d, rightLimit);

            range[i] = {L, R};
        }

        t.assign(n+1, vector<int>(2, -1));

        //prev = 0/1 (previious robot hit buttlet to left/right)
        return solve(walls, roboDist, range, 0, 0);
    }
};

