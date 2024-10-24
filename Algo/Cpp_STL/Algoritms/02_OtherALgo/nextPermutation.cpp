

#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>


// next perm in Lexicography order mai hota h dictornary


int main() {

    string s = "abc";

    //next_permutation(s.begin(), s.end());

    prev_permutation(s.begin(), s.end());

    cout << s << endl;


    //MAX-MIN ,  SWAP
    cout << max(4, 5) << " " << min(6, 10) << endl;

    int a = 5, b = 10;
    swap(a, b);
    cout << "a = " << a << endl;

    //max-min elem from vect, this return index
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << *(max_element(vec.begin(), vec.end())) << endl;  //be alert ankit deReference the elem using *





    return 0;
}