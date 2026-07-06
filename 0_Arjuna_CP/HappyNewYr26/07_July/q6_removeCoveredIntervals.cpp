

/*

6th July 2026 (Monday)

qno  1288  https://leetcode.com/problems/remove-covered-intervals/?envType=daily-question&envId=2026-07-06

1288. Remove Covered Intervals
Medium
Topics

Companies
Hint
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
 

Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= li < ri <= 105
All the given intervals are unique.
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
179,651/312.9K
Acceptance Rate
57.4%
Topics
Senior
Array
Sorting
Biweekly Contest 15

*/

//Approach (Using sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        auto lambda = [](auto &vec1, auto &vec2) {
            if (vec1[1] != vec2[1])
                return vec1[1] < vec2[1];
            return vec1[0] > vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        int result = 0;
        int first  = -1;
        int second = -1;

        for (int i = 0; i < n; ++i) {
            int l = intervals[i][0];
            int r = intervals[i][1];


            if (l <= first)
                continue;

            if (l > second) {
                result += 2;
                second = r;
                first = r - 1;
            } else {
                result += 1;
                first = second;
                second = r;
            }
        }
        return result;
    }
};



class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {  //tc=O(logN), sc=O(1) using sorting
        vector<vector<int>> result;
        int n = intervals.size();

        auto lambda = [] (vector<int>& vec1, vector<int>& vec2) {
            if(vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }

            return vec1[0] < vec2[0];
        };

        sort(begin(intervals), end(intervals), lambda);  //customSorting

        result.push_back(intervals[0]);

        for(int i=1; i<n; i++) {
            if(result.back()[0] <= intervals[i][0] && result.back()[1] >= intervals[i][1]) {
                continue;
            }

            result.push_back(intervals[i]);
        }

        return result.size();
    }
};