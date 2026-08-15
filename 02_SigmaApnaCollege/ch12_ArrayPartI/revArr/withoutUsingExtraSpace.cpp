

/*

Yes. hm  reverse kar sakte hai array without any extra array, using the two-pointer and swapping approach.


*/

#include <iostream>
using namespace std;


void revArrOptimized_twoPtrAndSwapping(int arr[], int n) { //tc=O(n), sc=O(1)
    int st = 0, end = n-1;

    while(st < end) {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
}


int main() {
    int arr[] = {5, 4, 3, 9, 2};
    int n = sizeof(arr) / sizeof(int);

    revArrOptimized_twoPtrAndSwapping(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



//on vector 
#include <iostream>
#include <vector>
using namespace std;

void revArr(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        swap(arr[start], arr[end]);

        start++;
        end--;
    }
}

int main() {
    vector<int> arr = {5, 4, 3, 9, 2};

    revArr(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


//SWAPPING using the temp variable 
void revArr(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}



git commit -m "feat(sigmaApnaCollege): covered LinearSearch and revArr withExtra, without extraSpace (ch12 arrPart I)" 