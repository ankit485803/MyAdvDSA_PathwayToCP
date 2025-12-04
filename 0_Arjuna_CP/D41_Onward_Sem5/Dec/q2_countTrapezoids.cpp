



/*


3rd Dec 2025 (Wednesday - second day [CNS 301] of campusImersion and on firstDay only travelling)


qno  3623    https://leetcode.com/problems/count-number-of-trapezoids-i/




3623. Count Number of Trapezoids I
Medium
Topics

Companies
Hint
You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]

Output: 3

Explanation:



There are three distinct ways to pick four points that form a horizontal trapezoid:

Using points [1,0], [2,0], [3,2], and [2,2].
Using points [2,0], [3,0], [3,2], and [2,2].
Using points [1,0], [3,0], [3,2], and [2,2].
Example 2:

Input: points = [[0,0],[1,0],[0,1],[2,1]]

Output: 1

Explanation:



There is only one horizontal trapezoid that can be formed.

 

Constraints:

4 <= points.length <= 105
–108 <= xi, yi <= 108
All points are pairwise distinct.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
99,012/209.7K
Acceptance Rate
47.2%
Topics
Array
Hash Table
Math
Geometry
Weekly Contest 459




*/




class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        //Geometry and Maths COUNTING approach - tc=O(n)=sc  but give TLE
 
        static int MOD_VAL  = 1e9 + 7;

        // Step 1: Group points by y-coordinate
        unordered_map<int, int> y_count;
        for (const auto& p : points) {
            y_count[p[1]]++;
        }

        // Step 2: For each y level, calculate number of ways to pick pairs
        unordered_map<int, long long> y_pairs;
        for (const auto& entry : y_count) {
            int count = entry.second;
            if (count > 1) {
                y_pairs[entry.first] = (count * (count - 1)) / 2;
            }
        }


        // Step 3: Count total trapezoids
        long long total_trapezoids = 0;
        for (auto it1 = y_pairs.begin(); it1 != y_pairs.end(); ++it1) {
            for (auto it2 = next(it1); it2 != y_pairs.end(); ++it2) {
                total_trapezoids = (total_trapezoids + it1->second * it2->second) % MOD_VAL;
            }
        }

        return total_trapezoids;
        

    }
};






class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {  //tc=O(n)=sc
        unordered_map<int, long long> mp;

        // Count points per y-level
        for (auto &p : points) {
            mp[p[1]]++;
        }

        long long result = 0;
        long long prev = 0;   // sum of past C(n,2)

        for (auto &e : mp) {
            long long cnt = e.second;
            if (cnt >= 2) {
                long long cur = cnt * (cnt - 1) / 2;   // C(n,2)

                result = (result + cur * prev) % MOD;

                prev = (prev + cur) % MOD;
            }
        }

        return result;
    }
};

