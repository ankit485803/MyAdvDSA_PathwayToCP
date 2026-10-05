
git commit -m "feat(sigmaApnaCollege): start newChap and cover static v/s dynamic memory allocation, memoryLeak prob (ch17_vectors)" 

/*

MemoryLeak: occurs when programmers create a memory in a HEAP, and forgot to DELETE it.
It lead to reduced the performance due to deletion of available memory 



*/

#include <iostream>
using namespace std;


int* funct() {
    int *ptr = new int;
    *ptr = 1200;
    cout << "ptr points to " << *ptr << endl;

    return ptr;

}


int main() {

    int *x = funct();
    cout << *x << endl;

    return 0;
}