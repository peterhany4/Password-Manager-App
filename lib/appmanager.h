#ifndef APPMANAGER_H
#define APPMANAGER_H
#include <string>
#include "app.h"
using namespace std;

class appmanager
{
private:
    string user_name;
    string password;
public:
    appmanager();
    appmanager(string user_name, string password);
    void insertUserName(string user_name);
    void insertAppPassword(string password);
    void hashingPassword(string password);
};

#endif