


/*

27th Feb 2026 (Friday)

qno 3666   https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/?envType=daily-question&envId=2026-02-27


3666. Minimum Operations to Equalize Binary String
Hard
Topics

Companies
Hint
You are given a binary string s, and an integer k.

In one operation, you must choose exactly k different indices and flip each '0' to '1' and each '1' to '0'.

Return the minimum number of operations required to make all characters in the string equal to '1'. If it is not possible, return -1.

 

Example 1:

Input: s = "110", k = 1

Output: 1

Explanation:

There is one '0' in s.
Since k = 1, we can flip it directly in one operation.
Example 2:

Input: s = "0101", k = 3

Output: 2

Explanation:

One optimal set of operations choosing k = 3 indices in each operation is:

Operation 1: Flip indices [0, 1, 3]. s changes from "0101" to "1000".
Operation 2: Flip indices [1, 2, 3]. s changes from "1000" to "1111".
Thus, the minimum number of operations is 2.

Example 3:

Input: s = "101", k = 2

Output: -1

Explanation:

Since k = 2 and s has only one '0', it is impossible to flip exactly k indices to make all '1'. Hence, the answer is -1.

 

Constraints:

1 <= s.length <= 10​​​​​​​5
s[i] is either '0' or '1'.
1 <= k <= s.length
 
Discover more
Online Coding Contests
coding
Seen this question in a real interview before?
1/5
Yes
No
Accepted
22,992/56.3K
Acceptance Rate
40.9%
Topics
Senior Staff
Math
String
Breadth-First Search
Union-Find
Ordered Set
Biweekly Contest 164



*/



//Approach-1 - Brute Force
//T.C : O(n*k) ~ O(n^2)
//S.C : O(n)
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int startZeros = 0;
        for(char &ch : s) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0) {
            return 0; //no operations required
        }

        vector<int> operations(n+1, -1);
        //operations[z] = min operations required to reach state in which we have z 0s

        set<int> evenSet;
        set<int> oddSet;

        for(int count = 0; count <= n; count++) {
            if(count%2 == 0) {
                evenSet.insert(count);
            } else {
                oddSet.insert(count);
            }
        }

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;
        if(startZeros % 2 == 0) {
            evenSet.erase(startZeros);
        } else {
            oddSet.erase(startZeros);
        }

        while(!que.empty()) {
            int z = que.front();
            que.pop();
            
            int min_new_z = z + k - 2*min(k, z);
            int max_new_z = z + k - 2*max(0, k-n+z);

            set<int> &currSet = (min_new_z%2 == 0) ? evenSet : oddSet;

            auto it = currSet.lower_bound(min_new_z);

            while(it != currSet.end() && *it <= max_new_z) {
                int newZ = *it;

                if(operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) {
                        return operations[newZ];
                    }

                    que.push(newZ);
                }

                it = currSet.erase(it);
            }
        }

        return -1;
    }
};




//Approach-2 - Optimal - Skipping already visited states
//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();

        int startZeros = 0;
        for(char &ch : s) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0) {
            return 0; //no operations required
        }

        vector<int> operations(n+1, -1);
        //operations[z] = min operations required to reach state in which we have z 0s

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;

        while(!que.empty()) {
            int z = que.front();
            que.pop();

            int minF = max(0, k-n+z);
            int maxF = min(k, z);

            for(int f = minF; f <= maxF; f++) {
                int newZ = z + k - 2*f;

                if(operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) {
                        return operations[newZ];
                    }

                    que.push(newZ);
                }
            }
        }

        return -1;
    }
};
