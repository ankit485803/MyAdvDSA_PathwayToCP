

/*

#Static Keyword

Static Variables
Variables declared as static in a function are created and initialised once for the lifetime of the program. //in Function

Static variables in a class are created and initialised once. They are shared by all the objects of the class. //in Class

Static Objects


*/

#include <iostream>
#include <string>
using namespace std;


void counter() {
    static int count = 0;
    count++;
    cout << "count : " << count << endl;
}


int main() {
    counter();
    counter();
    counter();

    return 0;
}


//eg2
class Example {
public:
    static int x = 0;
};


int main() {
    Example eg1;
    Example eg2;
    Example eg3;

    cout << eg1.x++ << endl;
    cout << eg2.x++ << endl;
    cout << eg3.x++ << endl;

    cout << "cod ending..\n";

    return 0;
}



//eg3 to see show work static
class Example {
public:
    Example() {
        cout << "constructor se create hoga..\n";
    }

    ~Example() {
        cout << "destructor se destroy or delete hoga..\n";
    }
};


int main() {
    int a = 0;
    if(a == 0) {
        static Example eg1;
    }

    cout << "code ending..\n";
}   