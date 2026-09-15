

/*


Question 1 : Use the following sorting algorithms to sort an array in DESCENDING 
order : 
a. Bubble Sort 
b. Selection Sort 
c. Insertion Sort 
d. Counting Sort 
You can use this array as an example : [3, 6, 2, 1, 8, 7, 4, 5, 3, 1]

*/


#include <iostream>
#include <climits>
using namespace std;

// Function to print array
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 1. Bubble Sort - Descending
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            // Swap if left element is smaller
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2. Selection Sort - Descending
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {

        // Find maximum element
        int maxIdx = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }

        swap(arr[i], arr[maxIdx]);
    }
}

// 3. Insertion Sort - Descending
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {

        int curr = arr[i];
        int prev = i - 1;

        // Shift smaller elements to the right
        while (prev >= 0 && arr[prev] < curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = curr;
    }
}

// 4. Counting Sort - Descending
void countingSort(int arr[], int n) {

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    // Find minimum and maximum
    for (int i = 0; i < n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    // Frequency array
    int freq[100000] = {0};

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Reconstruct array in descending order
    int j = 0;

    for (int i = maxVal; i >= minVal; i--) {

        while (freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }
}

// Main function
int main() {

    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr) / sizeof(int);

    // Bubble Sort
    int arr1[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    bubbleSort(arr1, n);

    cout << "Bubble Sort:    ";
    printArr(arr1, n);

    // Selection Sort
    int arr2[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    selectionSort(arr2, n);

    cout << "Selection Sort:  ";
    printArr(arr2, n);

    // Insertion Sort
    int arr3[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    insertionSort(arr3, n);

    cout << "Insertion Sort:  ";
    printArr(arr3, n);

    // Counting Sort
    int arr4[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    countingSort(arr4, n);

    cout << "Counting Sort:   ";
    printArr(arr4, n);

    return 0;
}



/* output

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
Bubble Sort:    8 7 6 5 4 3 3 2 1 1
Selection Sort:  8 7 6 5 4 3 3 2 1 1
Insertion Sort:  8 7 6 5 4 3 3 2 1 1
Counting Sort:   8 7 6 5 4 3 3 2 1 1
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$


*/


git commit -m "feat(sigmaApnaCollege): complete this chap and covered 4 types of sortingAlgo: Bubble, selection, insertion, counting with assig ques (ch14 basicSortingAlgo)" 