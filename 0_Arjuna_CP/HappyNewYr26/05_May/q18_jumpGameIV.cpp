

/*

18th May 2026 (Monday)

qno 1345  https://leetcode.com/problems/jump-game-iv/?envType=daily-question&envId=2026-05-18

1345. Jump Game IV
Hard
Topics

Companies
Hint
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 

Constraints:

1 <= arr.length <= 5 * 104
-108 <= arr[i] <= 108
 
Seen this question in a real interview before?
1/6
Yes
No
Accepted
187,989/390.9K
Acceptance Rate
48.1%
Topics
Senior Staff
Array
Hash Table
Breadth-First Search
Biweekly Contest 19

*/


class Solution {
public:
    int minJumps(vector<int>& arr) {  //tc=O(n)=sc using BFS

        int n = arr.size();

        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);

        // value -> list of indices
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> que;
        que.push(0);

        visited[0] = true;

        int steps = 0;

        while (!que.empty()) {

            int sz = que.size();

            while (sz--) {

                int curr = que.front();
                que.pop();

                // reached end
                if (curr == n - 1)
                    return steps;

                int left = curr - 1;
                int right = curr + 1;

                // i - 1
                if (left >= 0 && !visited[left]) {
                    visited[left] = true;
                    que.push(left);
                }

                // i + 1
                if (right < n && !visited[right]) {
                    visited[right] = true;
                    que.push(right);
                }

                // same value jumps
                for (int idx : mp[arr[curr]]) {
                    if (!visited[idx]) {
                        visited[idx] = true;
                        que.push(idx);
                    }
                }

                // IMPORTANT optimization
                mp.erase(arr[curr]);
            }

            steps++;
        }

        return -1;
    }
};