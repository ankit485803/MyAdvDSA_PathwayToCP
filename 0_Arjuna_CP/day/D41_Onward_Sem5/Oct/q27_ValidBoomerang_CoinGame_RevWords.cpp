



/*

6th Nov 2025 (Thursday)


qno  1037   https://leetcode.com/problems/valid-boomerang/description/


1037. Valid Boomerang
Easy
Topics

Companies
Hint
Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.

A boomerang is a set of three points that are all distinct and not in a straight line.

 

Example 1:

Input: points = [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: points = [[1,1],[2,2],[3,3]]
Output: false
 

Constraints:

points.length == 3
points[i].length == 2
0 <= xi, yi <= 100


*/


class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {  //myConcepts
        
        //apporach1: CoordinateGeometry 
        //prove that these threePoints can form straightLine return false else true - CONVERSE method
        //twoWays: AngleProperty - where adjacentSum = 180 and vecotrProp
        
    }
};



class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {  //TC=O(1)=SC
        
        //apporach1: CoordinateGeometry 
        //prove that these threePoints can form straightLine return false else true - CONVERSE method
        //twoWays: AngleProperty - where adjacentSum = 180 and vecotrProp


        // Extract points
        auto &A = points[0];
        auto &B = points[1];
        auto &C = points[2];
        
        // Check distinctness
        if ((A[0] == B[0] && A[1] == B[1]) ||
            (A[0] == C[0] && A[1] == C[1]) ||
            (B[0] == C[0] && B[1] == C[1])) {
            return false;
        }

        // Check collinearity using crossProduct
        int x1 = B[0] - A[0];
        int y1 = B[1] - A[1];
        int x2 = C[0] - A[0];
        int y2 = C[1] - A[1];

        // If area = 0, points are collinear
        return (x1 * y2 - y1 * x2) != 0;


    }
};




/*

qno 3222   https://leetcode.com/problems/find-the-winning-player-in-coin-game/description/


3222. Find the Winning Player in Coin Game
Easy
Topics

Companies
Hint
You are given two positive integers x and y, denoting the number of coins with values 75 and 10 respectively.

Alice and Bob are playing a game. Each turn, starting with Alice, the player must pick up coins with a total value 115. If the player is unable to do so, they lose the game.

Return the name of the player who wins the game if both players play optimally.

 

Example 1:

Input: x = 2, y = 7

Output: "Alice"

Explanation:

The game ends in a single turn:

Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.
Example 2:

Input: x = 4, y = 11

Output: "Bob"

Explanation:

The game ends in 2 turns:

Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.
Bob picks 1 coin with a value of 75 and 4 coins with a value of 10.
 

Constraints:

1 <= x, y <= 100


*/

class Solution {
public:
    string winningPlayer(int x, int y) {
        
        //EachTurn start with Alice, 
        //winningReq: 1 coin of 75 x and 4 coins of 10 y whose sum = 115

        //approach: GameSimulationLogic - Simple arithmetic reasoning

        // Each move requires 1 coin of 75 and 4 coins of 10
        int turns = min(x, y / 4);
        
        // If turns is odd → Alice wins, else Bob
        if (turns % 2 == 1)
            return "Alice";
        else
            return "Bob";
        


    }
};



/*

qno 1578   https://leetcode.com/problems/minimum-time-to-make-rope-colorful/




1578. Minimum Time to Make Rope Colorful
Medium
Topics

Companies
Hint
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
Return the minimum time Bob needs to make the rope colorful.



Example 1:
Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.



Example 2:
Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.



Example 3:
Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
 

Constraints:

n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.




*/


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) { //TC=O(n), sc=O(1)

        int totalTime = 0;
        int n = colors.size();


        for (int i = 1; i < n; i++) {
            // If two consecutive balloons have the same color
            if (colors[i] == colors[i - 1]) {
                // Remove the one with smaller removal time
                totalTime += min(neededTime[i], neededTime[i - 1]);
                
                // Keep the balloon with larger neededTime
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }

        return totalTime;
    }
};




/*

qno 151  https://leetcode.com/problems/reverse-words-in-a-string/description/


151. Reverse Words in a String
Solved
Medium
Topics

Companies
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?


*/


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i=0; i<n; i++) {
            string word = "";
            while(i<n && s[i] != ' ') {   //step1: POSITION last to first
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());  //step2: FORM ko tik kar rahe h each word ka
            if(word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};


// TC = O(n) , SC = O(1)