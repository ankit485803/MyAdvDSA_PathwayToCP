

/*

8th July 2026 (Wednesday)

output & input array


*/

#include <iostream>
using namespace std;


int main() {
    int arr[5] = {7, 5, 2, 1, 3};  //arr marks

    int len = sizeof(arr) / sizeof(int);

    for(int idx = 0; idx <= len - 1; idx++) {  //idx = 0, 1, 2, 3, 4
        cout << arr[idx] << " ";
    }
    cout << endl;

    //eg2 input
    int marks[5];
    int n = sizeof(marks) / sizeof(int);

    for(int i = 0; i < n; i++) {  //taking user's marks input
        cin >> marks[i];
    }
    cout << endl;

    cout << "Marks = { ";  //printing output
    for(int i=0; i<n; i++) {
        cout << marks[i] << ",";
    }
    cout << "}" << endl;

    return 0;
}