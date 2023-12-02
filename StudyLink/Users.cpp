#include "Users.h"
#include <string>
#define MAXVAL 10
Users::Users(string name) {
    users = new User* [MAXVAL];
}


Users::~Users() {

}
User** Users::getUsers() {
  return (users);
}
User* Users::getuser(string name,string number, string password) {
  return(users[0]);
}

void Users::print() {

}
void Users::addUser(User *u) {
  users[userCount] = u;
  userCount++;

}
