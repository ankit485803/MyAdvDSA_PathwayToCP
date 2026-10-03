

/*

3rd Oct 2026 (Saturday)

Member Functions in string c++
(1) str.length()
(2) str.at(idx)
(3) str.substr(startIdx, size)
(4) str.find(word)


substring and subarray


*/


#include <iostream>
#include <string>
using namespace std;


int main() {
    string str = "apna college!";

    cout << str.length() << endl;
    cout << str[3] << endl;
    cout << str.at[3] << endl;

    return 0;
}



//substring print
int main() {
    string str = "helloworld";

    cout << str.substr(1, 5) << endl;  //2nd idx se new substr print kar do

    return 0;
}

//find word
int main() {
    string str = "I love coding in c++ and Java. I don't like in Python";

    cout << str.find("c++") << endl;  //first occurrence ko print karta hai

    string str1 = "I love coding in c++ and c++. I don't like in c++"
    cout << str.find("c++", 20) << endl;  //hm 20 idx ke baad ko search karte hai
    cout << str.find("python")  //return unsigned value

    int idx = str.find("python");
    cout << idx << endl;  //-1 answer


    return 0;
}