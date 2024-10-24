

#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>



int main() {

    vector<int> vec = {1, 2, 3, 4, 5};

    //reverse(vec.begin(), vec.end());
    
    reverse(vec.begin()+1, vec.begin()+3);   //reverse the range of vec
     


    for(auto val : vec) {
        cout << val << " ";
    }
    cout << endl;




    return 0;
}