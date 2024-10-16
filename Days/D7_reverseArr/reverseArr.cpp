

// this is HackerRank ques  https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

//reverse the given arr NOTE: The syntax arr[ : -1] resembles slicing from Python, but it's not valid C++ syntax. 
//In C++, you can't directly slice arrays like that. 
//Instead, you'll need to use a loop or a library function to achieve similar functionality.





//method1: using iteration - O(n)
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
 

 
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {    //time complex = O(n) 
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



//method2: using STL (standard library) of c++ that is build in funct  #include <algorithm> // for std::reverse

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::reverse(arr, arr + size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



// hacker rank solutin

vector<int> reverseArray(vector<int> a) {
    // Use reverse iterators to create a reversed copy of the array
    vector<int> reversed(a.rbegin(), a.rend());
    return reversed;  // Return the reversed array
}

/*
 * Complete the 'reverseArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */



#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'reverseArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<int> reverseArray(vector<int> a) {
    // Use reverse iterators to create a reversed copy of the array
    vector<int> reversedMyArr(a.rbegin(), a.rend());
    return reversedMyArr;  // Return the reversed array
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    vector<int> res = reverseArray(arr);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];
        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
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
