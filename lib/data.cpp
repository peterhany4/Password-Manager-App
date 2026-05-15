#include <iostream>
#include "data.h"
using namespace std;

data::data()
{
    data::app_name = "";
    data::user_name = "";
    data::password = "";
}
data::data(string app_name, string user_name, string password)
{
    this->app_name = app_name;
    this->user_name = user_name;
    this->password = password;
}

string data::showAppName()
{
    return data::app_name;
}

string data::showUsername()
{
    return data::user_name;
}

string data::showPassword()
{
    return data::password;
}

// void data::insertAppName(string appName);
// void data::insertPassword(string password);
// void data::updatePassword(string password);
// void data::passwordEncryption(string password);