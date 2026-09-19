

/*

Search in sorted matrix

approach1: bruteForce O(n*m) go to each cell and search

2. row/cols wise: apply binarySearch  tc=O(n * logN) row 
                                        tc=O(m * logN) cols wise mai

3. Staircase Search         tc=O(n + m)                               

It follows two important conditions:
        Every row is sorted in ascending order.
        Every column is sorted in ascending order.
This allows us to use Staircase Search.



*/


#include <iostream>
using namespace std;

//each Rows and columns sorted apporach3
bool searchStaircase(int mat[][4], int n, int m, int key) {
    int i = 0, j = m-1;

    while(i < n && j >= 0) {
        if(mat[i][j] == key) {
            cout << "found at cell (" << i << "," << j << ")\n";
            return true;

        } else if(mat[i][j] > key) {
            //left
            j--;
        } else {
            //down
            i++;
        }
    }

    cout << "key not found\n";
    return false;
}


int main() {
    int mat[][4] = { {10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};

    searchStaircase(mat, 4, 4, 33);  //search for 33 key

    return 0;
}



//approach1: bruteForce tc=O(n * m) due to nestedLoop, sc=O(1) for anyMatrix
bool searchBruteForce(int mat[][4], int n, int m, int key) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == key) {
                cout << "Found at cell ("
                     << i << "," << j << ")\n";
                return true;
            }
        }
    }

    cout << "Key not found\n";
    return false;
}


//approach2: Row-wise Binary Search — O(n × log m) condition: Each row sorted
bool searchRowWise(int mat[][4], int n, int m, int key) {
    for (int i = 0; i < n; i++) {
        int start = 0;
        int end = m - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mat[i][mid] == key) {
                cout << "Found at cell ("
                     << i << "," << mid << ")\n";
                return true;
            }
            else if (mat[i][mid] < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    cout << "Key not found\n";
    return false;
}




//approach3: Column-wise Binary Search — O(m × log n)
//condition- Each column sorted
bool searchColWise(int mat[][4], int n, int m, int key) {
    for (int j = 0; j < m; j++) {
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mat[mid][j] == key) {
                cout << "Found at cell ("
                     << mid << "," << j << ")\n";
                return true;
            }
            else if (mat[mid][j] < key) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    cout << "Key not found\n";
    return false;
}

