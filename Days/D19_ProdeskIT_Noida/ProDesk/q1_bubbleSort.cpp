
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



/*
6th Dec 2025 (Saturday)

q1. BubbleSort

   count no of comparison, determine no of swaps



*/




vector<int> bubbleSort(vector<int> arr) {

    //using TwoPointerApproach
    int left = 0;
    int right = arr.size() - 1;

    for(int i=0; i<arr.size(); i++) {   
        if(arr[left] < arr[right]) {
            swap(arr[left], arr[right]);
            return arr;
        }

    }

};



// using c++ STL
// sort(arr.begin(), arr.end());


int main() {
    vector<int> arr = {12, 7, 5, 19, 8, 3};
    

    return 0;
}





// final  15th May 2026 (Friday - sem6 goingToEnd)

#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> arr) {
    int comparisons = 0;
    int swaps = 0;

    int n = arr.size();

    for(int i=0; i < n-1; i++) {  //tc=O(n^2), sc=O(1)  dueToNestedloop
        for(int j=0; j < n - i - 1; j++) { 

            comparisons++;

            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }

    cout << "Comparisons = " << comparisons << endl;
    cout << "Swaps = " << swaps << endl;

    return arr;
}

void printArr(vector<int> arr) {
    for(int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 7, 5, 19, 8, 3};

    vector<int> sortedArr = bubbleSort(arr);

    cout << "Sorted Array = ";
    printArr(sortedArr);

    return 0;
}




/*
output
sanja@IITP:~$ cd /mnt/c/Users/sanja/Desktop/LabSession/
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ notepad sigmaApnaCollege.cpp
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
Comparisons = 15
Swaps = 10
Sorted Array = 3 5 7 8 12 19
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$



*/