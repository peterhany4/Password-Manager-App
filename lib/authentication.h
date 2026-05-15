#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <string>
#include "app.h"
using namespace std;

class authentication
{
private:
    int id;
    string user_name;
    string password;

public:
    authentication();
    authentication(int id, string user_name, string password);
    void insertUserName(string user_name);
    void insertAppPassword(string password);
    void hashingPassword(string password);
};

#endif