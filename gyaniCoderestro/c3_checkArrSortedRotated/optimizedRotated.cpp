

/*
Prob: Check if Array Is Sorted and Rotated

Example:
A = [3, 4, 5, 1, 2]

--------------------------------------------------
Method 1: Brute Force

Rotate array from every index and check
whether any rotation becomes sorted.

TC = O(n^2)
SC = O(n)

--------------------------------------------------
Method 2: Optimized Observation

Property:
Every sorted & rotated array follows
a circular sorted pattern.
There will be only ONE position where:  currElem > nextElem

Example:
[3, 4, 5, 1, 2]

Only:
5 > 1

So if count of such break points <= 1,
then array is sorted and rotated.

TC = O(n)
SC = O(1)

*/

#include <iostream>
#include <vector>
using namespace std;


// --------------------------------------------------
// Helper Function
// Check if array is sorted
// --------------------------------------------------

bool isSorted(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; i++) {

        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}


// --------------------------------------------------
// Method 1 : Brute Force
// --------------------------------------------------

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


// --------------------------------------------------
// Method 2 : Optimized
// --------------------------------------------------

bool checkSortedAndRotatedOptimal(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++) {
        // Count break points
        if(arr[i] > arr[(i + 1) % n]) {
            count++;
        }
    }
    // Sorted & rotated array
    // can have at most 1 break point
    return count <= 1;
}



int main() {
    vector<int> arr = {3, 4, 5, 1, 2};
    // Brute Force
    if(checkSortedAndRotatedBrute(arr)) {
        cout << "Brute Force: Array is sorted and rotated\n";
    }
    else {
        cout << "Brute Force: Array is NOT sorted and rotated\n";
    }

    // Optimized
    if(checkSortedAndRotatedOptimal(arr)) {
        cout << "Optimized: Array is sorted and rotated\n";
    }
    else {
        cout << "Optimized: Array is NOT sorted and rotated\n";
    }

    return 0;
}