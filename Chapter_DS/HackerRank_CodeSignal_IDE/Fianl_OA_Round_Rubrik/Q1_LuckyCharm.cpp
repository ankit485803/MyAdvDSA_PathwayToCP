

/* QUES

Alice has provided you with an array of length M consisting of distinct integers in range [1,P]. Alice considers these and only these integers to be lucky.
Alice asks you to count the number of sequences of length N where each element is an integer in the range [1, P]. Additionally, the sum of all the elements in the sequence must be divisible by K, and at least one element of the sequence must be a lucky number.

Output the count of such sequences, modulo 998244353.


Constraints:
1 ≤ N ≤ 10⁷
1 ≤ P ≤ 10⁷
1 ≤ K ≤ 100
1 ≤ M ≤ min(P, 10⁶)
1 ≤ A ≤ P
All A are distinct
Subtask 1: 90 points
V ≤ 10⁵
K ≤ 20



concept req: Dynamic Programming (DP) on States/Sequences, Probability, Expected Value, and Randomized Algorithms
Combinatorics and Inclusion-Exclusion Principle,  Modular Arithmetic and Modular Exponentiation



approach= 

Why it’s important:
Handling large numbers modulo a prime (like 998244353) is common in competitive programming. Modular exponentiation allows
 efficient computation of powers in O(log(n))





*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 998244353;

// Function for modular exponentiation: (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Main function to calculate the number of valid sequences
long long count_valid_sequences(int N, int P, int M) {
    long long total_sequences = mod_exp(P, N, MOD);
    long long non_lucky_sequences = mod_exp(P - M, N, MOD);

    // Valid sequences with at least one lucky number
    long long valid_sequences = (total_sequences - non_lucky_sequences + MOD) % MOD;

    return valid_sequences;
}

int main() {
    int N, P, K, M;
    cin >> N >> P >> K >> M;

    set<int> lucky_numbers;
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        lucky_numbers.insert(num);
    }

    // Compute and print the result
    cout << count_valid_sequences(N, P, M) << endl;

    return 0;
}

// Modular Exponentiation: O(log(n)) for each call,   Overall = O(Log(n))







































#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 998244353;

// Function to count the number of sequences with a sum % k == 0
vector<long long> count_seq_with_sum(int n, int total_count, int k) {
    vector<long long> dp(k, 0);
    dp[0] = 1;  // There's one way to get sum 0 modulo k

    // Iterate over all elements in the sequence
    for (int i = 0; i < n; ++i) {
        vector<long long> new_dp(k, 0);

        // Iterate over all current sums modulo k
        for (int sum_mod = 0; sum_mod < k; ++sum_mod) {
            for (int num = 1; num <= total_count; ++num) {
                // Update the new dp with current element
                int new_sum_mod = (sum_mod + num) % k;
                new_dp[new_sum_mod] = (new_dp[new_sum_mod] + dp[sum_mod]) % MOD;
            }
        }
        dp = new_dp;
    }
    return dp;
}

// Function to count sequences with the given constraints
long long count_sequences(int n, int p, int k, const set<int>& lucky_numbers) {
    int m = lucky_numbers.size();  // Number of lucky numbers
    int non_lucky_count = p - m;   // Elements that are not lucky

    // Count total sequences with sum % K == 0
    vector<long long> total_count = count_seq_with_sum(n, p, k);

    // Count sequences with at least one lucky number
    vector<long long> lucky_count = count_seq_with_sum(n, m, k);

    // Count sequences without any lucky number
    vector<long long> non_lucky_count_seq = count_seq_with_sum(n, non_lucky_count, k);

    // Extract the valid counts (sum % K == 0)
    long long total_sequences = total_count[0];
    long long excluded_sequences = non_lucky_count_seq[0];

    // Calculate valid sequences with at least one lucky number
    long long valid_sequences = (total_sequences - excluded_sequences + MOD) % MOD;

    return valid_sequences;
}

int main() {
    int n, p, k, m;
    cin >> n >> p >> k >> m;

    set<int> lucky_numbers;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        lucky_numbers.insert(num);
    }

    // Compute and print the result
    cout << count_sequences(n, p, k, lucky_numbers) << endl;

    return 0;
}




// solution2


#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 998244353;

// Function to compute the number of sequences with sum % K == 0 using DP
vector<long long> count_sequences_with_mod_sum(int n, int total_count, int k) {
    vector<long long> dp(k, 0);
    dp[0] = 1;  // One way to have sum % k == 0 with an empty sequence

    for (int i = 0; i < n; ++i) {
        vector<long long> new_dp(k, 0);

        // Use prefix sum to efficiently update new_dp
        for (int sum_mod = 0; sum_mod < k; ++sum_mod) {
            for (int num = 1; num <= total_count; ++num) {
                int new_sum_mod = (sum_mod + num) % k;
                new_dp[new_sum_mod] = (new_dp[new_sum_mod] + dp[sum_mod]) % MOD;
            }
        }

        dp = new_dp;  // Update dp for the next iteration
    }
    return dp;
}

// Main function to calculate the valid sequences as per the problem constraints
long long count_sequences(int n, int p, int k, const set<int>& lucky_numbers) {
    int m = lucky_numbers.size();         // Count of lucky numbers
    int non_lucky_count = p - m;          // Count of non-lucky numbers

    // Get total sequences with sum % K == 0
    vector<long long> total_count = count_sequences_with_mod_sum(n, p, k);

    // Get sequences with only lucky numbers (to ensure at least one lucky element)
    vector<long long> lucky_count = count_sequences_with_mod_sum(n, m, k);

    // Get sequences with no lucky numbers
    vector<long long> non_lucky_count_seq = count_sequences_with_mod_sum(n, non_lucky_count, k);

    // Extract the number of valid sequences (sum % K == 0)
    long long total_sequences = total_count[0];
    long long excluded_sequences = non_lucky_count_seq[0];

    // Calculate valid sequences with at least one lucky number
    long long valid_sequences = (total_sequences - excluded_sequences + MOD) % MOD;

    return valid_sequences;
}

int main() {
    int n, p, k, m;
    cin >> n >> p >> k >> m;

    set<int> lucky_numbers;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        lucky_numbers.insert(num);
    }

    // Compute and print the result
    cout << count_sequences(n, p, k, lucky_numbers) << endl;

    return 0;
}



