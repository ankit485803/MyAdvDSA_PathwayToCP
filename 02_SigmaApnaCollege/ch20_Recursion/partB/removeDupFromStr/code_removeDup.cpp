

/*

Remove duplicate character from string
approach1: using recursion 

approach2: using Hashing -- will read in upcoming chap


*/


#include <iostream>
#include <string>
using namespace std;



void remmoveDuplicate(string str, string ans, int i, int map[26]) {
    if(i == str.size()) {
        cout << "ans : " << ans << endl;
        return;
    }

    char ch = str[i];
    int mapIdx = (int)(ch - 'a');

    if(map[mapIdx] == true) {  //duplicate case
        remmoveDuplicate(str, ans, i+1, map);
    } else {  //not duplicate
        map[mapIdx] = true;
        remmoveDuplicate(str, ans+str[i], i+1, map);
    }
}



int main() {
    string str = "appnnacollege";
    string ans = ""; //initialize  with emptyStr
    int map[26] = {false};  //pahle fill with false value

    remmoveDuplicate(str, ans, 0, map);  //ans: apncoleg

    return 0;
}



//without i ke hm funct likhte hai -- esmai str ke last charater se remove karna start karenge
void remmoveDuplicate(string str, string ans, int map[26]) {
    if(str.size() == 0) {
        cout << "ans : " << ans << endl;
        return;
    }


    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int)(str[n-1] - 'a');
    str = str.substr(0, n-1);

    if(map[mapIdx] == true) {  //duplicate case
        remmoveDuplicate(str, ans, map);
    } else {  //not duplicate
        map[mapIdx] = true;
        remmoveDuplicate(str, ch+ans, map);
    }
}

int main() {
    string str = "appnnacollege";   //output: yag last se push into ans--  pnacolge
    string ans = ""; 
    int map[26] = {false}; 

    remmoveDuplicate(str, ans, map);

    return 0;
}
