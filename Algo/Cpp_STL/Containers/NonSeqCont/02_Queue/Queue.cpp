

#include <iostream>
using namespace std;
#include <queue>


/* Queue = jo pahale aaya wah pahle gayega- schooling time assembly mai line lagana, FIFO (first in first out)

esmai INSERT elem = BACK se hote h, and DELETE = FRONT se hote h




some funct used in stack:  

synatx = queue<int> myQueue;
1. push, emplace
2. front
3. pop 
4. size
5. empty
6. swap



*/



int main() {

    queue<int> q;

    q.push(1);
    q.push(2); 
    q.push(3);


    while(! q.empty() ) {
        cout << q.front() << " ";
        q.pop();  //from front se khali hoga, we need to delete because infinite loop mai fas jayega
    }


    return 0;
}