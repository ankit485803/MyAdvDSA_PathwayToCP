

/*

3rd Nov 2026 (Tuesday)

qno 3736 https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/?envType=daily-question&envId=2026-11-03


*/

class Solution {
public:
    int minMoves(vector<int>& nums) { //tc=O(n), sc=O(1)
        int maxElem = *max_element(nums.begin(), nums.end());
        int moves = 0;

        for(int &num : nums) {
            moves += maxElem - num;
        }

        return moves;
    }
};




class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));
        
        int moves = 0;
        for (int& num : nums) {
            moves += maxEl - num;
        }
        /*
            Or you can do it like this : 
            moves = (maxEl - nums[0]) + (maxEl - nums[1]) + .....
            moves = (maxEl + maxEl + ...) - (nums[0] + nums[1] + ...)
            
            Final moves = n*maxEl - sum(nums);
        */
        
        return moves;
    }
};