#include <iostream>
#include <string>
#include "authentication.h"
using namespace std;

authentication::authentication()
{
    authentication::id = -1;
    authentication::user_name = "";
    authentication::password = "";
}

authentication::authentication(int id, string user_name, string password)
{
    this->id = id;
    this->user_name = user_name;
    this->password = password;
}

// void authentication::insertUserName(string user_name);
// void authentication::insertAppPassword(string password);
// void authentication::hashingPassword(string password);