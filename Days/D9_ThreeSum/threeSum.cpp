
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <algorithm>


// qno 15  https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector <int>> ans;

        set<vector<int>> s;  //set<uniqueTriplets>

        for(int i=0; i<n; i++) { //  O(n^3)
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {

                    if(nums[i] + nums[j] + nums[k] == 0) {  //found triplate, trick using unord_set 
                        vector<int> trip = {nums[i], nums[j], nums[k] };
                        sort(trip.begin(), trip.end());

                        if(s.find(trip) == s.end()) {  //O(log(unique triplets))
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }

        return ans; 
    }
};


//using BruteForcaApp-- TC= o(n^3 * log(uniqueTrip))
// SC = O(uniqueTrip * 2)  -- This solution gave the time limit exceed (TLE) error 



//method2: Hashing -- TC=O(n^2 * log(uniqueTriplets)), SC = O(uniqueTriplets + n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
      
        set<vector<int>> uniqueTriplets;   

        for(int i=0; i<n; i++) {
            int tar = -nums[i];
            set<int> s;

            for(int j=i+1; j<n; j++) {
                int third = tar - nums[j];

                if(s.find(third) != s.end()) {
                    vector<int> trip = {nums[i], nums[j], third};
                    sort(trip.begin(), trip.end());
                    uniqueTriplets.insert(trip);
                }

                s.insert(nums[j]);
            }

        }


        vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }
};



//method3: twoPointer approach-- 


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;  

        sort(nums.begin(), nums.end());  // Sorting step - O(n log n)

        for (int i = 0; i < n; i++) {
            // Skip duplicate elements for the first element in the triplet
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;

            while (j < k) {  // Two-pointer approach - O(n^2)
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;  // Move left pointer to the right to increase the sum
                } else if (sum > 0) {
                    k--;  // Move right pointer to the left to decrease the sum
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate elements for the second and third elements
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;  // Make sure to return the result at the end
    }
};


//method3: twoPointer app -- TC=O(nlogn + n^2), SC=O(uniqueTriplets)