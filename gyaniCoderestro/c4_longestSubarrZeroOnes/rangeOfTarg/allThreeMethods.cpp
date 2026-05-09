#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// ================= BRUTE FORCE =================
// TC = O(n)
// SC = O(1)

vector<int> searchRangeBrute(vector<int>& nums, int targ) {

    int first = -1, last = -1;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] == targ) {

            if(first == -1) {
                first = i;
            }

            last = i;
        }
    }

    return {first, last};
}




// ================= BinarySearch STL USING lower_bound & upper_bound =================
// TC = O(log n)
// SC = O(1)

pair<int, int> RangeOfTarget(const vector<int>& v, int t) {

    int lb = lower_bound(v.begin(), v.end(), t) - v.begin();

    // target not found
    if(lb == v.size() || v[lb] != t) {
        return {-1, -1};
    }

    int ub = upper_bound(v.begin(), v.end(), t) - v.begin() - 1;

    return {lb, ub};
}




// ================= MANUAL BINARY SEARCH =================
// TC = O(log n)
// SC = O(1)

int findFirst(vector<int>& nums, int target) {

    int st = 0, end = nums.size() - 1;
    int first = -1;

    while(st <= end) {

        int mid = st + (end - st) / 2;

        if(nums[mid] == target) {

            first = mid;   // possible answer
            end = mid - 1; // move left

        }
        else if(nums[mid] < target) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return first;
}



int findLast(vector<int>& nums, int target) {

    int st = 0, end = nums.size() - 1;
    int last = -1;

    while(st <= end) {

        int mid = st + (end - st) / 2;

        if(nums[mid] == target) {

            last = mid;    // possible answer
            st = mid + 1;  // move right

        }
        else if(nums[mid] < target) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return last;
}



vector<int> searchRangeBinary(vector<int>& nums, int target) {

    int first = findFirst(nums, target);
    int last = findLast(nums, target);

    return {first, last};
}




int main() {

    vector<int> v = {1, 2, 4, 4, 4, 5, 6, 7};
    int target = 4;



    // Method 1 : Brute Force
    vector<int> bruteAns = searchRangeBrute(v, target);

    cout << "Brute Force Output: ";
    cout << bruteAns[0] << " " << bruteAns[1] << endl;



    // Method 2 : lower_bound & upper_bound
    pair<int, int> boundAns = RangeOfTarget(v, target);

    cout << "LB & UB Output: ";
    cout << boundAns.first << " " << boundAns.second << endl;



    // Method 3 : Manual Binary Search
    vector<int> binaryAns = searchRangeBinary(v, target);

    cout << "Manual Binary Search Output: ";
    cout << binaryAns[0] << " " << binaryAns[1] << endl;


    return 0;
}