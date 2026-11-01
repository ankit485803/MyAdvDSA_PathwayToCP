

/*

check given arr is sorted or not

approach1: using loop tc=O(n), sc=O(1)

approach2: using recursion tc=O(n), sc=O(n) due to recursive stackDS call which form recessionTree


*/


#include <iostream>
using namespace std;

bool isSortedUsingLoop(int arr[], int n) {  // n is arr size here
    for(int i=0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}


//using recursion
bool isSorted(int arr[], int n, int i) {
    //threeWork
    //work1: baseCase 
    if(i == n-1) {
        return true;  //hm last idx pe
    }

    if(arr[i] > arr[i+1]) {  //work2: hmara Ankit ka kaam
        return false;
    }

    return isSorted(arr, n, i+1);  //work3: innerFun kya karega
}


int main() {
    int arr1[5] = {1, 2, 3, 4, 5};   //sorted 1
    int n = sizeof(arr1) / sizeof(int);
    int arr2[5] = {1, 2, 4, 3, 5};  //unsorted 0

    //cout <<  isSortedUsingLoop(arr1, n) << endl;

    cout << isSorted(arr1, 5, 0);

    return 0;
}





bool isSortedUsingRecursion(int arr[], int n) {
    // Base case
    if(n == 1) {
        return true;
    }

    // Check adjacent elements
    if(arr[n-2] > arr[n-1]) {
        return false;
    }

    // Recursive call
    return isSortedUsingRecursion(arr, n-1);
}
