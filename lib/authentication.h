#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <string>
#include "database.h"
using namespace std;

class database;

class authentication
{
private:
    string password;

public:
    string user_name;
    authentication();
    authentication(string user_name, string password);
    void insertUser(database db, string user_name, string password);
};
#endif