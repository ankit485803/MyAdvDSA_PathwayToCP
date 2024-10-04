
#include <iostream>  
using namespace std;  


//Linear search, time complexity = O(n)  but Binary search -- O(log(n))
int LinearSearch(int arr[], int size, int target) {
    for(int i=0; i<size; i++) {
        if(arr[i] == target) {  //found
            return i;
        }
    }
    return -1;  //not found
}



int main() {

    // Linear-Search
    int arr[] = {14, 15, 6, 7, 95, 3};
    int size = 6;
    int target = 95;

    cout << LinearSearch(arr, size, target) << endl;

    return 0;

}




