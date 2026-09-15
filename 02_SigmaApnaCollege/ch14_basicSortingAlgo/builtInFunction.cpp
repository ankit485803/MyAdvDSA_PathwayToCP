

/*

Built In function in c++ jiska time O(n * logN) hai efficient 

sorting works on COMPARISION LOGIC pe esliye descending ke liye different logic 

*/



#include <iostream>
using namespace std;
#include <algorithm>  //reqFor builtInFunct



void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main() {
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    //sort(arr, arr+8);  //from starting to ending index tak complete arr ko sort 

    sort(arr+2, arr+5);  //sort 2nd to 5th idx tak ok SORT IN PARTS
    printArr(arr, 8);
    return 0;
}



int main() {
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};

    sort(arr, arr+8, greater<int>());  //descending order we have third parameters

    printArr(arr, 8);
    return 0;
}


