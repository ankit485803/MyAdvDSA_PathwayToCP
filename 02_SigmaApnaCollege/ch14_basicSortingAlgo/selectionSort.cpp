

/*

Selection sort: is just opposite of bubbleSort

jaise hm bubbleSort mai largElem ko right side whereas selectionSort mai hm smallestElem ko push karte hai left first side mai
yah two parts mai work karta hai: sorted, unsorted 

Your code
This part is the heart of Selection Sort:
int minIdx = i;

for(int j = i+1; j < n; j++) {
    if(arr[j] < arr[minIdx]) {
        minIdx = j;
    }
}

swap(arr[i], arr[minIdx]);




*/

#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void selectionSort(int arr[], int n) {  //tc=O(n^2), sc=O(1)
    for(int i=0; i<n-1; i++) {

        int minIdx = i;
        //loop for min
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    printArr(arr, n);
}


int main() {
    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);

    selectionSort(arr, n);

    return 0;
}