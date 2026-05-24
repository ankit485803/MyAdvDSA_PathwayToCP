

/*

24th May 2026 (Sunday)

qno 1310  https://leetcode.com/problems/jump-game-v/description/?envType=daily-question&envId=2026-05-24


1340. Jump Game V
Hard
Topics

Companies
Hint
Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and  0 < x <= d.
i - x where: i - x >= 0 and  0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

 

Example 1:


Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
Output: 4
Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
Similarly You cannot jump from index 3 to index 2 or index 1.
Example 2:

Input: arr = [3,3,3,3,3], d = 3
Output: 1
Explanation: You can start at any index. You always cannot jump to any index.
Example 3:

Input: arr = [7,6,5,4,3,2,1], d = 1
Output: 7
Explanation: Start at index 0. You can visit all the indicies. 
 

Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 105
1 <= d <= arr.length
 
Discover more
Games
Game
programming
Seen this question in a real interview before?
1/6
Yes
No
Accepted
73,438/102K
Acceptance Rate
72.0%
Topics
Senior Staff
Array
Dynamic Programming
Sorting
Weekly Contest 174


*/



//Approach-1 (Recursion + Memoization)
//T.C : O(n*d)
//S.C : O(n)
class Solution {
public:
    int n;
    vector<int> t;

    int solve(vector<int>& arr, int d, int i) {
        if (t[i] != -1)
            return t[i];

        int result = 1; // count current index also

        // move left
        for (int j = i - 1; j >= max(0, i - d); j--) {
            // can't jump further once taller/equal element appears
            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

        // move right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            // can't jump further once taller/equal element appears
            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

        return t[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        t.resize(n, -1);

        int maxJump = 1;
        // We need to try from every index
        for (int i = 0; i < n; i++) {
            maxJump = max(maxJump, solve(arr, d, i));
        }

        return maxJump;
    }
};


//Approach-2 (Bottom-Up DP using Sorting)
//T.C : O(n*d)
//S.C : O(n)
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        // t[i] = maximum jumps starting from index i
        vector<int> t(n, 1);

        /*
            In recursion + memoization:
            solve(i) depends on smaller elements only.
            So in bottom-up, process smaller values first.
        */
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(begin(vec), end(vec));

        for (auto& it : vec) {
            int val = it.first;
            int i   = it.second;

            // move left
            for (int j = i - 1; j >= max(0, i - d); j--) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }

            // move right
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }
        }

        return *max_element(begin(t), end(t));
    }
};