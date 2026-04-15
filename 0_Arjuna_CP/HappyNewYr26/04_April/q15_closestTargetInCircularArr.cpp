

/*

15th April 2026 (Wednesday)


qno 2515   https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/?envType=daily-question&envId=2026-04-15


2515. Shortest Distance to Target String in a Circular Array
Solved
Easy
Topics

Companies
Hint
You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.

 

Example 1:

Input: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
Output: 1
Explanation: We start from index 1 and can reach "hello" by
- moving 3 units to the right to reach index 4.
- moving 2 units to the left to reach index 4.
- moving 4 units to the right to reach index 0.
- moving 1 unit to the left to reach index 0.
The shortest distance to reach "hello" is 1.
Example 2:

Input: words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
Output: 1
Explanation: We start from index 0 and can reach "leetcode" by
- moving 2 units to the right to reach index 2.
- moving 1 unit to the left to reach index 2.
The shortest distance to reach "leetcode" is 1.
Example 3:

Input: words = ["i","eat","leetcode"], target = "ate", startIndex = 0
Output: -1
Explanation: Since "ate" does not exist in words, we return -1.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] and target consist of only lowercase English letters.
0 <= startIndex < words.length
 
Discover more
Cloud computing services
Seen this question in a real interview before?
1/5
Yes
No
Accepted
80,048/133.6K
Acceptance Rate
59.9%
Topics
Mid Level
Array
String
Weekly Contest 325

*/


class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {  
        int n = words.size();
        int result = INT_MAX;

        for(int i=0; i<n; i++) {  //tc=O(n * Length), sc=O(1)
            if(words[i] == target) {
                int straightDist = abs(i - startIndex);
                int circularDist = n - straightDist;  //createdFormula on penPaperDiag

                result = min({result, straightDist, circularDist});
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};