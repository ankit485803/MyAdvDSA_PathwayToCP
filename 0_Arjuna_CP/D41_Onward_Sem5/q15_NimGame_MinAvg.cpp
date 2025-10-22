

/*

22nd Oct 2025 (Wednesday)


A Heap is a complete binary tree data structure that satisfies the heap property: for every node, the value of its children is greater than or equal to its own value. 
Heaps are usually used to implement priority queues, where the smallest (or largest) element is always at the root of the tree.



qno 292  https://leetcode.com/problems/nim-game/

292. Nim Game
Easy
Topics

Companies
Hint
You are playing the following Nim Game with your friend:

Initially, there is a heap of stones on the table.
You and your friend will alternate taking turns, and you go first.
On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
The one who removes the last stone is the winner.
Given n, the number of stones in the heap, return true if you can win the game assuming both you and your friend play optimally, otherwise return false.

 

Example 1:

Input: n = 4
Output: false
Explanation: These are the possible outcomes:
1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
In all outcomes, your friend wins.
Example 2:

Input: n = 1
Output: true
Example 3:

Input: n = 2
Output: true
 

Constraints:

1 <= n <= 231 - 1



*/


class Solution {
public:
    bool canWinNim(int n) {  //TC=O(1) = SC

        //Let's assume: firstPlayer-Ankit and SecondP - Samarth Mishra
        
        // If n % 4 == 0, it means it's a losing position for the first player 
        return n % 4  != 0;
    }
};



/*

qno 2465  https://leetcode.com/problems/number-of-distinct-averages/description/


We can use a set to store the distinct averages and then simply return the size of the set at the end.



2465. Number of Distinct Averages
Attempted
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums of even length.

As long as nums is not empty, you must repetitively:

Find the minimum number in nums and remove it.
Find the maximum number in nums and remove it.
Calculate the average of the two removed numbers.
The average of two numbers a and b is (a + b) / 2.

For example, the average of 2 and 3 is (2 + 3) / 2 = 2.5.
Return the number of distinct averages calculated using the above process.

Note that when there is a tie for a minimum or maximum number, any can be removed.

 

Example 1:

Input: nums = [4,1,4,0,3,5]
Output: 2
Explanation:
1. Remove 0 and 5, and the average is (0 + 5) / 2 = 2.5. Now, nums = [4,1,4,3].
2. Remove 1 and 4. The average is (1 + 4) / 2 = 2.5, and nums = [4,3].
3. Remove 3 and 4, and the average is (3 + 4) / 2 = 3.5.
Since there are 2 distinct numbers among 2.5, 2.5, and 3.5, we return 2.
Example 2:

Input: nums = [1,100]
Output: 1
Explanation:
There is only one average to be calculated after removing 1 and 100, so we return 1.
 

Constraints:

2 <= nums.length <= 100
nums.length is even.
0 <= nums[i] <= 100

*/

class Solution {
public:
    int distinctAverages(vector<int>& nums) {  //TC=O(n logN), SC=O(n)

        set<double> averages;   //Set to store distinct averages
        sort(nums.begin(), nums.end());
        
        while(! nums.empty()) {
            
            //calculate minNo, maxNo, avg on each iterate and thne remove it
            int minN =  nums.front();
            int maxN = nums.back();
            double avg = (minN + maxN) / 2.0;

            //Add the average to the set (automatically handles uniqueness)
            averages.insert(avg);
            
            // Remove the min and max fromArr
            nums.erase(nums.begin());  //removeFirstElem - min
            nums.pop_back(); //Remove the last element (max)

        
        }

        // Return the no of distinct averages
        return averages.size();
    }
};


/*


qno 3194  https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/


3194. Minimum Average of Smallest and Largest Elements
Easy
Topics

Companies
Hint
You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.

You repeat the following procedure n / 2 times:

Remove the smallest element, minElement, and the largest element maxElement, from nums.
Add (minElement + maxElement) / 2 to averages.
Return the minimum element in averages.

 

Example 1:

Input: nums = [7,8,3,4,15,13,4,1]

Output: 5.5

Explanation:

step	nums	averages
0	[7,8,3,4,15,13,4,1]	[]
1	[7,8,3,4,13,4]	[8]
2	[7,8,4,4]	[8,8]
3	[7,4]	[8,8,6]
4	[]	[8,8,6,5.5]
The smallest element of averages, 5.5, is returned.
Example 2:

Input: nums = [1,9,8,3,10,5]

Output: 5.5

Explanation:

step	nums	averages
0	[1,9,8,3,10,5]	[]
1	[9,8,3,5]	[5.5]
2	[8,5]	[5.5,6]
3	[]	[5.5,6,6.5]
Example 3:

Input: nums = [1,2,3,7,8,9]

Output: 5.0

Explanation:

step	nums	averages
0	[1,2,3,7,8,9]	[]
1	[2,3,7,8]	[5]
2	[3,7]	[5,5]
3	[]	[5,5,5]
 

Constraints:

2 <= n == nums.length <= 50
n is even.
1 <= nums[i] <= 50

*/


 

class Solution {
public:
    double minimumAverage(vector<int>& nums) {  //tc=O(n logN), sc=O(n)
     
        sort(nums.begin(), nums.end());
        
        vector<double> averages; // Store the averages
        
        // Repeat n / 2 times
        int n = nums.size();


        for (int i = 0; i < n / 2; ++i) {
            int minElem = nums[i];        // SmallestElem
            int maxElem = nums[n - 1 - i]; // LargElem
            

            // Calculate the average and add it to the averages vector
            double avg = (minElem + maxElem) / 2.0;
            averages.push_back(avg);
        }
         


        return *min_element(averages.begin(), averages.end());
    }
};
