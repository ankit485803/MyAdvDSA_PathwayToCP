


// https://www.hackerrank.com/algorage-iitp



//qno 4 https://www.hackerrank.com/contests/algorage-iitp/challenges/pair-sums



#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestValue' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY A as parameter.
 */





long largestValue(vector<int> A) {
    int n = A.size();
    long max_value = LLONG_MIN;

    // Iterate over all possible subarrays
    for (int start = 0; start < n; ++start) {
        for (int end = start; end < n; ++end) {
            // Compute the sum of the pairwise products for subarray A[start..end]
            long sum = 0;
            for (int i = start; i <= end; ++i) {
                for (int j = i + 1; j <= end; ++j) {
                    sum += A[i] * A[j];
                }
            }
            max_value = max(max_value, sum);
        }
    }
    
    return max_value;
}








int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    long result = largestValue(A);

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
