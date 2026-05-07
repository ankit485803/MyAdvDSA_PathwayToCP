

/*

7th May 2026 (Thursday)

Prob: Check if Array Is Sorted and Rotated

Example:
A = [3, 4, 5, 1, 2]

Brute Force Idea:
Rotate array from every index and check
whether any rotation becomes sorted.

TC = O(n^2)
SC = O(n)

*/

#include <iostream>
#include <vector>
using namespace std;


// Function to check if array is sorted
bool isSorted(vector<int>& arr) {

    int n = arr.size();

    for(int i = 0; i < n-1; i++) {

        if(arr[i] > arr[i+1]) {
            return false;
        }
    }

    return true;
}


// Brute Force Function
bool checkSortedAndRotatedBrute(vector<int>& arr) {

    int n = arr.size();

    // Try every rotation
    for(int k = 0; k < n; k++) {

        vector<int> rotatedArr(n);

        // Generate kth rotation
        for(int i = 0; i < n; i++) {

            rotatedArr[i] = arr[(i + k) % n];
        }

        // Check if this rotation is sorted
        if(isSorted(rotatedArr)) {
            return true;
        }
    }

    return false;
}


int main() {

    vector<int> arr = {3, 4, 5, 1, 2};

    if(checkSortedAndRotatedBrute(arr)) {
        cout << "Array is sorted and rotated";
    }
    else {
        cout << "Array is NOT sorted and rotated";
    }

    return 0;
}







#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkSortedAndRotatedBrute(vector<int>& arr) {
    int n = arr.size();

    for(int k = 0; k < n; k++) {
        vector<int> rotatedArr(n);

        // Generate kth rotation
        for(int i = 0; i < n; i++) {
            rotatedArr[i] = arr[(i + k) % n];
        }

        // Check if rotated array is sorted
        if(is_sorted(rotatedArr.begin(), rotatedArr.end())) {
            return true;
        }
    }

    return false;
}

int main() {

    vector<int> arr = {3, 4, 5, 1, 2};

    if(checkSortedAndRotatedBrute(arr)) {
        cout << "Array is sorted and rotated";
    }
    else {
        cout << "Array is NOT sorted and rotated";
    }

    return 0;
}