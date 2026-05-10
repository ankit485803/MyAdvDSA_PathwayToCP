

/*  probNo 3928  https://leetcode.com/problems/minimum-cost-to-buy-apples-ii/

https://leetcode.com/contest/weekly-contest-501/problems/minimum-cost-to-buy-apples-ii/

3928. Minimum Cost to Buy Apples II
Hard
premium lock icon
Companies
You are given an integer n and an integer array prices of length n, where prices[i] is the price of apples at shop i.

You are also given a 2D integer array roads, where roads[i] = [ui, vi, costi, taxi] represents a bidirectional road:

ui and vi are the shops connected by the road.
costi is the cost to travel the road without carrying apples.
taxi is the multiplier applied to costi when traveling with apples.
For each shop i, you can either:

Buy apples locally at shop i for prices[i].
Travel empty to any shop j using any number of roads, buy apples for prices[j], and return to shop i while carrying apples, paying cost * tax on each road used for the return trip.
The forward path, where you travel empty, and the return path may be different.

Return an integer array ans of length n, where ans[i] is the minimum total cost to buy apples starting from shop i.

 

Example 1:

Input: n = 2, prices = [8,3], roads = [[0,1,1,2]]

Output: [6,3]

Explanation:



Shop i	prices[i]	Shop j	prices[j]	costi	taxi	Travel cost	Return cost	Total	Minimum
0	8	1	3	1	2	1	1 * 2 = 2	1 + 2 + 3 = 6	min(8, 6) = 6
1	3	0	8	1	2	1	1 * 2 = 2	1 + 2 + 8 = 11	min(3, 11) = 3
Thus, the answer is [6, 3].

Example 2:

Input: n = 3, prices = [9,4,6], roads = [[0,1,1,3],[1,2,4,2]]

Output: [8,4,6]

Explanation:

​​​​​​​

Shop i	prices[i]	Shop j	prices[j]	costi	taxi	Travel cost	Return cost	Total	Minimum
0	9	1	4	1	3	1	1 * 3 = 3	1 + 3 + 4 = 8	min(9, 8) = 8
1	4	2	6	4	2	4	4 * 2 = 8	4 + 8 + 6 = 18	min(4, 18) = 4
2	6	1	4	4	2	4	4 * 2 = 8	4 + 8 + 4 = 16	min(6, 16) = 6
Thus, the answer is [8, 4, 6].

Example 3:

Input: n = 3, prices = [10,11,1], roads = [[0,2,1,3],[1,2,3,4],[0,1,5,2]]

Output: [5,11,1]

Explanation:

​​​​​​​​​​​​​​

Shop i	prices[i]	Shop j	prices[j]	costi	taxi	Travel cost	Return cost	Total	Minimum
0	10	2	1	1	3	1	1 * 3 = 3	1 + 3 + 1 = 5	min(10, 5) = 5
1	11	2	1	3	4	3	3 * 4 = 12	3 + 12 + 1 = 16	min(11, 16) = 11
2	1	0	10	1	3	1	1 * 3 = 3	1 + 3 + 10 = 14	min(1, 14) = 1
Thus, the answer is [5, 11, 1].

 

Constraints:

1 <= n <= 1000
prices.length == n
1 <= prices[i] <= 109
0 <= roads.length <= min(n × (n - 1) / 2, 2000)
roads[i] = [ui, vi, costi, taxi]
0 <= ui, vi <= n - 1
ui != vi
1 <= costi <= 109
​​​​​​​1 <= tax​​​​​​​i <= 100​​​​​​​
There are no repeated edges.
 

Seen this question in a real interview before?
1/6
Yes
No
Accepted
3,003/10.1K
Acceptance Rate
29.6%
Topics
Weekly Contest 501
*/