




/*


5th Dec 2025 (Friday - day4 immersion AI 305)


qno 2500   https://leetcode.com/problems/delete-greatest-value-in-each-row/



2500. Delete Greatest Value in Each Row
Easy
Topics

Companies
Hint
You are given an m x n matrix grid consisting of positive integers.

Perform the following operation until grid becomes empty:

Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
Add the maximum of deleted elements to the answer.
Note that the number of columns decreases by one after each operation.

Return the answer after performing the operations described above.

 

Example 1:


Input: grid = [[1,2,4],[3,3,1]]
Output: 8
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 4 from the first row and 3 from the second row (notice that, there are two cells with value 3 and we can remove any of them). We add 4 to the answer.
- In the second operation, we remove 2 from the first row and 3 from the second row. We add 3 to the answer.
- In the third operation, we remove 1 from the first row and 1 from the second row. We add 1 to the answer.
The final answer = 4 + 3 + 1 = 8.
Example 2:


Input: grid = [[10]]
Output: 10
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 10 from the first row. We add 10 to the answer.
The final answer = 10.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 100


*/



#include <algorithm>
#include <climits>

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {  //tc=O(m * n), sc=O(1)
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;

        // Perform the operation until all columns are removed
        for (int j = 0; j < n; ++j) {
            int maxDeletedValue = INT_MIN;

            // Find the maxVal in each row and remove it
            for (int i = 0; i < m; ++i) {
                int rowMax = *max_element(grid[i].begin(), grid[i].end());
                maxDeletedValue = max(maxDeletedValue, rowMax);

                // Remove the max value from the row
                auto it = find(grid[i].begin(), grid[i].end(), rowMax);
                grid[i].erase(it);
            }

            total += maxDeletedValue;
        }

        return total;
    }
};







/*


qno  1475  https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/



1475. Final Prices With a Special Discount in a Shop
Easy
Topics

Companies
Hint
You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.

 

Example 1:

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
Example 2:

Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
Example 3:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]
 

Constraints:

1 <= prices.length <= 500
1 <= prices[i] <= 1000


*/



class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(prices);  // Start by assuming no discounts (same as prices)

        for (int i = 0; i < n; ++i) {  //t=O(n*n) nestedLoop twoPointerApproach
            // Find the next item with price <= prices[i]
            for (int j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) {
                    result[i] = prices[i] - prices[j];  // Apply discount
                    break;  
                }
            }
        }

        return result;
    }
};





/*





*/