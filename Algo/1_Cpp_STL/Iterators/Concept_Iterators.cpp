

#include <iostream>
using namespace std;
#include <vector>

/* two iterators 


1. vec.begin() 
2.  vec.end()   : this not point last elem, be alert ankit it give  (last + 1)  here may be garbage value, when we derefernce * 
output may be 1 or 0 depond upon the compile



we use the iterator mostly applying loop on vector

dereference the vector usig symbol:  *(myVec.begin(1))
*/


int main() {

    vector<int> myVec = {1, 2, 3, 4, 5}; 

    vector<int>:: iterator it; 

    //loop on vec -- FORWARD
    for(it = myVec.begin(); it != myVec.end(); it++) {   //dirctly access the memeory location using iterators
        cout << *(it) << " ";
    }
    cout << endl;





    // Declare the reverse iterator
    vector<int>::reverse_iterator rit;

    // BACKEWARD
    cout << "Backward iteration: ";

    for(rit = myVec.rbegin(); rit != myVec.rend(); rit++) {
        cout << *(rit) << " "; // Dereferencing the reverse iterator to access the value
    }
    cout << endl;


    //dangrous for loop ban jata when combine so use AUTO
    // for(auto rit = myVec.begin(); rit != myVec.end(); rit++) {
    //     cout << *(rit) << " ";
    // }
    // cout << endl;


    
    //cout << "vec.begin = " << *(myVec.begin())  << endl;  //dereferecing 
    //cout << "vec.end = " << *(myVec.end())  << endl;  //give output garbage



    return 0;
}




//shardha didi boli jab waah microsoftware mai project par kam kar rahi thi Operating system mai waha c++ mai
// more useful this concept, practically in org