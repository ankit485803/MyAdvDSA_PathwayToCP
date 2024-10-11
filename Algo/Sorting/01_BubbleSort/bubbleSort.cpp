
// Bubble sort works on array to sort, with (n-1) iterations
// working principle = next elem ko every time compare and then swap to left when smaller than that index


#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>


//create funct bubble
void bubbleSort(int arr[], int n) {

    bool isSwap = false;   //jab sorted arr ho, to directly return

    for(int i=0; i<n-1; i++) {   //outer loop-- to kitne bar loop laega ITERATION  == time compl = 1*n bar chalega
        for(int j=0; j<n-i-1; j++) {  //inner loop: kya kam karna h -- time compl = n*n bar chalega 


            if(arr[j] > arr[j+1]) {   //agar apko DESCENDING order mai need h to, change sign < 
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }

        }

        if(! isSwap) {  //arr is already sorted
            return;
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

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}



// time compl of bubble sort = O(n^*n)    this happen in all case (best, avg, worst)

// but efficiency sorting algo = O(nlogn) par kam karta h e.g. Merge sort, Avg Quick sort