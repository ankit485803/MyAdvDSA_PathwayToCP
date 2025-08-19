


#include <iostream>
using namespace std;
#include <string>



/*


19th Aug 2025 (Tuesday - Sem5 starts) Static keywords - freq used

Two ways to uses:
    object



   deep concept: friend funct and friend class 

   OOPS MCQ HW: https://drive.google.com/file/d/1-fSUUeI02QdHv5x7SJWVtrMId9BEeYXw/view

*/


class ABC {
public: 
    ABC() {
        cout << "Constructor bhai \n";
    }

    ~ABC() {
        cout << "Destructor okk \n";
    }

};



int main() {
   
    if(true) {
        //ABC obj;

        static ABC obj;
    }

    cout << "End of main funct Bhai \n";


    return 0;
}