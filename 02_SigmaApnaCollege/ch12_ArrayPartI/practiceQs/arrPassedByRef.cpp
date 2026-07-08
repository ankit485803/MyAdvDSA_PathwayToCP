

/*

concepts:
1.2 In c++ arrayName ko internally convert into  POINTE


*/


#include <iostream>
using namespace std;


void func(int arr[]) {  //array ko as an arguments
    arr[0] = 1000;
}

void func2(int *ptr) {  //as a pointer array ko jab lete hai
    ptr[0] = 1000;
}


int main() {
    int a = 5;
    int *ptr = &a;
    cout << ptr << endl;   // 0x...

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << *arr << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr + 2) << endl;

    //passing Array name is equivalent to the passing the pointer
    func(arr);
    cout << arr[0] << endl;

    func2(arr);
    cout << arr[0] << endl;

    return 0;
}



git commit -m "feat(sigmaApnaCollege): covered output & input arr, arr passed by ref, and solved one Ques find largestElem in arr (ch12)" 