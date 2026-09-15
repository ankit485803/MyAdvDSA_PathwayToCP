

/*

Insertion Sort: yah like playing cards game jaisa hai

idea: pick an elem from unsorted part and place it correctly into sorted part

Pick an element from UNSORTED part
             ↓
Place it at the correct position
             ↓
        SORTED part

        

        
*/


#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insertionSort(int arr[], int n) {   
    for(int i=1; i<n; i++) {

        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }

        arr[prev+1] = curr;
    }

    printArr(arr, n);
}


int main() {
    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);

    return 0;
}