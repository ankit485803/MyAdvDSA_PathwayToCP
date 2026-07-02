

/*
Problem Statement 
You have a sequence of N integers. Find the maximum length of a subsequence that:
Can be reversed to form a palindrome (i.e., the subsequence itself is a palindrome)
The sum of all elements in the subsequence is even



approach:
count frequency of each number
total_pairs = sum(freq/2) for all values
answer = 2 * total_pairs
if any even number has odd frequency:
    answer += 1


*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    unordered_map<long long, int> freq;
    long long num;
    
    for (int i = 0; i < N; i++) {
        cin >> num;
        freq[num]++;
    }
    
    long long total_pairs = 0;
    bool has_even_odd = false;
    
    for (auto& p : freq) {
        total_pairs += p.second / 2;
        if (p.second % 2 == 1 && p.first % 2 == 0) {
            has_even_odd = true;
        }
    }
    
    long long answer = 2 * total_pairs;
    if (has_even_odd) {
        answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}