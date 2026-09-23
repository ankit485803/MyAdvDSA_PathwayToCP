
git commit -m "feat(sigmaApnaCollege): solve assig transpose matrix prob today (ch15_introTo2dArr)" 
/*

23rd Sep 2026 (Wednesday)

Question 3 : Write a program to Find Transpose of a Matrix. 
What is Transpose? 
Transpose of a matrix is the process of swapping the rows to columns. For a 2x3 
matrix, 
        Matrix 
        a11 a12 a13 
        a21 a22 a23 
Transposed Matrix 
        a11 a21 
        a12 a22 
        a13 a23

ok


*/

#include <iostream>
using namespace std;


void transposeMat(int mat[2][3], int n, int m) {
    //iterate each cell of mat and swap[row][cols] to [cols][row]

    for(int i=0; i<n; i++) { //firstAttempt
        for(int j=0; j<m; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    cout << endl;
}


int main() {
    int mat[][3] = { {1, 2, 3},
                     {4, 5, 6}};


    transposeMat(mat, 2, 3);
    return 0;
}


/*Output
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe

*** stack smashing detected ***: terminated
Aborted (core dumped)
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$



*/


void transposeMat(int mat[][3], int n, int m) {  //tc=O(n*m), sc=O(1)
    int transpose[3][2];  //take Variable

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            transpose[j][i] = mat[i][j];  //main logic: put row into cols and vice-versa
        }
    }

    //printingElem
    for(int i=0; i < m; i++) {
        for(int j=0; j < n; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
}