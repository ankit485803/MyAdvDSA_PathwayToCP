

/*

1st Nov 2026 (Sunday)

src: D:\GitProj\MyAdvDSA_PathwayToCP\0_Arjuna_CP\HappyNewYr26\11_Nov\q1_minMoveToMakeEqArr.cpp

*/

class Solution {
public:
    int minMoves(vector<int>& nums) {  //tc=O(n), sc=O(1) using onePass
        int n = nums.size();

        int sum = 0;
        int minElem = INT_MAX;

        for(int i=0; i<n; i++) {
            sum += nums[i];
            minElem = min(minElem, nums[i]);  //reassign minElem
        }

        return sum - n*minElem;  //mainLogic
    }
};


//Approach-2 (Two Pass)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
  
        int sum    = accumulate(begin(nums), end(nums), 0);
        int min_el = *min_element(begin(nums), end(nums));

        return sum - n*min_el;
    }
};