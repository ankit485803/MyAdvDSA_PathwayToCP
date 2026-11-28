

/*

using Linear search tc=O(n)
but using divide and conquer with modified BinarySearch tc=O(logN), sc=O(1)

*/

#include <iostream>
#include <vector>
using namespace std;


int search(int arr[], int si, int ei, int tar) {
    if(si > ei) {
        return -1;
    }

    int mid = si + (ei - si)/2;
    if(arr[mid] == tar) {
        return mid;
    }

    if(arr[si] <= arr[mid]) {  //line l1 case hoga
        if(arr[si] <= tar && tar <= arr[mid]) {
            //left 
            return search(arr, si, mid-1, tar);
        } else {
            //right half
            return search(arr, mid+1, ei, tar);
        }

    } else {  //line L2
        if(arr[mid] <= tar && tar <= arr[ei]) {
            //right half
            return search(arr, mid+1, ei, tar);
        } else {
            //left half
            return search(arr, si, mid-1, tar);
        }

    }
}


int main() {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    int ans = search(arr, 0, n-1, 0);  //find 0 idx in arr, ans = 4
    cout << "idx = " << ans << endl;

    return 0;
}