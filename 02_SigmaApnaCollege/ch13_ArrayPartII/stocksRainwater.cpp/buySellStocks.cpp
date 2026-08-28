

/*

git commit -m "feat(sigmaApnaCollege): learn Kadane's Algo to find maxSubarrSum  (ch13 arrPart II)" 


27th Aug 2026 (Thursday)

same concepts used in
LeetCode probNo 121 https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

*/


#include <iostream>
using namespace std;
#include <climits>

void maxProfit(int *prices, int n) {  //tc=O(2*n) = O(n)
    int bestBuy[100000];  //oneLakh
    bestBuy[0] = INT_MAX;

    cout << bestBuy[0] << ",";

    for(int i=1; i<n; i++) {
        bestBuy[i] = min(bestBuy[i-1], prices[i - 1]);
        cout << bestBuy[i] << ",";
    }

    int maxProfit = 0;
    for(int i=0; i<n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }

    cout << "max profit = " << maxProfit << endl;
}


int main() {
    int prices[6] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(int);
    
    maxProfit(prices, n);

    return 0;
}
