

#include <iostream>
using namespace std;
#include <vector>

/*

Function overloading: is eg of compile type polmorisms, static,  two fuction ka name same but parameters diff hona chahiye
ok

*/


class myPrint {
public:
    void show(int x) {
        cout << "integer : " << x << endl;
        
    }


    void show(char ch) {
        cout << "character : " << ch << endl;

    }


};






int main() {

    myPrint p1;
    p1.show(101);  //compile type pe hi detect ho jayega
    
    myPrint p2;
    p2.show('&');  //depend on context 

    return 0;
}