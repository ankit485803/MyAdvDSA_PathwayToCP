

/*

4th Nov 2026 (Wednesday)

qno 3505   https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/description/?envType=daily-question&envId=2026-11-04

*/

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<int> vals(nums);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();

        vector<int> rk(n);
        for (int i = 0; i < n; i++)
            rk[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;

        vector<long long> bc(m + 1, 0), bs(m + 1, 0);
        vector<int> cntAt(m + 1, 0);
        auto upd = [&](int i, int c, long long v) {
            for (; i <= m; i += i & -i) { bc[i] += c; bs[i] += v; }
        };
        int LOG = 0;
        while ((1 << (LOG + 1)) <= m) LOG++;
        int need = (x + 1) / 2;
        long long tot = 0;

        for (int i = 0; i < x; i++) {
            upd(rk[i], 1, nums[i]); cntAt[rk[i]]++; tot += nums[i];
        }

        vector<long long> cost(n - x + 1);
        for (int s = 0; s + x <= n; s++) {
            int pos = 0, kk = need;
            long long accC = 0, accS = 0;
            for (int b = LOG; b >= 0; b--) {
                int np = pos + (1 << b);
                if (np <= m && bc[np] < kk) {
                    pos = np; kk -= bc[np]; accC += bc[np]; accS += bs[np];
                }
            }
            int p = pos + 1;
            long long med = vals[p - 1];
            long long cntLE = accC + cntAt[p];
            long long sumLE = accS + cntAt[p] * med;
            cost[s] = med * cntLE - sumLE + (tot - sumLE) - med * (x - cntLE);

            upd(rk[s], -1, -nums[s]); cntAt[rk[s]]--; tot -= nums[s];
            if (s + x < n) {
                upd(rk[s + x], 1, nums[s + x]); cntAt[rk[s + x]]++; tot += nums[s + x];
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> prev(n + 1, 0), cur(n + 1);
        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), INF);
            for (int i = x; i <= n; i++) {
                long long best = cur[i - 1];
                if (prev[i - x] < INF) best = min(best, prev[i - x] + cost[i - x]);
                cur[i] = best;
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};