

// Selection sort: just behave opposite of bubble sort


// working -- start with Unsorted arr, step1: divide arr into 2 parts: sorted + unsorted and find smallest elem in unsorted 
// step2: swap smallest elem with first elem of unsorted arr, repeat (n-1) times


#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {   // O(n) times
        int smallestIndex = i;
        bool isSwap = false;  // Reset flag for each outer loop iteration

        for (int j = i + 1; j < n; j++) {  // O(n^2) times


            if (arr[j] < arr[smallestIndex]) {  //if need to print in DESCENDING order, then sign to >
                smallestIndex = j;
                isSwap = true;
            }
        }

        // Only swap if a smaller element was found
        if (isSwap) {
            swap(arr[i], arr[smallestIndex]);
        }
    }
}



//printing funct
int printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}




int main() {
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}



// time compl of bubble sort = O(n^*n) can represent as: O(n^2)  this happen in all case (best, avg, worst)