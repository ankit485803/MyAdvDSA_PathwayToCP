How to create a folder (works in mobile too)
Method (what you should do):
Open your repo (like your link)
Tap Add file / + icon
Tap Create new file
In filename field, type like this:
folderName/file.cpp



#include <bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int>& arr, int target) {
    int index = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

    if (index == arr.size()) {
        return -1; // no element >= target
    }

    return index;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 3, 4};
    int target = 2;

    int index = findLowerBound(arr, target);

    if (index != -1 && arr[index] == target) {
        cout << "First occurrence index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}