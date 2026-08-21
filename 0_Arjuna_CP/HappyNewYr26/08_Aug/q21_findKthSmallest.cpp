

/*

21st Aug 2026 (Friday)

qno 3116  https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/?envType=daily-question&envId=2026-08-21


*/

class Solution {
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        vector<pair<long long, int>> subsets;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long curLcm = 1;
            int bits = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    ++bits;
                    curLcm = lcm(curLcm, coins[i]);
                }
            }

            subsets.push_back({
                curLcm,
                bits & 1 ? 1 : -1
            });
        }

        auto count = [&](long long x) {
            long long total = 0;

            for (auto [v, sign] : subsets) {
                if (v > x)
                    continue;

                total += sign * (x / v);
            }

            return total;
        };

        long long left = 1;
        long long right = 1LL * k * (*min_element(coins.begin(),
                                                   coins.end()));

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};