

/*

concepts:

size v/s capacity of vector: capacity increase like array jo twice mai hota hai but not size

*/

#include <iostream>
#include <vector>
using namespace std;



int main() {
    vector<int> vec;

    for(int i=0; i<5; i++) {
        vec.push_back(i);
    }

    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    

    return 0;
}