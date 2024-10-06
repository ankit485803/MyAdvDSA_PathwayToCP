
// Pass by reference concept in a array

//array is a non-primitive data structure
#include <iostream>  
using namespace std;  


void changeArr(int arr[], int size) {
    for(int i=0; i<size; i++) {
        arr[i] = 2* arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3};

    changeArr(arr, 3);
    
    cout << "In Main \n";
    for(int i=0; i<3; i++) {   // 2 4 6
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
