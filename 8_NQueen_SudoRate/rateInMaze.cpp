

#include <iostream>
using namespace std;
#include <vector>

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans, vector<vector<bool>> &vis) {

    int n = mat.size();
    
    // Base case: If out of bounds or cell is blocked or already visited
    if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c]) {
        return;
    }

    // If we reach the bottom-right corner, add the path to the answer
    if(r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    vis[r][c] = true;

    // Recur for all 4 possible directions
    helper(mat, r + 1, c, path + "D", ans, vis); // down
    helper(mat, r - 1, c, path + "U", ans, vis); // up
    helper(mat, r, c - 1, path + "L", ans, vis); // left
    helper(mat, r, c + 1, path + "R", ans, vis); // right

    // Backtrack: unmark the current cell
    vis[r][c] = false;
}

vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false)); // To keep track of visited cells

    // Start from the top-left corner (0,0)
    if(mat[0][0] == 1) { // If the start is blocked, return an empty path
        helper(mat, 0, 0, "", ans, vis);
    }

    return ans; 
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = findPath(mat);
    if(ans.empty()) {
        cout << "No path found." << endl;
    } else {
        for(string path : ans) {
            cout << path << endl;
        }
    }

    return 0;
}



// TC = O(4 ** N^2) -- SC = visited O(n^2)

