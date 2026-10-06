

/*

6th Oct 2026 (Tuesday) Vector is also called Sequence Container 

Vector mai hmko manually memory ko allocate or delete karne ki jarurt nahi hoti hai like static array because
this follow dynamic memory allocation

constructor: is a function jisko use karte hai kisi Object ko initialize karne ke liye


vec.size(): no of elem present in vect
vec.capacity(): max no of elem can vect hold, yah doubling mai increase hota hai
*/


#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> vec1 = {1, 2, 3, 4};
    cout << "size = " << vec1.size() << "\n";
    cout << "capacity = " << vec1.capacity() << "\n";

    vec1.push_back(2)
    vec1.pop_back(2);

    vector<int> vec2(10, -1);  //fill constructor ke method se vector create with initialize with -1
    cout << "size = " << vec2.size() << "\n";

    for(int i=0; i<vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;


    return 0;
}