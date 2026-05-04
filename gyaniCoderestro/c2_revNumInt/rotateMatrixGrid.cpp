

/*4th May 2026 (Monday)

how to rotate the mat clockwise 90 deg
vector<vector<int>>& matrix

method1: with extraSpace - lastRow ko leke firstCol mai dala do and then return mat;
which we already doing in small 5th class

method2: without extraSpace -- stepA: grid transpose via diagonal mirrorImg and then stepB: revRows to get the rotatedMat 
class 11th approach

Transpose → rows become columns
Reverse rows → fixes direction → gives clockwise rotation
*/




//method1: concepts new[j][n - 1 - i] = matrix[i][j]  
vector<vector<int>> rotate(vector<vector<int>>& matrix) {  //tc=O(n^2) = sc
    int n = matrix.size();
    vector<vector<int>> res(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][n - 1 - i] = matrix[i][j];
        }
    }
    return res;
}




// method2:

void rotate(vector<vector<int>>& matrix) {  //tc=O(n^2), sc=O(1)
    int n = matrix.size();

    // Step A: Transpose (i, j) → (j, i)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step B: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}




/* How to derive LOGIC

🎯 Step 2: Track ONE element

Pick (i, j) → see where it goes.

Example:

1 at (0,0) → goes to (0,2)
2 at (0,1) → goes to (1,2)
3 at (0,2) → goes to (2,2)

🎯 Step 3: Find pattern
From examples:
Original (i, j)	New position
(0,0)	(0,2)
(0,1)	(1,2)
(0,2)	(2,2)


👉 Row becomes column → j
👉 Column becomes reversed row → n - 1 - i

So:
new_row = j
new_col = n - 1 - i



👉 Final:
new[j][n - 1 - i] = matrix[i][j];


*/