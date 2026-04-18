

/*

arr is sorted given so we can apply BinarySearch

here we apply twoTimes BS - one for fistOcc, and second for lastOcc

tc=O(logN), sc=O(1)


*/

#include <iostream>
using namespace std;
#include <vector>

int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            ans = mid;
            high = mid - 1;  //leftSideSearch

        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}


//secondBS
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            ans = mid;
            low = mid + 1;  //right side search

        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}


int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 3, 4};
    int target = 2;

    // callFunct
    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);

    cout << "Fist Idx: " << first << endl;
    cout << "Last idx: " << last << endl;

    return 0;
}



/*
output

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ./codeRunFile.exe
Fist Idx: 1
Last idx: 3
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$




🟡 2. Logic check (important insight)
Your core idea:
    When arr[mid] == target:
        Move left for first occurrence ✅
        Move right for last occurrence ✅

This is exactly the correct trick. Many people miss this nuance
*/