

/*

7th May 2026 (Thursday)

prob: Check if Array Is Sorted and Rotated
Link: https://www.instagram.com/reel/DXeSWBSgWOf   (23 April Thur uploaded)


given arr A[5] = [3, 4, 5, 1, 2]
  not sorted


method1: bruteForce rotate each from right and check using nestedLoop tc=O(n^2), sc=O(n)


method2 optimized - property of any sortedArr: everySortedArr ek circular pattern follow karta hai jaha ek point pe currElem > nextElem hota hai 
                        hn log wasi observation ko use karenge method2 mai

ok
Property:
Every sorted & rotated array follows
a circular sorted pattern.
There will be only ONE position where:  currElem > nextElem


*/


#include <iostream>
using namespace std;
#include <vector>


void checkSortedAndRotatedBrute(vector<int>& arr) {
    int n = arr.size();

    for(int k=0; k < n; k++) {
        vector<int> rotatedArr(n);

        //Generate the kth rotation 
        for(int i=0; i<n; i++) {
            rotatedArr[i] = arr[(i + k) % n];   //yaha i+k se lastElem compare also
        }

        //check if this specific rotation is sorted
        if(isSorted(rotatedArr)) {
            return true;
        }
    }

    return false;
}



// optimized tc=O(n), sc=O(1)
bool check(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    
    for(int i=0; i<n; i++) {
        if(arr[i] > arr[(i + 1) % n]) {
            count++;
        }
    }

    return count <= 1;  //possible to makeSorted if count <= 1
}


int main() {
    vector<int>& arr = [3, 4, 5, 1, 2];


    return 0;
}


// git commit -m "feat(gyaniCoderestro): c3_checkArrSortedRotated using bruteForce nestedLoop and optimized using sortedArr prop"