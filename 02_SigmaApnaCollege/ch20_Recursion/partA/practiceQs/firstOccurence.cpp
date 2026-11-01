

/*
WAF to find the first occurrence of elem in arr


approach1: bruteForce - iterate each elem in arr if arr[i] == targ return i; else -1     tc=O(n), sc=O(1)
approach2: using sorting STL  tc=O(nlogN), sc=O(1)
sort(arr.begin(), arr.end())


approach3: using recursion  tc=O(n)=sc


*/

#include <iostream>
#include <vector>
using namespace std;


int firstOccur(vector<int> arr, int i, int targ) {
    //basecase work1
    if(i == arr.size()) {
        return -1;
    }

    if(arr[i] == targ) {  //work2: kaam Ankit 
        return i;
    }

    return firstOccur(arr, i+1, targ);  //next index pe jake check karenge esliye i+1  work3: jo innerFun karega
}


int main() {
    vector<int> arr = {1, 2, 3, 3, 4};
    int targ = 3;

    cout << firstOccur(arr, 0, targ) << endl;

    return 0;
}


//Approach 1: Brute force using loop
int firstOccurLoop(vector<int>& arr, int targ) {

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == targ) {
            return i;
        }
    }

    return -1;
}


/*
Approach 2: Using STL
One important correction: sort() does not find the first occurrence. It sorts the array and also changes the original order.
tc=O(n), sc=O(1)
*/

auto it = find(arr.begin(), arr.end(), targ);

if(it != arr.end()) {
    cout << distance(arr.begin(), it);
} else {
    cout << -1;
}