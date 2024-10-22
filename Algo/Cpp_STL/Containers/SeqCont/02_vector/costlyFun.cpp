

#include <iostream>
using namespace std;
#include <vector>


/*  some funct of vector who work TC = O(n) , in funny way we said costly funct

1. erase
2. inset

3. clear: es ye sara vec ek sath delete ho jata h
4. empty


vector.begin()  not pass as index, pass as ITERATOR in earse fun
erse + clear funct: only change the size but not capacity of our vector


*/

int main() {

    //initlize
    vector<int> myVec = {1, 2, 3, 4, 5};    

    //myVec.erase(myVec.begin());   //delete 1st elem  as an iterator
    //myVec.erase(myVec.begin() + 2);   //delete 3rd elem

    //myVec.erase(myVec.begin() + 1, myVec.begin() + 3);   //ek range se delete

    myVec.insert(myVec.begin() + 2, 100);

    // myVec.clear();


    //printing vec
    for(int val : myVec) {
        cout << val << " ";
    }
    cout << endl;



    cout << "size of vec = " << myVec.size() << endl;
    cout << "capacity of vec = " << myVec.capacity() << endl;

    cout << "is empty : " << myVec.empty() << endl;  //if yes, give true 1 otherwise 0 for false


    return 0;
}