

#include <iostream>
using namespace std;


/*

23rd July 2025 (Wednesday) Bitwise operator in cpp and its application on solving the prob - sum of two numb without mathematical
operator like + and -


Bitwise AND:  &   yah kam karta hai jab dono one ho fir one dega and vice versa for OR
Bitwise OR : |
Bitwise NOT:  ~
Bitwise XOR: ^    yah jab same ho to one dega 
Bitwise left shift: << and RIGHT: >>

precedence: ~ (highest NOT), << >>,  &, ^,  | (lowest hai OR ki precedence)

concept recap by Gate Samasher youtube https://youtu.be/Yk3Jwm5YuFs?si=Ss6KQYvh40lbmxf_

hm negative numb ko represent nahi karte h compter mai two compement mai Bitwise NOT operator
Bitwise left shift ko bolte h Multiply by 2 and vice vesa for RIGHT
jab same precedence ho to, then we Associtiy Left to right direction mai kar sakte ho app



Topic: Bitmanipulation 
*/



int sum_Direct(int a, int b) {  //valid only for positive
    for(int i=1; i<=b; i++) {
        a++;  //post increment or we can we ++a  also pre-increament
      
    }
    return a;
}




int sum_Bitmanipulaton(int a, int b) {  //can handle both postive and negative no
  while(b != 0) {
    int carry = a & b;
    a =  a^b;  //jo khali hai nahi raho sirf value wala XOR
    b = carry << 1;  //left shift
  }

  return a;
}




int main() {
    int x = 5, y = 3;

    cout << "Sum using loop: " << sum_Direct(x, y) << endl;
    cout << "Sum using bit manipulation: " << sum_Bitmanipulaton(x, y) << endl;

    return 0;
}



// qno 371   https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b) {
        
        //method1: direct, work only when b>0, fail hoga Ankit jab negative number
        // for(int i=1; i<=b; i++) {
        //     a++;
        // }
        // return a;



        //method2: using Bit manipulation operator
        while(b != 0) {
            int carry = a & b;  //naikalo carry AND 
            a = a^b; //sif rahko usko ko jo 1 ho-- use XOR
            b = carry << 1;  //left shift by 1

        }
        return a;
    }

};


// TC = O(n) because loop runs until carry becomes 0
// SC = O(1) only integer variables used