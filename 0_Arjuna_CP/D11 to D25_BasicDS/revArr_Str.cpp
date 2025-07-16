
#include <iostream>
using namespace std;



/*

16th July 2025 (Wednesday) reverse arr and str using recursion & iteration/Normal method



*/


void revArr_UsingRecursion(int arr[], int st, int end) {  //TC=O(n)=SC
    //baseCase
    if(st >= end) {
        return;
    }


    //swaping elem
    int temp = arr[st];
    arr[st] = arr[end];
    arr[end] = temp;


    //recursive call the fun
    revArr_UsingRecursion(arr, st + 1, end-1);

}



void revArr_Iterative(int arr[], int n) {  //TC=O(n), SC=O(1)
    int st = 0;
    int end = n-1;

    while(st < end) {
        //swap elem
        int temp = arr[st];
        arr[st] = arr[end];
        arr[end] = temp;

        st++;
        end--;

    }
}



int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);    //total no elem in arr or hm bolte hai Length of arr

    //revArr_UsingRecursion(arr, 0, n-1);
    revArr_Iterative(arr, n);



    //printing
    cout << "Reversed Arr: " ;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";

    }
    cout << endl;


    return 0;
}