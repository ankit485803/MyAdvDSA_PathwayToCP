


#include <iostream>
#include <vector>
using namespace std;

void printSubS(vector<int>& arr, vector<int> ans, int i, int& count) {
    if (i == arr.size()) {
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        count++;  // Increment count for each subset
        return;
    }

    // Inclusion step
    ans.push_back(arr[i]);
    printSubS(arr, ans, i + 1, count);

    // Backtracking step
    ans.pop_back();

    // Exclusion step
    printSubS(arr, ans, i + 1, count);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;  // Store current subset
    int count = 0;    // To count total subsets

    printSubS(arr, ans, 0, count);

    cout << "\nTotal number of subsets: " << count << endl;

    return 0;
}
