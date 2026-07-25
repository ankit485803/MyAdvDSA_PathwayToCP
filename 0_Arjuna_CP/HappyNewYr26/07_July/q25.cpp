

qno 3536 https://leetcode.com/problems/maximum-product-of-two-digits

class Solution {
public:
    int maxProduct(int n) {
        int maxDigit = 0;
        int secondMaxDigit = 0;

        while(n > 0) {
            int r = n%10;
            if(maxDigit < r) {
                secondMaxDigit = maxDigit;
                maxDigit = r;
            } else if(secondMaxDigit < r) {
                secondMaxDigit = r;
            }
            n /= 10;
        }

        return maxDigit * secondMaxDigit;
    }
};