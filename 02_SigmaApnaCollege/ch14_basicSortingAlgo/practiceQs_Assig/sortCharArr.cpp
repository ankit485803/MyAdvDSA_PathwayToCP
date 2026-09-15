

/*

15th Sep 2026 (Tuesday) in upcoming chapter Recursion mai mergeSort and quickSort we'll do

Sort this arr of characters using Insertion sort in ascending order

char ch = {'f', 'b', 'a', 'e', 'c', 'd'};

in c++ jaise integer compare hota hai wasi tarah char bhi hota hai compare

*/



#include <iostream>
using namespace std;

void printArr(char arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}


void sortChar(char arr[], int n) {   
    for(int i=1; i<n; i++) {

        int curr = arr[i];
        int prev = i-1;
        //while(prev >= 0 && arr[prev] > curr) {  //for ascending
        while(prev >= 0 && arr[prev] < curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }

        arr[prev+1] = curr;
    }

    printArr(arr, n);
}


int main() {
    char ch[6] = {'f', 'b', 'a', 'e', 'c', 'd'};
    int n = sizeof(ch) / sizeof(char);

    sortChar(ch, n);

    return 0;
}