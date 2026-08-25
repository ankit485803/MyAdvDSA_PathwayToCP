void printAllPossibleSubarr(int arr[], int n)
void printAllPossibleSubarr(int *arr[], int n)

int arr[]      → array of int       → int*
int *arr[]     → array of int*      → int**


/*

25th Aug 2026 (Tuesday)

print the possible subarr of given arr[] = {2, 3, 6, -5, 4};


*/

#include <iostream>
using namespace std;

void printAllPossibleSubarr(int arr[], int n) {
    for(int st = 0; st < n; st++) {
        for(int end = st; end < n; end++) {
            
            //printingConditions
            for(int i = st; i <= n; i++) {
                cout << arr[i];
            }
            cout << ", ";
        }
        cout << endl;
    }
}



int main() {
    int arr[] = {2, 3, 6, -5, 4};
    int n = sizeof(arr) / sizeof(int);

    cout << "original arr: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    cout << "Possible subarr are: \n";
    printAllPossibleSubarr(arr, n);


    return 0;
}



//complete
#include <iostream>
using namespace std;

void printAllPossibleSubarr(int arr[], int n) {

    for(int start = 0; start < n; start++) {

        for(int end = start; end < n; end++) {

            for(int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
}

int main() {
    int arr[] = {2, 3, 6, -5, 4};
    int n = sizeof(arr) / sizeof(int);

    cout << "original arr: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    printAllPossibleSubarr(arr, n);

    return 0;
}


git commit -m "feat(sigmaApnaCollege): learn printing subarr from scratch and dryRun (ch13 arrPart II)" 