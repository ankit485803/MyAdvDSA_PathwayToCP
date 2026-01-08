


/* https://www.geeksforgeeks.org/problems/data-type-1666706751/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=data-type

Here we need to know about the sizes of datatype like character, Integer, Long, Float and Double

Character- 1 byte
Integer-4 bytes
Float- 4 bytes
Long - 8bytes
Double- 8 bytes


*/





//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int dataTypeSize(string str) {
        // your code here
        
        // 24th March 2025 (Monday)
        
        if(str == "Character") {
            return 1;
        }
        
        else if(str == "Integer" || str == "Float") {
            return 4;
        }
        
        else if(str == "Double" || str == "Long") {
            return 8;
        }
        
        else {
            return -1;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends