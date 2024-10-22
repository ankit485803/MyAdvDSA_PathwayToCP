
#include <iostream>
using namespace std;
#include <stack>

/* Stack = Last in first out (LIFO) data structure

in stack- elem remove and add only from top 


some funct used in stack:  

synatx = stack<int> myStack;
1. push, emplace
2. top
3. pop (delete)
4. size
5. empty
6. swap



e.g.  jaise Ankit tumari mummy roti banate ho aur rakhte ho waah ek best eg hai stack ka
*/


int main() {

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    
    stack<int> s2;

    s2.swap(s);

    //cout << "top elem of stack = " << s.top() << endl;



    while(! s.empty() ) {  //till stack become empty
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    cout << "size of s = " << s.size() << endl;  //0
    cout << "size of s2 = " << s2.size() << endl; ///3
    


    return 0;
}