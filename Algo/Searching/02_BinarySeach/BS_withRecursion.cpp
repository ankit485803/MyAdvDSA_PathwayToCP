

// apply BS using Recursion

#include <iostream>
#include <vector>
using namespace std;

// time complex = O(log(n)), space = O(1)  using Recursion

int recurBinarySearch(vector<int> arr, int tar, int st, int end) {
    if(st <= end) {
        int mid = st + (end - st)/2;

        if(tar > arr[mid]) {   //2nd half
            return recurBinarySearch(arr, tar, mid+1, end);
        } else if(tar < arr[mid]) {
            return recurBinarySearch(arr, tar, st, mid-1);
        } else {
            return mid;
        }
    }

    return -1;  //when not found
}



int main() {
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; //odd size wala arr
    int tar1 = 4;

    cout << recurBinarySearch(arr1, 4, -1, 12) << endl;


    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};  //even
    int tar2 = 0;


    return 0;
}
 