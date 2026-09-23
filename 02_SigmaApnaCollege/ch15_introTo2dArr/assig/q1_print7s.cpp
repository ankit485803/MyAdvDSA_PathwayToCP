
git commit -m "feat(sigmaApnaCollege): complete this chapter lecture and assig ques left (ch15_introTo2dArr)" 
/*

20th Sep 2026 (Sunday)

Question 1 : Print the number of all 7’s that are in the 2d array. 
Example : 
Input - int arr[ ][ ] = { {4,7,8}, {8,8,7} }; n = 2, m = 3 
Output - 2 


Here:
n → number of rows
m → number of columns
3 → compile-time column size required by the array type



*/


#include <iostream>
using namespace std;


int countSeven(int arr[][3], int n, int m) {   //tc=O(n * m), sc=O(1)
    int count = 0;

    for(int i=0; i<n; i++) {  //OUTER loop: no of rows 
        for(int j=0; j<m; j++) {  //innerLoop cols
            if(arr[i][j] == 7) {
                count++;
            }
        }
    }

    cout << "no of seven in the 2D arr =" << count << endl;
    return count;
}


int main() {
    int matrixArr[2][3] = { {4, 7, 8},
                      {8, 8, 7}};

    
    countSeven(matrixArr, 2, 3);

    return 0;
}



int countSeven(int arr[][3], int n, int m) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 7) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int matrixArr[2][3] = {
        {4, 7, 8},
        {8, 8, 7}
    };

    cout << "No. of sevens in the 2D array = "
         << countSeven(matrixArr, 2, 3) << endl;

    return 0;
}
