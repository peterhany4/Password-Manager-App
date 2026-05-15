#include <iostream>
#include "password_class.h"
#include "authentication.h"
#include "database.h"
using namespace std;

password_class::password_class()
{
    password_class::app_name = "";
    password_class::user_name = "";
    password_class::password = "";
}
password_class::password_class(string app_name, string user_name, string password)
{
    this->app_name = app_name;
    this->user_name = user_name;
    this->password = password;
}

string password_class::showAppName()
{
    return password_class::app_name;
}

string password_class::showUsername()
{
    return password_class::user_name;
}

string password_class::showPassword()
{
    return password_class::password;
}

void password_class::insertApp(database datab, authentication user, string app_name, string user_name, string password)
{
    this->app_name = app_name;
    this->user_name = user_name;
    this->password = password;
    datab.insertApp(datab.db, user, app_name, user_name, password);
}

// void password_class::updatePassword(string password);
// void password_class::passwordEncryption(string password);