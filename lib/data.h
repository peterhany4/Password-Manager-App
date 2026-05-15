#ifndef DATA_H
#define DATA_H
#include <string>
using namespace std;

class data
{
private:
    string app_name;
    string user_name;
    string password;

public:
    data();
    data(string app_name, string user_name, string password);

    string showAppName();
    string showUsername();
    string showPassword();
    void insertAppName(string app_name);
    void insertUsername(string user_name);
    void insertPassword(string password);
    void updateUsername(string user_name);
    void updatePassword(string password);
    void passwordEncryption(string password);
};
#endif