
/* Inseration sort: yah idea aya hai playing card, jowaa se tas khelan ankit okkk

working = divid arr into sort and Unsort, then campare with previous, swaps 
arr[prev] , arr[prev+1]

*/


#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>



void inserationSort(int arr[], int n) { 
    for(int i=1; i<n; i++) {   //run O(n) times
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr) {    // O(n) time rum
            arr[prev+1] = arr[prev];
            prev --;   //opposite chalte hai yaha
        }

        arr[prev+1] = curr;   //fill empty space, placing the curr elem in correct time
        
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

    inserationSort(arr, n);
    printArray(arr, n);

    return 0;
}


//time complex = O(n^2) of inseration sort

// Q. for printing to descening order mai, only change sign where camparision 

/*  for DESCENDING order

while(prev >= 0 && arr[prev] < curr) {    // O(n) time rum
            arr[prev+1] = arr[prev];
            prev --;   //opposite chalte hai yaha

} 
*/