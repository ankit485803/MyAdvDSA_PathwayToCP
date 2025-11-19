


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
