


/*

19th Oct 2026 (Monday)


qno 2089  https://leetcode.com/problems/find-target-indices-after-sorting-array/?envType=daily-question&envId=2026-10-19

*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //step1: sort using STL  tc=O(n logN), sc=O(1)
        sort(nums.begin(), nums.end());

        //iterateEach idx
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};



//Approach-2 (Using one Count variable)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;  // Number of elements less than target
        for (int &num : nums) {
            if (num < target) 
                count++;
        }

        vector<int> result;
        for (int& num : nums) {
            if (num == target) {
                result.push_back(count);
                count++;
            }
        }
        return result;
    }
};


//Approach-2 (Using two Count variables)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int count1 = 0;  // Number of elements less than target
        int count2 = 0;  // Number of elements equal to target
        for (int &num : nums) {
            if (num < target) 
                count1++;
            else if(num == target)
                count2++;
        }

        vector<int> result;
        for(int i = count1; i < count1+count2; i++) {
            result.push_back(i);
        }
        return result;
    }
};