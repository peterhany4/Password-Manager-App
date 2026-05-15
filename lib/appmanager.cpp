#include <iostream>
#include <string>
#include "appmanager.h"
using namespace std;

appmanager::appmanager()
{
    appmanager::user_name = "";
    appmanager::password = "";
}

appmanager::appmanager(string user_name, string password)
{
    this->user_name = user_name;
    this->password = password;
}

// void appmanager::insertUserName(string user_name);
// void appmanager::insertAppPassword(string password);
// void appmanager::hashingPassword(string password);