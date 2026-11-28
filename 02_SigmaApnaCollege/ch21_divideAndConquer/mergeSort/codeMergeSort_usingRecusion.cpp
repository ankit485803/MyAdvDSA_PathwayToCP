

/*

27th Nov 2026 (Friday)

jab history study karte the in childhood British bhi divide and conquer karke kingdom win karte the

step1: divide -- mid = (si + ei) / 2;  starting idx, endingIdx
step2: mergeSort(left)
       mergeSort(right)  -- subProb

step3: merge() function likho conquer wala step


tc=O(nlogN), sc=O(n)
*/


#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei) {  //tc=O(n) yahi step3 imp hai conquer
    vector<int> temp;
    int i = si;
    int j = mid+1;

    while(i <= mid && j <= ei) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    //check
    while(i <= mid) {
        temp.push_back(arr[i++]);
    }

    //dono loop mai se koi ek hi run hoga
    while(j <= ei) {
        temp.push_back(arr[j++]);
    }

    //copy vector to original arr
    for(int idx = si; idx <= ei; idx++) {  //original arr
        arr[idx] = temp[idx - si];
    }
}


void mergeSort(int arr[], int si, int ei) {  //tc=O(nlogN)
    //baseCase
    if(si >= ei) {
        return;
    }

    //divide step1
    int mid = si + (ei - si)/2;  //esmai data overflow nahi hoga
    
    mergeSort(arr, si, mid); //left half  step2
    mergeSort(arr, mid+1, ei);  //right 

    merge(arr, si, mid, ei); //step3  conquer wala
}


void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    mergeSort(arr, 0, n-1);
    printArr(arr, n);


    return 0;
}



/* output
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
6 6 7 7 0 0
*** stack smashing detected ***: terminated
Aborted (core dumped)
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/