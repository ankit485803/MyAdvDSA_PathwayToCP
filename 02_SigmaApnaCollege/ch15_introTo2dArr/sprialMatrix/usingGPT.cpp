

#include <iostream>
using namespace std;

void spiralMat(int mat[][4], int n, int m) {
    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;

    while (srow <= erow && scol <= ecol) {

        // Top
        for (int j = scol; j <= ecol; j++) {
            cout << mat[srow][j] << " ";
        }

        // Right
        for (int i = srow + 1; i <= erow; i++) {
            cout << mat[i][ecol] << " ";
        }

        // Bottom
        if (srow < erow) {
            for (int j = ecol - 1; j >= scol; j--) {
                cout << mat[erow][j] << " ";
            }
        }

        // Left
        if (scol < ecol) {
            for (int i = erow - 1; i > srow; i--) {
                cout << mat[i][scol] << " ";
            }
        }

        // Move inward
        srow++;
        scol++;
        erow--;
        ecol--;
    }

    cout << endl;
}

int main() {
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    spiralMat(mat, 4, 4);

    return 0;
}