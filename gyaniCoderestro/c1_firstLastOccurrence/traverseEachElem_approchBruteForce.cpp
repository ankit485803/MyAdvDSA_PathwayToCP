

/* Link: https://www.instagram.com/reels/DXMYZakgW8q/

Problem Statement: 

given  Arr[7] = {1, 2, 2, 2, 3, 3, 4}, target = 2
find the fist and last occurrence index of target 


method1: bruteForce - traverse eachElem  tc=O(n), sc=O(1)

Use consistent verbs in git commit -m "feat(gyaniCoderestro): c1_firstLastOccurrence using BS"
Try to standardize:
    add
    refactor
    optimize
    fix
*/

#include <iostream>
using namespace std;
#include <vector>

void firstLastOccurrence(vector<int>& arr, int target) {
    int first = -1, last = -1;

    for(int i=0; i < arr.size(); i++) {
        if(arr[i] == target) {
            if(first == -1) {
                first = i;  //first occurrence 
            }
            last = i;  //keep updating last
        }
    }

    cout << "First Index: " << first << endl;
    cout << "Last Index of target:" << last << endl;
}


int main() {
    //vector<int> arr = {1, 2, 2, 2, 3, 3, 4};
    vector<int> arr(7);
    arr = {1, 2, 2, 2, 3, 3, 4};
    
    int target = 2;

    // callFunct
    firstLastOccurrence(arr, target);

    return 0;
}