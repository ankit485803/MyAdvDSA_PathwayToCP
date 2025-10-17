

// Pair (is a part of c++ utility libray)
 

//recap again on 17th Oct 2025 (Friday - winter Spring Sem5  IITP 3rd year after ISRO Meghalaya Dehradun)

#include <iostream>
using namespace std;
#include <vector>

int main() {

    pair<int, int> myPair = {1, 5};

    pair<string, int> p2 = {" Ankit Kumar ", 56};
    //crate pair of pair
    pair<int, pair<int, char>> p3 = {2, {7, 'a'}};

    //access the val of pair

    cout << myPair.first << endl;
    cout << myPair.second << endl;

    cout << p2.first << endl;
    
    cout << p3.second.first << endl;  //second elem ka first value = 7
    cout << p3.second.second << endl;  //a

    //vector of pair
    vector<pair <int, int>> myV = {{1,2}, {2, 3}, {3, 4}};

    // for(pair<int, int> p : myV) {
    //     cout << p.first << " " << p.second << endl;
    // }

    myV.push_back({4, 5});  //inplace
    myV.emplace_back(4, 5); //in-place object create

   for(auto p : myV) {
    cout << p.first << " " << p.second <<endl;
   }
    
    


    return 0;
}





/*


push_back  -- jada dikhne mileg apko because syntax familiar , but emplace_back is more fast 


*/