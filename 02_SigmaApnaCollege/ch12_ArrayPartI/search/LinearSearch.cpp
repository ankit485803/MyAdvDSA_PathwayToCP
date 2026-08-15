

/*

15th Aug 2026 (Saturday - Happy Independence day)

LinearSearch: can apply on sorted or unsorted arr

tc=O(n) linear

TC: relation b/w inputSize (arrSize) and no of operations 

*/

#include <iostream>
using namespace std;

int linearSearch(int *arr, int n, int key) {  //tc=O(n) linear, sc=O(1)
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;  //output idx
        }
    }

    return -1;  //if not key 
}



int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(int);

    cout << linearSearch(arr, n, 10) << endl;

    return 0;
} 