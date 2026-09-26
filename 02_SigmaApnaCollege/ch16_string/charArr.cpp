

/*

26th Sep 2026 (Saturday)

char arrays: bhi work same like int array works, can store string using double colon "str"

eg: "hello", "apna college", "hi hello wold"

in c++ explicitly terminated by null character '\0'



*/

#include <iostream>
using namespace std;
#include <cstring> //for using strlen() funct

int main() {
    char ch[5] = {'a', 'b', 'c', 'd', 'e'};
    char ch1[5] = {'c', 'o', 'd', 'e', '\0'};

    cout << ch1 << endl;
    "apna college" //yah string literals hai esko hmko \0 se end nahi karna hota hai
    "helloworld"
    "a"  //str literals

    return 0;
}



//creation & output
int main() {
    //1st ways: Size automatically determined
    char work[] = "code";  //esmail size defined karne ki required nahi hai automatic right side le leta  hai
    cout << work << endl;

    //2nd ways: Give the size explicitly
    char work1[10] = "code";  //minSize = 5 or more chalega
    cout << work1 << endl;

    //3rd ways: Initialize character-by-character
    char work2[] = {'c', 'o', 'd', 'e', '\0'};
    cout << work2 << endl;

    //4th ways: character-by-character + fixed size
    char work3[50] = {'c', 'o', 'd', 'e', '\0'};
    cout << work3 << endl;


    cout << strlen(work3) << endl;

    return 0;
}