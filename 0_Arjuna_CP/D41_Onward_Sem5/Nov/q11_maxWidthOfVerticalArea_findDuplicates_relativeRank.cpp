


/*

19th Nov 2025 (Wednesday)


qno 1637  https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/


1637. Widest Vertical Area Between Two Points Containing No Points
Easy
Topics

Companies
Hint
Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.

 

Example 1:

​
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.
Example 2:

Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3
 

Constraints:

n == points.length
2 <= n <= 105
points[i].length == 2
0 <= xi, yi <= 109



*/


class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) { //TC=O(n logN), SC=O(n) because we are storing the x-coordinates in a separate vector.
        
        //step1: Extract x-coordinates O(n) SC
        vector<int> xCoords;
        for(auto& point : points) {
            xCoords.push_back(point[0]);
        }

        //step2: sort xCoord - O(logN) tc
        sort(xCoords.begin(), xCoords.end());

        //step3:  Calculate the maximum width between consecutive x-coord
        int maxWidth = 0;
        for(int i=1; i<xCoords.size(); ++i) {
            maxWidth = max(maxWidth, xCoords[i] - xCoords[i-1]);
        }

        return maxWidth;
    }
};




/*

qno 442  https://leetcode.com/problems/find-all-duplicates-in-an-array/description/


442. Find All Duplicates in an Array
Attempted
Medium
Topics
premium lock icon
Companies
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.



*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) { //myFirstWrongApproach - Duplicates can appear anywhere in the array, not necessarily in consecutive positions
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<=n; i++) {
            if(nums[i-1] == nums[i]) {  //when eq means DUPLICATE
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};





class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; ++i) {
            int idx = abs(nums[i]) - 1;   

            if(nums[idx] < 0) {   
                //If the value at index is negative, it means the number has appeared before
                ans.push_back(abs(nums[i]));
            } else {
                // Otherwise, negate the value at this index to mark it as visited
                nums[idx] = -nums[idx];
            }
        }

        return ans;
    }
};


#include <vector>
#include <algorithm>  // For sort
#include <list>       // For list
using namespace std;

class Solution {
public:
    list<int> findDuplicates(vector<int>& nums) {
        list<int> answer;  
        
 
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // Find duplicates by comparing adjacent elements
        for (int i = 1; i < n; i++) {
            if (nums[i-1] == nums[i]) {
                answer.push_back(nums[i]);  // Add the duplicate to the list
            }
        }
        
        return answer;
    }
};



/*

qno 530 https://leetcode.com/problems/next-greater-element-ii/


503. Next Greater Element II
Solved
Medium
Topics

Companies
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
693,991/1M
Acceptance Rate
67.4%
Topics
Array
Stack
Monotonic Stack


*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { //TC=O(n)=SC
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s; 

        //revOrderLoop
        for(int i=2*n-1; i>=0; i--) {  
            while(s.size() > 0 && nums[s.top()]  <= nums[i % n]) {
                s.pop();
            }

            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i % n); 
        }

        return ans;
    }
};





/*

qno 506  https://leetcode.com/problems/relative-ranks/description/

506. Relative Ranks
Easy
Topics

Companies
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

 

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

 

Constraints:

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.
 
Discover more
Medal
Seen this question in a real interview before?
1/5
Yes
No
Accepted
384,158/519.1K
Acceptance Rate
74.0%
Topics
Array
Sorting
Heap (Priority Queue)




*/



class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) { //TC=O(n logN), SC=O(n)
        //step1: Create a copy of score
        vector<int> sortedScores = score;
        
        //step2: Sort in descending order
        sort(sortedScores.begin(), sortedScores.end(), greater<int>());
        
        //step3: Create a map to store the rank of each score O(N)
        unordered_map<int, string> rankMap;
        
        //step4: Assign ranks based on sorted order
        for (int i = 0; i < sortedScores.size(); i++) {
            if (i == 0) {
                rankMap[sortedScores[i]] = "Gold Medal";
            } else if (i == 1) {
                rankMap[sortedScores[i]] = "Silver Medal";
            } else if (i == 2) {
                rankMap[sortedScores[i]] = "Bronze Medal";
            } else {
                rankMap[sortedScores[i]] = to_string(i + 1);  // Ranks for 4th, 5th, etc.
            }
        }
        
        //step5: Generate the result based on original score 
        vector<string> result;
        for (int scoreValue : score) {
            result.push_back(rankMap[scoreValue]);
        }
        
        return result;
    }
};




/*

qno 387  https://leetcode.com/problems/first-unique-character-in-a-string/description/


387. First Unique Character in a String
Solved
Easy
Topics

Companies
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
 
Discover more
Developer laptop backpacks
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,190,944/3.4M
Acceptance Rate
64.5%
Topics
Hash Table
String
Queue
Counting


*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        
        // First pass: count the frequency of each character
        for(int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        
        // Second pass: find the first character with a frequency of 1
        for(int i = 0; i < s.size(); i++) {
            if(m[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;  // No unique character found
    }
};


// TC = O(n) = SC
