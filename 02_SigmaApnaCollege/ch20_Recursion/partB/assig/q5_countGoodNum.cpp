

/*

leetcode probNo 1922  https://leetcode.com/problems/count-good-numbers/description/

Mathematics + Binary Exponentiation (Fast Power)


*/


class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;

    ll power(ll x, ll n) {
        ll ans = 1;

        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            n /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {  //tc=O(logN), sc=O(1) using maths & binaryExpentation
        ll even = (n + 1) / 2;
        ll odd = n / 2;

        ll a = power(5, even);
        ll b = power(4, odd);

        return (a * b) % MOD;
    }
};