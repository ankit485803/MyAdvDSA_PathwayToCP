

/*

15th Sep 2026 (Tuesday) BubbleSort

Idea: large elem come to end by swapping with adjacent 
esmai hm larElm ko compare karke right side ke wor move karte hai with swapping



*/

#include <iostream>
using namespace std;


void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {  
    int count = 0;  // count no of swap

    for(int i=0; i<n; i++) {  //tc=O(n^2), sc=O(1)
        for(int j=0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                count++;
            }
        }
    }
    printArr(arr, n);
    cout << "no of swaps by bubbleSortAlgo = " << count << endl;
}



int main() {
    //int arr[] = {5, 4, 1, 3, 2};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);


    return 0;  
}


void bubbleSort(int arr[], int n) {
    int swapCount = 0;
    int comparisonCount = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {

            comparisonCount++;  // every time we compare two elements

            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapCount++;
            }
        }
    }

    printArr(arr, n);

    cout << "No. of comparisons = " << comparisonCount << endl;
    cout << "No. of swaps = " << swapCount << endl;
}



//optimization in bubbleSort jab given arr is already sorted then hmko why to compare and swap directly return 
//if sortedArr given, to avoid unnecessary check and swap

void bubbleSort(int arr[], int n) {  
    for(int i=0; i<n; i++) {  
        //cout << "outerLoop";
        bool isSwap = false;
        
        for(int j=0; j < n-i-1; j++) {
            //cout << "innerLoop";
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            //arr is already sort jab koi swap nahi huwa directly return hamara controller
            break;;
        }
    }
    printArr(arr, n);
}
