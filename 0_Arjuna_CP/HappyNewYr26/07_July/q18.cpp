

qno 1979 https://leetcode.com/problems/find-greatest-common-divisor-of-array


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