


/*


13th March 2026 (Friday)


qno 3296   https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/?envType=daily-question&envId=2026-03-13


13th or 13rd march 2026 is correct
13th March 2026 is the correct way to write the date using an ordinal number. 
In English, ordinal numbers for "13" always end in -th (thirteenth), unlike "3," which ends in -rd (third). 
While numbers ending in 3 like 23 (23rd) and 33 (33rd) use the "-rd" suffix, the "teens" (11th, 12th, and 13th) are exceptions and always use -th. 


Summary of Rules
Correct: 13th March 2026 (or March 13th, 2026).
Incorrect: 13rd March 2026.
Ordinal Rule: Use -st for 1, -nd for 2, and -rd for 3, except for the teens (11th, 12th, 13th), which all use -th


3296. Minimum Number of Seconds to Make Mountain Height Zero
Medium
Topics

Companies
Hint
You are given an integer mountainHeight denoting the height of a mountain.

You are also given an integer array workerTimes representing the work time of workers in seconds.

The workers work simultaneously to reduce the height of the mountain. For worker i:

To decrease the mountain's height by x, it takes workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example:
To reduce the height of the mountain by 1, it takes workerTimes[i] seconds.
To reduce the height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2 seconds, and so on.
Return an integer representing the minimum number of seconds required for the workers to make the height of the mountain 0.

 

Example 1:

Input: mountainHeight = 4, workerTimes = [2,1,1]

Output: 3

Explanation:

One way the height of the mountain can be reduced to 0 is:

Worker 0 reduces the height by 1, taking workerTimes[0] = 2 seconds.
Worker 1 reduces the height by 2, taking workerTimes[1] + workerTimes[1] * 2 = 3 seconds.
Worker 2 reduces the height by 1, taking workerTimes[2] = 1 second.
Since they work simultaneously, the minimum time needed is max(2, 3, 1) = 3 seconds.

Example 2:

Input: mountainHeight = 10, workerTimes = [3,2,2,4]

Output: 12

Explanation:

Worker 0 reduces the height by 2, taking workerTimes[0] + workerTimes[0] * 2 = 9 seconds.
Worker 1 reduces the height by 3, taking workerTimes[1] + workerTimes[1] * 2 + workerTimes[1] * 3 = 12 seconds.
Worker 2 reduces the height by 3, taking workerTimes[2] + workerTimes[2] * 2 + workerTimes[2] * 3 = 12 seconds.
Worker 3 reduces the height by 2, taking workerTimes[3] + workerTimes[3] * 2 = 12 seconds.
The number of seconds needed is max(9, 12, 12, 12) = 12 seconds.

Example 3:

Input: mountainHeight = 5, workerTimes = [1]

Output: 15

Explanation:

There is only one worker in this example, so the answer is workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 + workerTimes[0] * 4 + workerTimes[0] * 5 = 15.

 

Constraints:

1 <= mountainHeight <= 105
1 <= workerTimes.length <= 104
1 <= workerTimes[i] <= 106
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
33,904/80.2K
Acceptance Rate
42.3%
Topics
Staff
Array
Math
Binary Search
Greedy
Heap (Priority Queue)
Weekly Contest 416



*/




class Solution {
public:
    bool can(long long T, int H, vector<int>& w){
        long long total = 0;
        
        for(long long t : w){
            long long val = (2*T)/t;
            long long x = (sqrt(1 + 4*val) - 1) / 2;
            
            total += x;
            if(total >= H) return true;
        }
        
        return total >= H;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) { //tc=O(logE) using binarySearch
        
        long long l = 0, r = 1e18;
        long long ans = r;
        
        while(l <= r){
            long long mid = (l + r) / 2;
            
            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};