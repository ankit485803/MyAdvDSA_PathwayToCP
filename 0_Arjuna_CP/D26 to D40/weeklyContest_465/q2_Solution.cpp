



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minDifference(int n, int k) {
        int midInput = n;  // store the input midway in the function
        vector<int> bestSplit;
        int bestDiff = INT_MAX;

        function<void(int,int,vector<int>&)> dfs = [&](int num, int parts, vector<int>& cur) {
            if (parts == 1) {
                cur.push_back(num);  // last factor must be num
                int mx = *max_element(cur.begin(), cur.end());
                int mn = *min_element(cur.begin(), cur.end());
                int diff = mx - mn;
                if (diff < bestDiff) {
                    bestDiff = diff;
                    bestSplit = cur;
                }
                cur.pop_back();
                return;
            }

            // try divisors of num
            for (int d = 1; d * d <= num; d++) {
                if (num % d == 0) {
                    cur.push_back(d);
                    dfs(num / d, parts - 1, cur);
                    cur.pop_back();
                }
            }
        };

        vector<int> cur;
        dfs(n, k, cur);
        return bestSplit;
    }
};



int main() {
    Solution s;
    auto ans = s.minDifference(44, 3);
    for (int x : ans) cout << x << " ";
    return 0;
}



 // TC=O(n^0.5)^k-1  and SC=O(k)