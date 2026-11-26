
git commit -m "feat(sigmaApnaCollege): complete all video Lec of this chap (ch20_Recursion)" 
/*

4th Nov 2026 (Tuesday)

Question 1 : Write a recursive function to perform Binary Search. 
Input : arr[ ] = {1, 2, 3, 4, 5, 6, 7}, n = 7, key = 5 
Output : 4 (index of key) 
*Use the starting index & ending index logic used in rotated, sorted array Qs.


25th Nov 2026 (Wednesday - after Diwali Chhath Puja)


*/


#include <iostream>
using namespace std;

int binarySearch(int arr[], int st, int end, int key) {  //tc=O(logN) = sc due recursive call STACK

    // Base case
    if (st > end) {
        return -1;
    }

    int mid = st + (end - st) / 2;

    // Key found
    if (arr[mid] == key) {
        return mid;
    }

    // Search in right half
    if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, end, key);
    }

    // Search in left half
    else {
        return binarySearch(arr, st, mid - 1, key);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int key = 5;

    cout << binarySearch(arr, 0, n - 1, key) << endl;

    return 0;
}