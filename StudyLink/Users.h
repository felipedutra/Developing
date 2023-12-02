#ifndef USERS_H
#define USERS_H
#include <string>
#include <iostream>
#include "User.h"


using namespace std;
class Users {
    public:
      Users(string name);
      virtual ~Users();
      string getname();
      string getnumber();
      User** getUsers();
      User* getuser(string name,string number, string password);
      void addUser(User *u);
      void print();

    private:
      string name;
      string number;
      User** users;
      int userCount;
      string password;

};
#endif // User_H
