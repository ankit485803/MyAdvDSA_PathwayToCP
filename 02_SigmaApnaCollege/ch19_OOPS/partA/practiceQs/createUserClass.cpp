


/*

Create a User class with properties: id (private), username (public) & password (private).

Its id should be initialized in a parameterized constructor.

It should have a Getter & Setter for password.




*/


#include <iostream>
#include <string>
using namespace std;


class User {
private:
    int id;
    string password;

public:
    string username;

    User(int id) {
        this->id = id;  //left wala object ki id hoga hai right wala parameter ki CONSTRUCTOR
    }

    //getter
    string getPassword() {
        return password;
    }

    //setter
    void setPassword(string password) {
        this->password = password;
    }

};

int main() {
    User user1(101);
    user1.username = "apnacollege";
    user1.setPassword("abcd");

    cout << "username : " << user1.username << endl;
    cout << "password : " << user1.getPassword() << endl;

    return 0;
}