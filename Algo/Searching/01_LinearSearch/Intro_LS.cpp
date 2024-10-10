
// Linear Search -- can apply on any type of array Sorted or Unsorted 
// time complex - Best = O(1) jab first mai ho , worst = O(n) when last mai ho

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

int LinearSeachFunct(vector<int> arr, int tar) {
    
    // brute forcely, we use ITERATIVE method
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == tar) {
            return i;
        } 
    }
    return -1;
}





int main() {

    vector<int> arr1 = {4, 6, 1, 3, 7};
    int tar1 = 7;

    cout << LinearSeachFunct(arr1, tar1) << endl;



    return 0;  //execute all code properly
}