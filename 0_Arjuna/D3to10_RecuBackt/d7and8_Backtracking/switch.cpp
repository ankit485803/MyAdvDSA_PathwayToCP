

#include<iostream>
using namespace std;
#include <math.h>



/*
The switch statement in C++ is a multi-way decision-making control statement that allows executing different blocks of code based 
on the value of an expression. It is an alternative to multiple if-else conditions and is generally more efficient.





*/

switch (expression) {
    case value1:
        // Code block for value1
        break;
    case value2:
        // Code block for value2
        break;
    case value3:
        // Code block for value3
        break;
    default:
        // Default code block (optional)
}


//ans


#include <bits/stdc++.h>
using namespace std;
#include <cmath> // Use <cmath> for M_PI

class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        switch (choice) {
            case 1: // Area of Circle
                return M_PI * arr[0] * arr[0]; // Using M_PI
            
            case 2: // Area of Rectangle
                return arr[0] * arr[1]; // Corrected indices
            
            default:
                return -1;
        }
    }
};

// Driver Code for GFG
int main() {
    int choice;
    cin >> choice;
    
    vector<double> arr((choice == 1) ? 1 : 2); // Correct vector size
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i]; // Use cin instead of scanf
    }
    
    Solution obj;
    double res = obj.switchCase(choice, arr);

    cout << fixed << setprecision(2) << res << endl; // Ensure correct output format
}
