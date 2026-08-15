

/*

15th Aug 2026 (Saturday)

binarySearch: can only apply on the sortedArr okk

threeWorks: 
find mid
if arr[mid] == key  
arr[mid] < key then search in 2nd half
arr[mid] > key then 1st half 


TC: relation b/w inputSize (n) and no of operations (LOOP)
tc=O(logN)

*/

#include <iostream>
using namespace std;


int binarySearch(int arr[], int n, int key) {  //given key jisko find karna hai and n = sizeof arr
    int st = 0, end = n-1;

    while(st <= end) {
        //int mid = (st + end) / 2;
        int mid = st + (end - st) / 2;

        if(arr[mid] == key) {
            return mid;  // idx of mid

        } else if(arr[mid] < key) {  //search in 2nd half
            st = mid + 1;

        } else {  //1st half
            end = mid - 1;
        }
    }

    return -1;   //if not found any key
}



int main() {
    int arr[] = {2, 4 ,6, 8, 10, 12, 14, 16, 18};
    int n = sizeof(arr) / sizeof(int);

    cout << binarySearch(arr, n, 8) << endl;

    return 0;
}



#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int st = 0, end = n - 1;
    int count = 0;

    while (st <= end) {
        count++;  // count each iteration

        int mid = st + (end - st) / 2;

        if (arr[mid] == key) {
            cout << "No. of iterations: " << count << endl;
            return mid;
        }
        else if (arr[mid] < key) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << "Key not found" << endl;
    cout << "No. of iterations: " << count << endl;

    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int n = sizeof(arr) / sizeof(int);

    cout << "Index: " << binarySearch(arr, n, 8) << endl;

    return 0;
}
