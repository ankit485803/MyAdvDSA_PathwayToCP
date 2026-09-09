

/*

9th Sep 2026 (Wednesday)

qno 3871  https://leetcode.com/problems/count-commas-in-range-ii/description/?envType=daily-question&envId=2026-09-09.


*/


class Solution {
public:
    long long countCommas(long long n) {
        long long p = 1000, res = 0;
        while (p <= n) {
            res += n - p + 1;
            p *= 1000;
        }
        return res;
    }
};