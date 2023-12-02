#ifndef USER_H
#define USER_H
#define MAX_SLEEP_RECORDS 10
#include <string>
#include <iostream>



using namespace std;
class User {
    public:
        User (string name,string number);
        void sleepRecorder(double hours, int day);

        virtual ~User();
        string getname();
        void print();
    private:
        string name;
        string number;
        double sleepHours[MAX_SLEEP_RECORDS];


};
#endif // User_H
