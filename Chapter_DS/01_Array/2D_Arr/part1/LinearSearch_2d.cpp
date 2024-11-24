
#include <iostream>
using namespace std;

/* apply Linear search in 2d arr -- go on cell similar to noraml arr mai each numb pe jate h


*/

bool LinearSearch(int mat[][3], int rows, int cols, int key) {  //we need to give col val in matrix because it's format

    for(int i=0; i<rows; i++) {
        for(int j=0; i<cols; j++) {
            if(mat[i][j] == key) {  //check cell value with key to find
                return true;
            }
        }
    }

    return false;

}



int main() {

    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};         //2d array
    int rows = 4;
    int cols = 3;

    cout << LinearSearch(matrix, rows, cols, 8) << endl;  // 1 mean yes, 0 mean NO

    return 0;
}