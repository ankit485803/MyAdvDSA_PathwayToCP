

/*
src: https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

GCD = HCF
formula
LCM(a, b) = |a*b| divide by GCD(a, b)



Given two integers a and b, the task is to compute their LCM and GCD and return an array containing their LCM and GCD.

Examples:

Input: a = 5 , b = 10
Output: [10, 5]
Explanation: LCM of 5 and 10 is 10, while their GCD is 5

*/




#include <bits/stdc++.h>
using namespace std;


//method1: Build In funct

// class Solution {
// public:
//     vector<int> lcmAndGcd(int A, int B) {
//         int gcd = __gcd(A, B); // Built-in function to compute GCD
//         int lcm = (A / gcd) * B; // Using the LCM formula
//         return {lcm, gcd};
//     }
// };

// int main() {
//     int a, b;
//     cin >> a >> b;
//     Solution obj;
//     vector<int> result = obj.lcmAndGcd(a, b);
//     cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl;
//     return 0;
// }





//method2: scratch
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute GCD using Euclidean Algorithm
    int computeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to compute LCM using the GCD formula
    int computeLCM(int a, int b, int gcd) {
        return (a / gcd) * b; // Avoids overflow issues
    }

    vector<int> lcmAndGcd(int A, int B) {
        int gcd = computeGCD(A, B);
        int lcm = computeLCM(A, B, gcd);
        return {lcm, gcd};
    }
};

int main() {
    int a, b;
    cin >> a >> b; // Take input
    Solution obj;
    vector<int> result = obj.lcmAndGcd(a, b);
    
    cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl;
    return 0;
}

/*
Time Complexity: O(log(min(a, b))) (due to Euclidean GCD calculation)

Space Complexity: O(1) (uses only a few integer variables)

*/