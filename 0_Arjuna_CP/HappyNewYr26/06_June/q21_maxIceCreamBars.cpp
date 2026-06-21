

/*

21st June 2026 (Sunday - happyFather's Day)
already solved on 19th Jan 2026


1833. Maximum Ice Cream Bars
Solved
Medium
Topics

Companies
Hint
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

 

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 

Constraints:

costs.length == n
1 <= n <= 105
1 <= costs[i] <= 105
1 <= coins <= 108
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
259,690/341.1K
Acceptance Rate
76.1%
Topics
Senior
Array
Greedy
Sorting
Counting Sort
Weekly Contest 237

*/


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {  //tc=O( logN), sc=O(1)
        sort(costs.begin(), costs.end());
        int maxIceBar = 0;

        for(int i=0; i<costs.size(); i++) {
            if(coins >= costs[i]) {
                coins -= costs[i];
                maxIceBar++;
            } else {
                break;
            }
        }

        return maxIceBar;
    }
};


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) { //tc=O(n logN), sc=O(1)
        //step1: sort arr costs using countingSort as per req
        sort(costs.begin(), costs.end());

        int count = 0;   //no of ice creams bars

        //step2: iterate each idx to count
        for(int i=0; i < costs.size(); i++) {
            if(costs[i] <= coins) {
                count++;
                coins = coins - costs[i];   //subtract 
            } else {
                break;
            }
        }

        return count;
    }
};



class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {  //tc=O(n + maxCost), sc=O(maxCost)
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxCost + 1, 0);

        // Counting sort frequency array
        for (int cost : costs) {
            freq[cost]++;
        }

        int count = 0;

        // Buy cheapest bars first
        for (int cost = 1; cost <= maxCost && coins >= cost; cost++) {
            if (freq[cost] == 0) continue;

            int canBuy = min(freq[cost], coins / cost);

            count += canBuy;
            coins -= canBuy * cost;
        }

        return count;
    }
};