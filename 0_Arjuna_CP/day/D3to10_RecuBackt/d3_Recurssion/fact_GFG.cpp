

// iterative -- O(n)

#include <bits/stdc++.h>
using namespace std;

// Function to calculate factorial iteratively -- TC=O(n), SC=O(1)
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    cin >> n;  // Taking user input

    cout << factorial(n) << endl;  // Printing factorial
    return 0;
}






// Recursive function to calculate factorial -- TC=O(n) = SC
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;  // Base Case
    return n * factorial(n - 1);
}


//GFG IDE format

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int factorial(int n) {
        // code here
        long long fact = 1;  // Initialize factorial to 1

        for (int i = 2; i <= n; i++) {  // Loop from 2 to n
            fact *= i;
        }

        return fact;
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
        cout << ob.factorial(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends