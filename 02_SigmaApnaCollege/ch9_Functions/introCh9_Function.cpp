git commit -m "feat(sigmaApnaCollege): started newChapter Function from today (ch9)"

/*

5th May 2026 (Tuesday) Intro to function

WHY funct ?
jab hm bachapan mai Ramamyan serial dekhte the waha pe directory bigMovies ko chunk of episodes mai break karke dekhate the
similary when our codebase is going to increase to understanding ke liye we have to break


definition: Block of code which runs when it is called




void primitive data type in c++
oid is a primitive (built-in) data type that represents a valueless entity or the absence of a value. Because it denotes nothingness, you cannot declare a variable of type void

https://image.pi7.org/join-images-online  and https://pinetools.com/merge-images


returnType of function: int, char, bool, void

shardhaDi boli - koi function kisi to bhi call kar sakti hai aur jistni baar, if call itself that is called RECURSION which we'll learn in upcoming chapter 

*/

void printMessage() {
    std::cout << "Hello, World!";
}



//syntax
returnType fName() {

    //do somework
    return someValue;  //optional 
}
fName();  //function call


#include <iostream>
using namespace std;

void sayHello() {
    cout << "Hello \n";
}

void assistant() {
    sayHello();
    cout << "Work done \n";
}


int main() {
    //sayHello();

    assistant();  //function call
   

    return 0;
}