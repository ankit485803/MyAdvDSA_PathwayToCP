

git commit -m "feat(sigmaApnaCollege): start the newChap from today with printSubarr (ch13 arrPart II)" 


/*

17th Aug 2026 (Monday) Print Subarrays

Subarray is a continuos part of an array

*/


#include <iostream>
using namespace std;

void printArrays(int *arr, int n) {  //n means numSize arr to be print
    //outerLoop: kaha tak print karna h
    for(int st = 0; st < n; st++) {
        for(int end = st; end < n; end++) {
            cout << "(" << st << "," << end << ") "; 
        }

        cout << endl;
    }

}



int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    printArrays(arr, n);

    return 0;
}


/* OUTPUT
sanja@IITP:~$ cd /mnt/c/Users/sanja/Desktop/LabSession/
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ls
mapper.py  myRunFile.exe  reducer.py  scrape.py  sigmaApnaCollege.cpp  wiki.txt
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ notepad sigmaApnaCollege.cpp
^Csanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ ./myRunFile.exe
(0,0) (0,1) (0,2) (0,3) (0,4)
(1,1) (1,2) (1,3) (1,4)
(2,2) (2,3) (2,4)
(3,3) (3,4)
(4,4)
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$
*/



void printArrays(int *arr, int n) {   //tc=O(n^3)

    for(int st = 0; st < n; st++) {
        for(int end = st; end < n; end++) {
            //cout << "(" << st << "," << end << ") "; 
            
            for(int i=st; i <= end; i++) {
                cout << arr[i];
            }
            cout << ",";
        }
        cout << endl;
    }

}


/* OUTPUT
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
1,12,123,1234,12345,
2,23,234,2345,
3,34,345,
4,45,
5,
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/