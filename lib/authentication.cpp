#include <iostream>
#include <string>
#include "authentication.h"
#include "database.h"
using namespace std;

authentication::authentication()
{
    authentication::user_name = "";
    authentication::password = "";
}

authentication::authentication(string user_name, string password)
{
    this->user_name = user_name;
    this->password = password;
}

void authentication::insertUser(database datab, string user_name, string password)
{
    this->user_name = user_name;
    this->password = password;
    datab.insertUser(datab.db, user_name, password);
}