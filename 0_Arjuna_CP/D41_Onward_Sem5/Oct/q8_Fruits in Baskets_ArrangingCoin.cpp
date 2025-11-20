



/*  https://webwhiteboard.com/
this is link on which AI lab 307 class taken   https://miro.com/online-whiteboard/




15th Oct 2025 (Wednesday)

qno  3477   https://leetcode.com/problems/fruits-into-baskets-ii/description/




3477. Fruits Into Baskets II
Easy
Topics

Companies
Hint
You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.

From left to right, place the fruits according to these rules:

Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
Each basket can hold only one type of fruit.
If a fruit type cannot be placed in any basket, it remains unplaced.
Return the number of fruit types that remain unplaced after all possible allocations are made.

 

Example 1:
Input: fruits = [4,2,5], baskets = [3,5,4]
Output: 1
Explanation:
fruits[0] = 4 is placed in baskets[1] = 5.
fruits[1] = 2 is placed in baskets[0] = 3.
fruits[2] = 5 cannot be placed in baskets[2] = 4.
Since one fruit type remains unplaced, we return 1.

Example 2:
Input: fruits = [3,6,1], baskets = [6,4,7]
Output: 0
Explanation:
fruits[0] = 3 is placed in baskets[0] = 6.
fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
fruits[2] = 1 is placed in baskets[1] = 4.
Since all fruits are successfully placed, we return 0.

 

Constraints:
n == fruits.length == baskets.length
1 <= n <= 100
1 <= fruits[i], baskets[i] <= 1000


*/



class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        //solution using GreedyApproach
        
        //sort both arr  - O(n logN)
        sort(fruits.begin(), fruits.end());
        sort(baskets.begin(), baskets.end());


        //intilize idx
        int unplacedCount = 0, basketIdx = 0;

        //iterate eachFruits and try to place in basekt
        for(int i=0; i<fruits.size(); i++) {  //O(nN)
            while(basketIdx  < baskets.size()  &&  baskets[basketIdx]  <  fruits[i]) {
                basketIdx ++;  //skip basket too SMALL 
            }

            if(basketIdx < baskets.size()) {
                basketIdx ++;  // If we find a basket for the fruit, place it and move to the next basket
            } else {
                unplacedCount ++;  // If no basket can accommodate the current fruit, it remains unplaced
            }
        }

        return unplacedCount;  

    }
};




/*
qno 441   https://leetcode.com/problems/arranging-coins/description/


441. Arranging Coins
Easy
Topics

Companies
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

Example 1:


Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
Example 2:


Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
 

Constraints:

1 <= n <= 231 - 1


*/



class Solution {
public:
    int arrangeCoins(int n) {
        // Binary search approach TC=O(logN), SC=O(1)
        int left = 0, right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long coinsNeeded = (long long)mid * (mid + 1) / 2;
            
            if (coinsNeeded == n) {
                return mid;   
            } else if (coinsNeeded < n) {
                left = mid + 1;   
            } else {
                right = mid - 1;   
            }
        }
        
        return right;  // When the loop ends, `right` will be the largest valid `k`
    }
};
