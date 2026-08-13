// Date of upload: 15th May 2026 Friday 


#include <iostream>
#include <vector>
using namespace std;

// Function to find the extra element using XOR logic
int findExtraElement(const vector<int>& A, const vector<int>& B) {
    int ans = 0;

    // XOR all elements of vector A
    for (int num : A) {
        ans ^= num;
    }

    // XOR all elements of vector B
    for (int num : B) {
        ans ^= num;
    }

    return ans;
}


// approach2: using map tc=sc= O(n)
int findExtraElement(const vector<int>& A, const vector<int>& B) {
    unordered_map<int, int> freq;

    // Count frequency of elements in A
    for (int num : A) {
        freq[num]++;
    }

    // Subtract frequency using elements of B
    for (int num : B) {
        freq[num]--;

        // If frequency becomes negative,
        // this element exists extra in B
        if (freq[num] < 0) {
            return num;
        }
    }

    return -1;
}

int main() {
    // Define the two input vectors
    vector<int> A = {2, 1, 3};
    vector<int> B = {2, 1, 3, 4};

    // Call function and display output
    cout << "Extra Element: " << findExtraElement(A, B) << endl;

    return 0;
}
