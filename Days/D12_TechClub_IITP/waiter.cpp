


/*  https://www.hackerrank.com/contests/algorage-iitp/challenges/waiter




problem Overview:
You are a waiter at a party and you have a pile of plates. Each plate has a number on it. You need to process these plates by checking if the number on each plate is divisible by a prime number. If a plate number is divisible by a given prime number, move it to a separate "pile". Otherwise, keep it in a "stack". You need to perform this operation multiple times, based on a list of prime numbers, and at the end return the final order of the plates.

Task:
Initial setup:
Plates are given in a list, and you need to check if they are divisible by a given prime number.
If a plate number is divisible by the current prime, move it to the "pile".
If a plate number is not divisible, move it to the "stack".
Repetition:
For each prime number in the list, repeat the process using the current stack of plates from the previous iteration.
Result:
After processing all the primes, move the remaining plates (from the "stack") to the final result list in the order they were processed.
Return the final order of plates after all operations.
Function Description:
You need to implement the function waiter which takes the following inputs:

number: A list of integers representing the plates' numbers.
q: The number of primes you need to process.
The function should return the final list of plates' numbers after processing all the primes.

Input Format:
The first line contains two space-separated integers:
n (the number of plates)
q (the number of primes).
The second line contains n space-separated integers representing the numbers on the plates.
Output Format:
The function should return a list of integers which represent the final arrangement of the plates after all the operations.


*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector<int> waiter(vector<int> number, int q) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
