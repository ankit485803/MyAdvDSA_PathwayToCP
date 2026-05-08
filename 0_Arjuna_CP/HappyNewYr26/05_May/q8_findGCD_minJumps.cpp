

/*

8th May 2026 (Friday)

qno 1979  https://leetcode.com/problems/find-greatest-common-divisor-of-array/

1979. Find Greatest Common Divisor of Array
Solved
Easy
Topics

Companies
Hint
Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 

Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
Example 2:

Input: nums = [7,5,6,8,3]
Output: 1
Explanation:
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
Example 3:

Input: nums = [3,3]
Output: 3
Explanation:
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.
 

Constraints:

2 <= nums.length <= 1000
1 <= nums[i] <= 1000
 
Seen this question in a real interview before?
1/6
Yes
No
Accepted
248,923/311.5K
Acceptance Rate
79.9%
Topics
Mid Level
Array
Math
Number Theory
Weekly Contest 255

*/


class Solution {
public:
    //make gcd helperFun using EuclideanAlgo
    int gcdEuclid(int a, int b) {  //O(log(min(a, b))) tc, sc-O(1)
        while(b != 0) {
            int rem = a % b;
            
            a = b;
            b = rem;  //remainder
        }

        return a;
    }

    int findGCD(vector<int>& nums) {
        int n = nums.size();
        //step1: sortArr and declare variable smallestNo, largestNo
        sort(nums.begin(), nums.end());  //using STL

        int smallNo = nums[0];  
        int largNo = nums[n-1];

        //step2: gcd calculation
        int ans = gcdEuclid(smallNo, largNo);
        return ans;
    }
};



class Solution {
public:
    // Euclidean Algorithm
    int gcdEuclid(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
        int smallNo = *min_element(nums.begin(), nums.end());
        int largNo  = *max_element(nums.begin(), nums.end());

        return gcdEuclid(smallNo, largNo);
    }
};



/*

qno 3629  https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/?envType=daily-question&envId=2026-05-08



*/



//Approach (Using BFS + Sieve)
//T.C : O(maxEL * loglog(maxEl))
//S.C : O(maxEl + n)
class Solution {
public:
    vector<bool> isPrime;
    
    void buildSieve(int maxEl) {
        //fill isPrime
        isPrime.resize(maxEl+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num*num <= maxEl; num++) {
            if(isPrime[num]) {

                for(int multiple = num*num; multiple <= maxEl; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; //element -> indices
        int maxEl = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }

        //build isPrime vector using Sieve
        buildSieve(maxEl); //O(maxEL * loglog(maxEl));

        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;
        //We visite each node only once - O(n)
        //O(n + maxEL * loglog(maxEl));
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                int i = que.front();
                que.pop();

                if(i == n-1) {
                    return steps;
                }

                if(i-1 >= 0 && !visited[i-1]) {
                    que.push(i-1);
                    visited[i-1] = true;
                }

                if(i+1 <= n-1 && !visited[i+1]) {
                    que.push(i+1);
                    visited[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]) {
                    if(!mp.contains(multiple)) {
                        continue;
                    }

                    for(int &j : mp[multiple]) {
                        if(!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }

            steps++;
        }

        return steps;
    }
};