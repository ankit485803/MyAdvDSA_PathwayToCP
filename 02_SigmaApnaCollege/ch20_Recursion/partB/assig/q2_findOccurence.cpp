

/*

25th Nov 2026 (Wednesday - after Diwali Chhath Puja)


Question 2 : For a given integer array of size N. You have to find all the occurrences 
(indices) of a given element (Key) and print them. 
Use a recursive function to solve this problem. 
Sample Input : arr[ ] = {3, 2, 4, 5, 6, 2, 7, 2, 2}, key = 2 
Sample Output : 1 5 7 8



Time Complexity (TC): 
O(N) — traverses every array element once.

Space Complexity (SC): 
O(N) — recursive call stack.

*/

#include <iostream>
using namespace std;

void findOccurrences(int arr[], int n, int key, int i) {

    // Base case
    if (i == n) {
        return;
    }

    // Check if current element matches key
    if (arr[i] == key) {
        cout << i << " ";
    }

    // Recursive call
    findOccurrences(arr, n, key, i + 1);
}

int main() {
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int n = 9;
    int key = 2;

    findOccurrences(arr, n, key, 0);
    cout << endl;

    return 0;
}