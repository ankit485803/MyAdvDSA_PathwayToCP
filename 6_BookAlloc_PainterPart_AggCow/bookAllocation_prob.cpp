
/* this ques on GFG   https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1


11th Oct 2024 (Friday) se start


 This is book allocation problem. Here we apply the binary search algo, not directly, but indirectly the concept

 */



#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

//make isValid funct
int isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;

    for(int i=0; i<n; i++) {   //yah loop complex = O(n)
        if(arr[i] > maxAllowedPages) {
            return false;
        }

        //adding pages
        if(pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students ++;
            pages = arr[i];
        }
    }

    return students > m ? false : true;
}


//create  allocation funct
int allocationBooks(vector<int> &arr, int n, int m) {      //total complex of code = O(log(Range) * n)    
    if(n > m) {   //edge case
        return -1;
    }


    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    int ans = -1;
    int st = 0, end = sum;  //we got range of all possible ans

    while(st <= end) {     ////yah complex = O(log(range)) because hm Binary Search applied
        int mid = st + (end-st)/2;

        if(isValid(arr, n, m, mid)) {  //LEFT
            ans = mid;
            end = mid - 1;

        } else {  //RIGHT
            st = mid + 1;

        }
    }

    return ans;
    

}


//main funt
int main() {
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 5;      //n = no of books, m = no of student 

    cout << allocationBooks(arr, n, m) << endl;
    return 0;

}