#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int inv_count = 0;

    // Merge the two halves while counting inversions
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            inv_count += (mid - i + 1);  // Count inversions
            j++;
        }
    }

    // Copy remaining elements from the left half
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from the right half
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy the merged elements back to the original array
    for(int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }

    return inv_count;
}

int mergeSortAndCount(vector<int>& arr, int st, int end) {
    int inv_count = 0;
    if(st < end) {
        int mid = st + (end - st) / 2;

        inv_count += mergeSortAndCount(arr, st, mid);   // Count inversions in left half
        inv_count += mergeSortAndCount(arr, mid + 1, end); // Count inversions in right half

        inv_count += merge(arr, st, mid, end); // Count inversions during merge
    }
    return inv_count;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();
    
    int inversion_count = mergeSortAndCount(arr, 0, n - 1);
    cout << "Number of inversions: " << inversion_count << endl;
    
    return 0;
}
