

#include <iostream>
using namespace std;
#include <vector>


/*
15th July 2025 (Tuesday) print subsets II which contain duplicate element

qno 90  https://leetcode.com/problems/subsets-ii/description/

yah socho ye aate h kyo duplicate elem
pahle sort the arr and then calculate the subset; very imp to exclude the elements


*/


class Solution {
public:

    void getAllSubsets(vector<int>& nums, vector<int> ans, int i, vector<vector<int>> & allSubsets) {
        //baseCase
        if(i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }


        //including wala step
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans i + 1, allSubsets);

        //backTracking
        ans.pop_back();  //to remove 

        //exclude wala very imp step for subet 2 prob duplicate
        int idx = i+1;
        while(idx < n  && nums[idx] == nums[idx-1]) {  //jab equal ho to skip karo
            idx ++;

        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());   // TC = O(nlogn)
        vector<vector<int>> allSubsets;
        vector<int> ans;

        return allSubsets;
        
    }
};


// TC  O(nlogn + 2^n * n)