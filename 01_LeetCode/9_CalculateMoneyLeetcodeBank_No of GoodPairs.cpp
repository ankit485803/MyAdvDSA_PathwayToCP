



/*

1st Oct 2025 (Wednesday - 9th Puja Navratri Maa Durja ji)


qno 1512     https://leetcode.com/problems/number-of-good-pairs/


Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

*/



class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int count = 0;  //  Variable to store the count of good pairs

        //iterate all the  pair (i, j) where i<j
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {   //only check pairs where i < j
                //check given condition in ques
                if(nums[i] == nums[j]) {
                    count ++;
                }
            }
        }

        return count;  //final total no of paris possible
    }
};


//TC=O(n^2) due to nested loop and optimized using HASH MAP which give O(n) 
//sc = O(1)









/*

qno 1716   https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/




Calculate Money in Leetcode Bank
Easy
Topics
premium lock icon
Companies
Hint
Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.



Example 1:
Input: n = 4
Output: 10
Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.




Example 2:
Input: n = 10
Output: 37
Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.




Example 3:
Input: n = 20
Output: 96
Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
 

Constraints:

1 <= n <= 1000





*/



class Solution {
public:
    int totalMoney(int n) {
        
        int totalA = 0;   //amount total
        int weekStart = 1;  //  Amount deposited on Monday of the current week
        int day = 0;

        //Brute force apporach - OuterLop for each week and inner loop for each day in week or less
        while(day < n) {
            int current = weekStart;
            for(int i=0; i<7  &&  day < n; ++i) {
                totalA += current;
                current ++;
                day ++;
            }

            weekStart ++;  //Next week starts with +1

        }

        return totalA;
    }
};

// TC = O(n)  One operation per day up to n days
// sc = (1) Uses only a fixed number of variables