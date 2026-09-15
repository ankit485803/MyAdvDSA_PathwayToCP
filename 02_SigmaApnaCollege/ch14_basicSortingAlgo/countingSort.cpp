

/*

Counting Sort: esko use karte hai min---max range low ho

idea: use a freq count of elem from min to max
this work in two steps

*/


#include <iostream>
using namespace std;
#include <climits>

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void countingSort(int arr[], int n) {   
    int freq[100000] = {0};  // Initialize frequency arr range
    int minVal = INT_MAX, maxVal = INT_MIN;

    for(int i=0; i<n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    //1st step -- O(n)
    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
    }

    //2nd step  -- O(range) = max - min
    int j = 0;
    for(int i = minVal; i <= maxVal; i++) {
        while(freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }

    printArr(arr, n);
}


int main() {
    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);

    countingSort(arr, n);

    return 0;
}