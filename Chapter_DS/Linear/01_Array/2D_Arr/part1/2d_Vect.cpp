

#include <iostream>
using namespace std;
#include <vector>

//2d vector can resize dynamically, 

// 2d arr se 2d vec se advantage hai


int main() {
    vector <vector <int>> mat = {{1, 2, 3}, {4, 5, 6, 10, 11, 12}, {7, 8, 9}};  //3*3

    //cout << mat[0][0] << endl; 



    //all elem print of 2d matrix
    // row => mat.size();
    // cols = 1 row kitne elements hai -- mat[i].size();


    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }

        cout << endl;
    }


    return 0;
}