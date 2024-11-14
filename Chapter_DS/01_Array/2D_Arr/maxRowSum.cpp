
#include <iostream>
using namespace std;


// Max Row sum


int getMaxSum(int mat[][3], int rows, int cols) {
    int maxRowSum = INT8_MAX;
    
    for(int i=0; i<rows; i++) {
         int rowSumI = 0;

        for(int j=0; j<cols; j++) {
           rowSumI += mat[i][j];
        }

        maxRowSum = max(maxRowSum, rowSumI);
    }

    return maxRowSum;

}





int main() {

    int matrix[3][3] = {{1, 2, 300}, {4, 5, 6}, {7, 8, 9}};         //2d array
    int rows = 3;
    int cols = 3;

    cout << getMaxSum(matrix, rows, cols) << endl;
}