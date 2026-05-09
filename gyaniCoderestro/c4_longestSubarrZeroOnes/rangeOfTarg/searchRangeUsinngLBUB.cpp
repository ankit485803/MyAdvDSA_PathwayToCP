

/*

9th May 2026 (Saturday)

prob:  First and last position of target element in sorted array, Range of target element in an array  | Upper Bound lowerB | Binary Search
Link: https://www.instagram.com/reel/DYFDkvsBnGj

given sorted arr = {1, 2, 2, 2, 3, 4, 5}
method1: bruteForce iterate eachELem tc=O(n), sc=O(1)

method2: using lowerB and upperB -- LB give fist idx of targ because LB works on idx >= targ, UB gives just greater than targ

Key Idea
lower_bound() → first index where value >= target
upper_bound() → first index where value > target
So:
first occurrence = lower_bound
last occurrence = upper_bound - 1

*/




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> searchRangeBrute(vector<int>& nums, int targ) {
    int first = -1, last = -1;

    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == targ) {
            if(first == -1) {
                first = i;
            }
            last = i;
        }
    }

    return {first, last};
}

pair<int, int> RangeOfTarget(const vector<int>& v, int t) {
    int lb = lower_bound(v.begin(), v.end(), t) - v.begin();
    if (lb == v.size() || v[lb] != t) return {-1, -1};
    int ub = upper_bound(v.begin(), v.end(), t) - v.begin() - 1;
    return {lb, ub};
}



int main() {
    vector<int> v = {1, 2, 4, 4, 4, 5, 6, 7};
    pair<int, int> res = RangeOfTarget(v, 4);
    cout << res.first << " " << res.second << endl;
    return 0;
}


git commit -m "feat(gyaniCoderestro): c4 searchRange using binarySearch c++ STL lowerBound and upperBound"