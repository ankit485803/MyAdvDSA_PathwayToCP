

/* 


Print numbers from 1 to n without the help of loops. You only need to complete the function printNos() that takes n as a parameter and prints the number from 1 to n recursively.

Note: Don't print any newline, it will be added by the driver code.


https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-1-to-n-without-using-loops

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printNos(int n) {
        if (n == 0) return;  // Base case

        printNos(n - 1);  // Recursive call
        cout << n << " ";  // Print number
    }
};

int main() {
    int n;
    cin >> n;
    Solution ob;
    ob.printNos(n);
    return 0;
}
