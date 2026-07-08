

/*

8th July 2026 (Wednesday)

find the largest 

arr = {5, 4, 3, 9, 2}

method1: sort arr using any sorting algo BubbleSort, Quick sort, etc and return lastElem, tc=O(n logN), sc=O(1)
method2: using STL, tc=O(n), sc=O(1)
int *max_elem = arr.begin(), arr.end();

method3: iterative approach  tc=O(n), sc=O(1)

*/

#include <iostream>
using namespace std;


int main() {
    //int arr[6] = {5, 4, 3, 9, 2, 8};
    int arr[] = {5, 4, 3, 9, 2, 8, 12};
    int n = sizeof(arr) / sizeof(int);

    //method3 iterate each elem
    int maxElem = arr[0];
    int min = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxElem) {
            maxElem = arr[i];
            cout << "assign value " << arr[i] << " to max\n";
        }

        if(arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Largest Elem = " << maxElem << endl; 
    cout << "min = " << min << endl;

    return 0;
}



/*
output

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
assign value 9 to max
assign value 12 to max
assign value 15 to max
Largest Elem = 15
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$


    cout << "Largest Elem = " << maxElem << endl; 
    cout << 'min = ' << min << endl;

sigmaApnaCollege.cpp:25:13: warning: character constant too long for its type
   25 |     cout << 'min = ' << min << endl;
      |             ^~~~~~~~
assign value 9 to max
assign value 12 to max
Largest Elem = 12
18476065602
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

In C++:

Double quotes (" ") are for strings.
Single quotes (' ') are for a single character.

For example:

'A'      // Correct: a character
"Hello"  // Correct: a string

*/