

/*


14th April 2026 (Tuesday)

qno 2463  https://leetcode.com/problems/minimum-total-distance-traveled/?envType=daily-question&envId=2026-04-14


2463. Minimum Total Distance Traveled
Attempted
Hard
Topics

Companies
Hint
There are some robots and factories on the X-axis. You are given an integer array robot where robot[i] is the position of the ith robot. You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.

The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be in the same position as a factory initially.

All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.

At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.

Return the minimum total distance traveled by all the robots. The test cases are generated such that all the robots can be repaired.

Note that

All robots move at the same speed.
If two robots move in the same direction, they will never collide.
If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.
If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
If the robot moved from a position x to a position y, the distance it moved is |y - x|.
 

Example 1:


Input: robot = [0,4,6], factory = [[2,2],[6,2]]
Output: 4
Explanation: As shown in the figure:
- The first robot at position 0 moves in the positive direction. It will be repaired at the first factory.
- The second robot at position 4 moves in the negative direction. It will be repaired at the first factory.
- The third robot at position 6 will be repaired at the second factory. It does not need to move.
The limit of the first factory is 2, and it fixed 2 robots.
The limit of the second factory is 2, and it fixed 1 robot.
The total distance is |2 - 0| + |2 - 4| + |6 - 6| = 4. It can be shown that we cannot achieve a better total distance than 4.
Example 2:


Input: robot = [1,-1], factory = [[-2,1],[2,1]]
Output: 2
Explanation: As shown in the figure:
- The first robot at position 1 moves in the positive direction. It will be repaired at the second factory.
- The second robot at position -1 moves in the negative direction. It will be repaired at the first factory.
The limit of the first factory is 1, and it fixed 1 robot.
The limit of the second factory is 1, and it fixed 1 robot.
The total distance is |2 - 1| + |(-2) - (-1)| = 2. It can be shown that we cannot achieve a better total distance than 2.
 

Constraints:

1 <= robot.length, factory.length <= 100
factory[j].length == 2
-109 <= robot[i], positionj <= 109
0 <= limitj <= robot.length
The input will be generated such that it is always possible to repair every robot.
 
Discover more
Online assessment tools
Seen this question in a real interview before?
1/5
Yes
No
Accepted
98,351/161.2K
Acceptance Rate
61.0%
Topics
Senior Staff
Array
Dynamic Programming
Sorting
Weekly Contest 318

*/


class Solution {
public:
    typedef long long ll;

    ll solve(int ri, int fi, vector<int>& robot, vector<int>& positions, vector<vector<ll>>& t) {
        if(ri >= robot.size()) {
            return 0; //no more distance to be covered
        }

        if(fi >= positions.size()) {
            // return INT_MAX;
            return 1e12;
        }

        if(t[ri][fi] != -1) {
            return t[ri][fi];
        }

        ll take_current_factory = abs(robot[ri] - positions[fi]) + solve(ri+1, fi+1, robot, positions, t);
        ll skip = solve(ri, fi+1, robot, positions, t);

        return t[ri][fi] = min(take_current_factory, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {  //tc=O(m*n)=sc using recussion and memoization
        //step1: sorting
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        int m = robot.size();

        //step2: expand factory positions to avoid tracking of limit and easy recursion
        vector<int> positions;
        for(int i=0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos = factory[i][0];

            for(int j=0; j < limit; j++) {
                positions.push_back(pos);
            }
        }
        int n = positions.size();
        vector<vector<ll>> t(m+1, vector<ll> (n+1, -1));

        //step3: solve
        return solve(0, 0, robot, positions, t);
    }
};