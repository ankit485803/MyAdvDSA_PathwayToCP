

//recap again on 17th Oct 2025 (Friday - winter Spring Sem5  IITP 3rd year after ISRO Meghalaya Dehradun)

#include <iostream>
using namespace std;
#include <map>

/* Map (key, value)

it is used to store the (key, value) pair. and cam visualize like table. Key is UNIQUE , eg. student roll no in school, employee id in company
map : yah hmesa pront hoga sorted order mai, ascending order accord to key





syntax:  map<string, int> m;

m[key] = value;

some operations:
1. insert, emplace
2. count
3. erase
4. find  - if found then return iterators,  not found then return  m.end()  jo last value hai

5. size, empty, erase




*/


int main() {

    map<string, int> m;

    m["tv"] = 100;
    m["laptop"] = 70;
    m["headphone"] = 50;
    m["tablet"] = 20;  //yah hmesa pront hoga sorted order mai, ascending order accord to key
    m["watch"] = 50;


    m.insert({"camera", 25});
    m.emplace("apple", 25);   //no need to make obj in emplace

    m.erase("tv");

    for(auto myPair : m) {
        cout << myPair.first << " " << myPair.second << endl;
    }


    cout << "count of laptop = " << m.count("laptop") << endl;
    cout << "corrosponding value laptop key = " << m["laptop"] << endl;


    //find
    if(m.find("camera")  !=  m.end()) {
        cout << "found \n";
    } else {
        cout << "not found \n" ;
    }


    return 0;
}