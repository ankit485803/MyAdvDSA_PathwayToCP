
#include <iostream>
#include <vector>
#include <algorithm>


// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0; // Handle the empty case

        int maxProfit = 0;
        int bestBuy = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            // Update the maximum profit if the current price is greater than the best buy price
            if (prices[i] > bestBuy) {
                maxProfit = std::max(maxProfit, prices[i] - bestBuy);
            }
            // Update the best buy price if the current price is lower
            bestBuy = std::min(bestBuy, prices[i]);
        }
        
        return maxProfit;
    }
};

int main() {
    Solution solution;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << "Max Profit: " << solution.maxProfit(prices) << std::endl;
    return 0;
}
