


//this is also sequential container, and  associated with DOUBLY  LINKED LIST

#include <iostream>
using namespace std;
#include <list>  //for making list


// In list, we can pop + push from front and back -- we have EMPLACE front/back

//all these funct:  size, erase, clear, begin, end, rbegin, rend, insert, front, back --- all apply in list also as we read in vector



int main() {

    list<int> myList;
    list<int> l2 = {1, 2, 3, 4, 5};

    myList.emplace_back(1);    //emplace_back  ya push_back, dono same ans deta h
    myList.push_back(2);

    myList.push_front(3);
    myList.push_front(5);

    myList.pop_back();
    myList.pop_front();


    //randon access the index in List is not possible
    //cout << myList[2] << endl;



    //printing list
    for(int val : l2) {
        cout << val << " ";
    }
    cout << endl;







    return 0;
}




