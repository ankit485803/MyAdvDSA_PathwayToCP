

/*

18th June 2026 (Thursday)

qno 1344  https://leetcode.com/problems/angle-between-hands-of-a-clock/?envType=daily-question&envId=2026-06-18

0_Arjuna_CP\HappyNewYr26\06_June\q18_angleClock.cpp

*/

class Solution {
public:
    double angleClock(int hour, int minutes) {  //tc=O(1)=sc
        //using maths formula angle b/w hour and minutes hand
        double angle = abs(30.0 * hour - 5.5 * minutes);

        return min(angle, 360.0 - angle);
    }
};
