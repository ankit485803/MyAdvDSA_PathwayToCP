

#include <iostream>
using namespace std;
#include <map>
#include <unordered_map>
 


/*  Unordered map:  jada use karte h DSA mai

it stores the data in random order and any elem can print any times,  can't duplicate value

recap on 9th Nov 2025 (Sunday) C:\Users\sanja\Desktop\GitProj\MyAdvDSA_PathwayToCP\0_Arjuna_CP\D41_Onward_Sem5\q30_countKdiff.cpp 
very imp prop of unordered_map() jo kabhi bhi duplicateValue nahi rakhta hai Bhai okkk



*/


int main() {

     

    unordered_multimap<string, int> m;

    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("laptop", 100);
    m.emplace("tv", 100);



    
    for(auto p : m) {
        cout << p.first << " " << p.second << endl;
    }


    return 0;
}



/* we use frequently unordered map +  map  function

in undered_map :  insert, erase, count --- O(1) , if collosion occur in map then O(n)
in map :  insert, erase, count --- O(log(n)) ---   self balancing tree

*/