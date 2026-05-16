#ifndef PASSWORD_CLASS_H
#define PASSWORD_CLASS_H
#include <string>
#include "authentication.h"
#include "database.h"
using namespace std;

class password_class
{
public:
    string app_name;
    string user_name;
    string password;
    password_class();
    password_class(string app_name, string user_name, string password);

    string showAppName();
    string showUsername();
    string showPassword();
    void insertApp(database datab, authentication user, string app_name, string user_name, string password);
    void updateUsername(string user_name);
    void updatePassword(string password);
    void passwordEncryption(string password);
};
#endif