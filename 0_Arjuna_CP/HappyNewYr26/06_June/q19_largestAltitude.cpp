

/*

19th June 2026 (Friday)

qno 1732  https://leetcode.com/problems/find-the-highest-altitude/?envType=daily-question&envId=2026-06-19

1732. Find the Highest Altitude
Easy
Topics

Companies
Hint
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

 

Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
 

Constraints:

n == gain.length
1 <= n <= 100
-100 <= gain[i] <= 100
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
814,316/965.5K
Acceptance Rate
84.3%
Topics
Mid Level
Array
Prefix Sum
Biweekly Contest 44

*/


class Solution {
public:
    int largestAltitude(vector<int>& gain) {  //tc=O(n), sc=O(1)
        int n = gain.size();
        vector<int> altitude(n+1);  //take arr size n+1

        altitude[0] = 0;  //firstElem always 0 because given in prob

        for(int i=0; i<n; i++) {
            altitude[i+1] = altitude[i] + gain[i]; 
        }

        return *max_element(altitude.begin(), altitude.end());
    }
};


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, maxAlt = 0;

        for (int g : gain) {
            curr += g;
            maxAlt = max(maxAlt, curr);
        }

        return maxAlt;
    }
};