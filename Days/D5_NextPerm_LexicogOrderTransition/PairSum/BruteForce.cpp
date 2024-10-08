#include <iostream>
#include <vector>
using namespace std;


// Return pair in SORTED arr with target sum
// Brute force - O(n^2)
vector <int> pariSum(vector <int> nums, int target) {
    vector <int> ans;
    int n = nums.size();

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 17;

    vector<int> ans = pariSum(nums, target);
    cout << ans[0] << " , " << ans[1] << endl;
    return 0;
}








