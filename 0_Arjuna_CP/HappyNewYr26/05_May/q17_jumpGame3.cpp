

/*
17th May 2026 (Sunday)

qno 1306  https://leetcode.com/problems/jump-game-iii/submissions/2005249404/?envType=daily-question&envId=2026-05-17

1306. Jump Game III
Attempted
Medium
Topics

Companies
Hint
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
 

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] < arr.length
0 <= start < arr.length
 
Discover more
Games
Game
Seen this question in a real interview before?
1/6
Yes
No
Accepted
319,759/472.5K
Acceptance Rate
67.7%
Topics
Staff
Array
Depth-First Search
Breadth-First Search
Weekly Contest 169


*/



class Solution {
public:
    int n;
    bool dfs(vector<int>& arr, int i) {
        if(i < 0 || i >= n || arr[i] < 0) {
            return false;
        }

        if(arr[i] == 0) 
            return true;

        arr[i] *= -1;
        
        int left = dfs(arr, i - arr[i]);    
        int right = dfs(arr, i + arr[i]);   

        return left || right; 
    }

    bool canReach(vector<int>& arr, int start) {  //tc=O(n), sc=O(n) stackUsed
        n = arr.size();

        return dfs(arr, start);
    }
};



//Approach-2 (BFS with in-place visited marking)
//T.C : O(n)
//S.C : O(n) — queue space
class Solution {
public:
    bool bfs(vector<int>& arr, int start, int n) {
        queue<int> que;
        que.push(start);

        while(!que.empty()) {
            int curr = que.front();
            que.pop();

            //reached 0
            if(arr[curr] == 0)
                return true;

            //This was visited before. Ignore
            if(arr[curr] < 0)
                continue;

            int left  = curr + arr[curr];
            int right = curr - arr[curr];

            if(left >= 0 && left < n)
                que.push(left);
            if(right >= 0 && right < n)
                que.push(right);

            //curr is visited and its neighbours are explored. We don't need it
            arr[curr] = -arr[curr];
        }

        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = (int) arr.size();
        return bfs(arr, start, n);
    }
};