

/*

26th June 2026 (Friday)

qno  3739  https://leetcode.com/problems/count-subarrays-with-majority-element-ii/?envType=daily-question&envId=2026-06-26

same yesterday prob no 3737 
only diff

Constraints:

1 <= nums.length <= 10​​​​​​​5
1 <= nums[i] <= 10​​​​​​​9
1 <= target <= 109


*/

//Approach-1 (Brute Force) - PART I Accepted, PART II TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int count = 0;

            for (int j = i; j < n; ++j) {
                count += (nums[j] == target ? 1 : -1);

                if (count > 0) {
                    result++;
                }

            }
        }

        return result;
    }
};



//Approach-2 (Brute Force Prefix Sum) - PART I Accepted, PART II TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }

        for(int i = 1; i < n; i++) {
            nums[i] += nums[i-1];
        }

        long long ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                int sum = nums[r] - ((l > 0) ? nums[l-1] : 0);

                if(sum > 0)
                    ans++;
            }
        }

        return ans;

    }
};



//Approach-3 (Optimal Using Map) PART I Accepted, PART II TLE (Instead of map you can use an array of size 2*n+1 as well because we can have cumulaive sum from -n to +n)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        //Instead of map you can use an array of size 2*n+1 as well because we can have cumulaive sum from -n to +n)
        unordered_map<int,int> mp;   // mp[cumSum] = frequency of how many times cumSum has occurred
        
        int currSum = 0;
        
        mp[0] = 1; //we have seen cumSum = 0 in the beginning once

        long long validLeftPoints = 0;

        long long result = 0;

        for (int x : nums) {
            if (x == target) {
                validLeftPoints += mp[currSum];
                currSum++;
            } else {
                currSum--;
                validLeftPoints -= mp[currSum];
            }

            mp[currSum]++;

            result += validLeftPoints;
        }

        return result;
    }
};