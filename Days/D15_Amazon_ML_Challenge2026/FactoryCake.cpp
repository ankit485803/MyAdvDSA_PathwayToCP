

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> //  ADD THIS LINE
using namespace std;




int minCompletionTimeBruteForce(int A, const vector<int>& B, const vector<int>& C) {
    vector<int> indices(A);
    for (int i = 0; i < A; ++i) indices[i] = i;

    long long minTime = LLONG_MAX;

    cout << "All permutations and their total times:\n";

    do {
        // Print current permutation
        cout << "Order: ";
        for (int idx : indices)
            cout << idx << " ";
        cout << "| ";

        // Simulate time calculation
        long long pamTime = 0, samTime = 0;
        for (int i = 0; i < A; ++i) {
            int job = indices[i];
            pamTime += B[job];
            samTime = max(samTime, pamTime) + C[job];
        }

        cout << "TT: " << samTime << endl;

        minTime = min(minTime, samTime);

    } while (next_permutation(indices.begin(), indices.end()));

    return minTime;
}

int main() {
    int A = 4;
    vector<int> B = {3, 2, 2, 4};
    vector<int> C = {1, 2, 3, 4};

    long long result = minCompletionTimeBruteForce(A, B, C);

    cout << "\nMinimum total time across all permutations: " << result << endl;

    return 0;
}
