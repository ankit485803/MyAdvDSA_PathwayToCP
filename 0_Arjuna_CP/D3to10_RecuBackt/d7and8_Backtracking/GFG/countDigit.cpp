

// https://www.geeksforgeeks.org/problems/count-digits5716/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        
        
        int count = 0; //store valid no of digit
        int temp = n; //original no
        
        while(temp > 0) {
            int digit = temp % 10;  //extract last digit
            temp /= 10;  //remove last
            
            if(digit != 0 && n % digit  == 0) {
                count ++;
            }
            
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends