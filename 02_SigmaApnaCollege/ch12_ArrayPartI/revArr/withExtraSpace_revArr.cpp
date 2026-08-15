

/*

Reverse Arr: twoWays - with extraSpace and without extraSpace

In C++, a standard fixed-size array does not have a push_back() function. To add elements dynamically using push_back(), you must use a std::vector, 
which functions as a dynamic arr


*/

#include <iostream>
using namespace std;
#include <vector>


int revArr(int *arr, int n) {
    int ans[] = {};

    for(int i = n-1; i > 0; i--) {  //loop apply from backward REVERSE order
        ans.push_back(arr[i]);
    }

    return ans;
}



int main() {
    int arr[] = {5, 4, 3, 9, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << revArr(arr, n) << endl;


    return 0;
}


/*
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
sigmaApnaCollege.cpp: In function ‘int revArr(int*, int)’:
sigmaApnaCollege.cpp:10:13: error: request for member ‘push_back’ in ‘ans’, which is of non-class type ‘int [0]’
   10 |         ans.push_back(arr[i]);
      |             ^~~~~~~~~
sigmaApnaCollege.cpp:13:12: error: invalid conversion from ‘int*’ to ‘int’ [-fpermissive]
   13 |     return ans;
      |            ^~~
      |            |
      |            int*
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$
*/


#include <iostream>
using namespace std;

void revArr(int arr[], int n, int ans[]) {

    int j = 0;

    for (int i = n - 1; i >= 0; i--) {  
        ans[j] = arr[i];
        j++;
    }
}

int main() {

    int arr[] = {5, 4, 3, 9, 2};
    int n = sizeof(arr) / sizeof(int);

    int ans[n];

    revArr(arr, n, ans);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}


//using vector
#include <iostream>
#include <vector>
using namespace std;

vector<int> revArr(int *arr, int n) {
    vector<int> ans;  //sc=O(n)

    for (int i = n - 1; i >= 0; i--) {  //tc=O(n)
        ans.push_back(arr[i]);
    }

    return ans;
}

int main() {
    int arr[] = {5, 4, 3, 9, 2};
    int n = sizeof(arr) / sizeof(int);

    vector<int> result = revArr(arr, n);

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}