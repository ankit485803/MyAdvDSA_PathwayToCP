
git commit -m "feat(sigmaApnaCollege): start newChap (ch17_vectors)" 

/*

5th Oct 2026 (Monday)

Dynamic Memory Allocation: runtime pe size dente hai in HEAP
where static: mai fixed hota hai compile time pe hota hai

NEW keyword mai mandatory hai DELETE keyword ka otherwise MEMORY LEAK hoga


*/

#include <iostream>
#include <vector>
using namespace std;


void funcInt() {
    int *ptr = new int;
    *ptr = 5;

    cout << *ptr;

    delete ptr;   //yah req hai nahi to MEMORY LEAK hoga
}


void funcArr() {
    int size;
    cin >> size;

    int *ptr = new int[size];

    int x = 1;
    for(int i=0; i<size; i++) {
        arr[i] = x;
        cout << arr[i] << " ";
        x++
    }
    cout << endl;

}


int main() {
    int arr[100] = {1, 2, 3, 4, 5};  //static memory

    //call func
    funcArr();

    return 0;
}