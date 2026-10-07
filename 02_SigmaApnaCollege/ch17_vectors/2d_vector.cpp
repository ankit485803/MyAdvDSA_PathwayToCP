

/*

7th Oct 2026 (Wednesday)

2D vector: matrix

*/

#include <iostream>
#include <vector>
using namespace std;



int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> mat2 = {{1, 2, 3}, {4, 5}, {6}};


    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //size and capacity

    return 0;
}