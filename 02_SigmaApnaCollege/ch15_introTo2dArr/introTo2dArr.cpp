
git commit -m "feat(sigmaApnaCollege): start newChapter and restructure files (ch15_introTo2dArr)" 

/*

16th Sep 2026 (Wednesday)

Exactly 👍 — for a 2D array parameter, the first dimension can be omitted, but the second dimension is required.

Think of it this way:  int arr[rows][columns];
When passing it to a function: int func(int arr[][3], int rows, int columns)

Why can we omit the first dimension?
The function doesn't need the number of rows to understand how to move through the array. You provide it separately:

Why can't we omit the second dimension?
Because the compiler needs to know how wide each row is to calculate where arr[i][j] is located.



*/

#include <iostream>
using namespace std;

int main() {
    int students[3][3] = { {100, 100, 100},   //yah second wala 3 as parameter dena mandatory hai 
                            {85, 74, 89},
                            {63, 72, 65}};

    cout << students[1][1] << endl;  //ans at index (1, 1)
    return 0;
}
