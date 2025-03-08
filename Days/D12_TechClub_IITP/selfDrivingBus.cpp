


/*    https://www.hackerrank.com/contests/algorage-iitp/challenges/self-driving-bus



Problem:
You are a waiter at a party. There is a stack of plates, each with a number on it. You are given a list of numbers (representing the plates), and a list of prime numbers. For each prime, you will check if the plates are divisible by that prime number.

If a plate is divisible by the prime, put it in a "pile."
If a plate is not divisible by the prime, keep it in the "stack."
After each round (for each prime), move the plates in the pile to the result, and the remaining plates (in the stack) go to the next round.

Repeat this process for a given number of primes, and after all rounds, return the list of remaining plates in the order they were processed.

Function Description:
You need to implement a function waiter that takes two inputs:

number: An array of integers representing the numbers on the plates.
q: The number of prime numbers you will use for dividing the plates.
After the processing, return the final list of plates after all rounds, with the plates stacked and ordered as required.

Input:
The first line contains two integers: n (number of plates) and q (number of prime numbers).
The second line contains n space-separated integers, which are the numbers on the plates.
Output:
After processing, return a list of integers representing the final arrangement of the plates.




*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY tree as parameter.
 */

int solve(vector<vector<int>> tree) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> tree(n - 1);

    for (int i = 0; i < n - 1; i++) {
        tree[i].resize(2);

        string tree_row_temp_temp;
        getline(cin, tree_row_temp_temp);

        vector<string> tree_row_temp = split(rtrim(tree_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int tree_row_item = stoi(tree_row_temp[j]);

            tree[i][j] = tree_row_item;
        }
    }

    int result = solve(tree);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
