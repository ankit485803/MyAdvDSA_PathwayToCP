

#include <iostream>
using namespace std;
#include <set>

#include <unordered_set>


/* Set : is very similar to maths set, having all elem UNIQUE value + SORTED order

syntax:  set<int> s;



some operations:    similar work link map funct -- all operating on O(log(n))
1.  insert, emplace
2. count
3. erase
4. find
5.  size, empty, erase



6. lower_bound and upper_bound  :  this funct return iterators if elem present otherwise retunrn  s.end()  value dega
yah just usse bara elem deta h



*/


int main() {

    //set<int> s;

    multiset<int> s;
    // unordered_set <int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);  //see set always make in SORTED order while creating i give unsorted but set make it sorted automatic
    
    s.insert(1);
    s.insert(2);



    


    //duplicate val can't allowed in set, and size reamin same
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);




    //printing val
    for(int val : s) {
        cout << val << " ";
    }
    cout << endl;


    cout << "size of set = " << s.size() << endl;

    //cout << "lowet bound = " << *(s.lower_bound(5)) << endl;  // if not present s.end()



    return 0;
}


/*
Lower bound('b') : should not be less than by
upper bound('b) : greater than

1. multi set

2.  unordered set -- TC = O(1)  foe this data str lower bound and upper bound concept not exist because data is un-sorted

*/