




/*



7th Aug 2025 (Thursday) but Amazon ML Challenge  happend on 3th Aug
https://www.scaler.com/partnerships/amazon


Cake Factory
Problem Description:
You are a manager at a cake factory, which has A orders to complete. Pam and Sam are workers at your factory. Every order must be worked on by both of them. For each order:

Pam must work on it first,
Then Sam works on it after Pam finishes.

For the i-th order (1 ≤ i ≤ A):
Pam takes B[i] units of time,
Sam takes C[i] units of time (starting only after Pam finishes that order).
Your task is to find the minimum total time required to complete all orders.



Constraints
1 ≤ A ≤ 10⁵
1 ≤ B[i], C[i] ≤ 10⁹



Input Format
The first line contains a single integer A, the number of orders.
The second line contains an integer array B of size A, where B[i] is the time Pam takes for the i-th order.
The third line contains an integer array C of size A, where C[i] is the time Sam takes for the i-th order.



Output Format
Return a single integer: the minimum total time required to complete all orders.

*/


// method1: Brute force -- pahle permutation findout all possible then total time for each return minTime, TC=O(n! * n)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCompletionTime(int A, vector<int>& B, vector<int>& C) {
    vector<pair<int, int>> front, back;

    // Divide into two parts
    for (int i = 0; i < A; ++i) {
        if (B[i] <= C[i])
            front.push_back({B[i], C[i]});
        else
            back.push_back({B[i], C[i]});
    }

    // Sort front by B ascending
    sort(front.begin(), front.end());

    // Sort back by C descending
    sort(back.begin(), back.end(), [](pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
    });

    // Merge the order
    vector<pair<int, int>> orders = front;
    orders.insert(orders.end(), back.begin(), back.end());

    // Simulate processing
    long long pamTime = 0, samTime = 0;
    for (auto& order : orders) {
        pamTime += order.first;
        samTime = max(samTime, pamTime) + order.second;
    }

    return samTime;
}

int main() {
    int A = 4;
    vector<int> B = {3, 2, 2, 4};
    vector<int> C = {1, 2, 3, 4};

    cout << minCompletionTime(A, B, C) << endl; // Output: 15

    return 0;
}



//method2: Two-machine flow shop scheduling (Johnson's Rule-Based Solution = Greedy Approach) TC=O(n log n), SC=O(n)