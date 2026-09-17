
void spiralMat(int mat[4][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while(....) {

        //top
        for(int j = scol; j <= ecol; j++) {
            cout << mat[srow][j] << " ";
        }

        //right
        for(int i = srow+1; i <= erow; i++) {
            cout << mat[i][ecol] << " ";
        }

        //bottom
        for(int j = ecol-1; j >= scol; j--) {
            cout << mat[erow][j] << " ";
        }

        //left
        for(int i = erow-1; i >= srow + 1; i--) {
            cout << mat[i][scol] << " ";
        }
    }
    
    
}
/*

write code for Spiral Matrix

srow: starting row
erow: ending row
scol: stating column
ecol: ending col

top, bottom and left, right

pattern SEE: top -> right -> bottom -> left -> top -> right .... repeat until reach to center


*/


#include <iostream>
using namespace std;


void spiralMat(int mat[4][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while(srow <= erow && scol <= ecol) {  //odd matrix ke case mai equal to hoga otherwise middle wala centre elem print nahi hoga
        //top
        for(int j = scol; j <= ecol; j++) {
            cout << mat[srow][j] << " ";
        }

        //right
        for(int i = srow+1; i <= erow; i++) {
            cout << mat[i][ecol] << " ";
        }

        //bottom
        for(int j = ecol-1; j >= scol; j--) {
            cout << mat[erow][j] << " ";
        }

        //left
        for(int i = erow-1; i >= srow + 1; i--) {
            cout << mat[i][scol] << " ";
        }

        srow++; scol++;
        erow--; ecol--;
    }
    cout << endl;  
}


int main() {
    int mat[4][4] = { {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};

    int n = 4, m = 4;

    spiralMat(mat, n, m);

    return 0;
}


/* output
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/


int main() {
    int n = 4, m = 4;
    int mat[4][4] = { {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};
    
    spiralMat(mat, n, m);

    //corner case for odd matrix so to present from this hmko bottom and left pe ek condition dena hota hai
    int mat2[5][4] = { {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16},
                      {17, 18, 19, 20}};

    spiralMat(mat2, 5, 4);

    return 0;
}


void spiralMat(int mat[4][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while(srow <= erow && scol <= ecol) {  //odd matrix ke case mai equal to hoga otherwise middle wala centre elem print nahi hoga
        //top
        for(int j = scol; j <= ecol; j++) {
            cout << mat[srow][j] << " ";
        }

        //right
        for(int i = srow+1; i <= erow; i++) {
            cout << mat[i][ecol] << " ";
        }

        //bottom
        for(int j = ecol-1; j >= scol; j--) {
            if(srow == erow) {  //middl wala already top se print hai es liye again print mat karo
                break;
            }
            cout << mat[erow][j] << " ";
        }

        //left
        for(int i = erow-1; i >= srow + 1; i--) {
            if(scol == ecol) {  //middle
                break;
            }
            cout << mat[i][scol] << " ";
        }

        srow++; scol++;
        erow--; ecol--;
    }
    cout << endl;  
}


git commit -m "feat(sigmaApnaCollege): start chap and cover introducation and spiral matrix concepts (ch15_introTo2dArr)" 