


#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();       
        int n = matrix[0].size();    


        int left = 0, right = m * n - 1;  // Binary search range
        


        while (left <= right) {
            int mid = left + (right - left) / 2; 
            int midValue = matrix[mid / n][mid % n];  // Convert to 2D indices
            
            if (midValue == target) {
                return true;  // Found the target

            } else if (midValue < target) {
                left = mid + 1;  // Search the right half
                
            } else {
                right = mid - 1;  // Search the left half
            }
        }
        
        return false;  
    }
};




// Example usage
int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1, 4, 7, 11},
                                  {2, 5, 8, 12},
                                  {3, 6, 9, 16},
                                  {10, 13, 14, 17}};
    int target = 7;

    bool result = solution.searchMatrix(matrix, target);
    cout << (result ? "Found" : "Not Found") << endl; // Expected Output: Found

    return 0;
}
