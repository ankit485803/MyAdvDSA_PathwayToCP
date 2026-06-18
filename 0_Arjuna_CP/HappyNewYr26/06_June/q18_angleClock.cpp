

/*

18th June 2026 (Thursday)

qno 1344  https://leetcode.com/problems/angle-between-hands-of-a-clock/?envType=daily-question&envId=2026-06-18


1344. Angle Between Hands of a Clock
Medium
Topics
premium lock icon
Companies
Hint
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

 

Example 1:


Input: hour = 12, minutes = 30
Output: 165
Example 2:


Input: hour = 3, minutes = 30
Output: 75
Example 3:


Input: hour = 3, minutes = 15
Output: 7.5
 

Constraints:

1 <= hour <= 12
0 <= minutes <= 59
 
Discover more
Clocks
Clock
programming
Seen this question in a real interview before?
1/6
Yes
No
Accepted
203,107/300.7K
Acceptance Rate
67.5%
Topics
Staff
Math
Biweekly Contest 19


*/


class Solution {
public:
    double angleClock(int hour, int minutes) {  //tc=O(1)=sc
        //using maths formula angle b/w hour and minutes hand
        double angle = abs(30 * hour - 5.5 * minutes);

        return angle;
    }
};


class Solution {
public:
    double angleClock(int hour, int minutes) {  //tc=O(1)=sc
        //using maths formula angle b/w hour and minutes hand
        double angle = abs(30.0 * hour - 5.5 * minutes);

        return min(angle, 360.0 - angle);
    }
};
