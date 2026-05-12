

/*

12th May 2026 (Tuesday)

qno 1665  https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/?envType=daily-question&envId=2026-05-12

1665. Minimum Initial Energy to Finish Tasks
Solved
Hard
Topics

Companies
Hint
You are given an array tasks where tasks[i] = [actuali, minimumi]:

actuali is the actual amount of energy you spend to finish the ith task.
minimumi is the minimum amount of energy you require to begin the ith task.
For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.

You can finish the tasks in any order you like.

Return the minimum initial amount of energy you will need to finish all the tasks.

 

Example 1:

Input: tasks = [[1,2],[2,4],[4,8]]
Output: 8
Explanation:
Starting with 8 energy, we finish the tasks in the following order:
    - 3rd task. Now energy = 8 - 4 = 4.
    - 2nd task. Now energy = 4 - 2 = 2.
    - 1st task. Now energy = 2 - 1 = 1.
Notice that even though we have leftover energy, starting with 7 energy does not work because we cannot do the 3rd task.
Example 2:

Input: tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
Output: 32
Explanation:
Starting with 32 energy, we finish the tasks in the following order:
    - 1st task. Now energy = 32 - 1 = 31.
    - 2nd task. Now energy = 31 - 2 = 29.
    - 3rd task. Now energy = 29 - 10 = 19.
    - 4th task. Now energy = 19 - 10 = 9.
    - 5th task. Now energy = 9 - 8 = 1.
Example 3:

Input: tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
Output: 27
Explanation:
Starting with 27 energy, we finish the tasks in the following order:
    - 5th task. Now energy = 27 - 5 = 22.
    - 2nd task. Now energy = 22 - 2 = 20.
    - 3rd task. Now energy = 20 - 3 = 17.
    - 1st task. Now energy = 17 - 1 = 16.
    - 4th task. Now energy = 16 - 4 = 12.
    - 6th task. Now energy = 12 - 6 = 6.
 

Constraints:

1 <= tasks.length <= 105
1 <= actual​i <= minimumi <= 104
 
Discover more
Programming interview prep
Seen this question in a real interview before?
1/6
Yes
No
Accepted
64,150/87.9K
Acceptance Rate
73.0%
Topics
Senior Staff
Array
Greedy
Sorting
Weekly Contest 216


*/



//Approach (Binary search on answer + greedy sorting)
//T.C : O(n*logn)
//S.C : O(1)
class Solution {
public:

    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for(auto &task : tasks) {
            int actual  = task[0];
            int minimum = task[1];

            if(minimum > mid) {
                return false;
            }

            mid -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        int l = 0;
        int r = 1e9;

        int result = INT_MAX;

        auto lambda = [](auto &task1, auto& task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lambda);


        while(l <= r) {
            int mid = l + (r-l)/2;

            if(isPossible(tasks, mid)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};