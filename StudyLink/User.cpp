#include "User.h"

#include <string>

User::User(string name, string number) {
  //ctor
  this->name = name;
  this->number = number;
  for (int i = 0; i < MAX_SLEEP_RECORDS; i++) {
    sleepHours[i] = -1.0;
  }
}

User::~User() {
    cout <<"Deleted" <<endl;
}




void User::sleepRecorder(double hours, int day) {
  sleepHours[day] = hours;

}
string User::getname() {
  return(name);
}

void User::print() {
  double sum = 0;
  cout << "Name of the user:" << User::getname() <<" has a number:" <<number <<endl;
  for (int i = 0; i < MAX_SLEEP_RECORDS; i++) {
    cout << "Hours of Sleep " << sleepHours[i] <<endl;
    sum += sleepHours[i];

  }
  cout << "Average hours of Sleep " << sum/MAX_SLEEP_RECORDS <<endl;
}
