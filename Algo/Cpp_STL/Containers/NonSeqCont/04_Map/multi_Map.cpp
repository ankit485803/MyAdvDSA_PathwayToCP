

#include <iostream>
using namespace std;
#include <map>


/* In multi-map : we can store the multiple value


yaha aap duplicate key create kar sakte h, can't use SQUARE-BRACKET notation  i.e.  m.insert 
sirf use karo m.emplace



*/


int main() {

    //map<string, int> m;   //yah only time print karega map, but multimap jitna rahega utna

    multimap<string, int> m;

    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);


    //m.erase("tv");  //delete all elem

    //delete specific elem
    m.erase(m.find("tv"));

    
    for(auto p : m) {
        cout << p.first << " " << p.second << endl;
    }


    return 0;
}