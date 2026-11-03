

/*

1st Nov 2026 (Sunday)

qno 453  https://leetcode.com/problems/minimum-moves-to-equal-array-elements/?envType=daily-question&envId=2026-11-01

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

//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool allEqual(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[0]) return false;
        }
        return true;
    }

    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;

        while (!allEqual(nums)) {
            // Find the max element's index
            int maxIdx = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] > nums[maxIdx]) maxIdx = i;
            }

            // Increment everything except the max
            for (int i = 0; i < n; i++) {
                if (i != maxIdx) nums[i]++;
            }
            moves++;
        }

        return moves;
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

//Approach-3 (One Pass)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
  
        int sum    = 0;
        int min_el = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            min_el = min(min_el, nums[i]);
        }

        return sum - n*min_el;
    }
};