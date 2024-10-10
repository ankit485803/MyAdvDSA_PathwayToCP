
// learn the BS (apply only for sorted arr - ascending or descending  called MONOTONIC matlab nahi increase ya decreasing) concept
// Linear Search = O(n) but Binary search = O(log(n))

// 2 searching algo - Linear or Binary
// Divide & conquer approach

// step1: find the mid, mid = (start + end) // 2
// step2: tar > arr[mid]  -- 2nd half    and tar < arr[mid] -- 1st half
// step3: tar == arr[mid], ans: mid


#include <iostream>
#include <vector>
using namespace std;

//funct BS using ITERATIVE code -- time complex = O(log(n)) = space

int binarySearch(vector<int> arr, int tar) {
    int st=0, end=arr.size()-1;

    while(st <= end) {
        //int mid = (st + end) /2;   //overflow when big index val
        int mid = st + (end - st) / 2;

        if(tar > arr[mid]) {
            st = mid + 1;
        } else if(tar < arr[mid]) {
            end = mid -1;
        } else {
            return mid;
        }
    }

    return -1;   //when not present tar
    
}


int main() {
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; //odd size wala arr
    int tar1 = 4;

    //cout << binarySearch(arr1, tar1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};  //even
    int tar2 = 0;

    cout << binarySearch(arr2, tar2) << endl;


    return 0;
}


// Binary search mai sabse jayada imp hai to identify the SEARCH-SPACE kon sa hai

