#include <iostream>
#include <string>
#include <list>
#include <database.h>
#include <sqlite3.h>
using namespace std;

struct passwords
{
    int id;
    string user;
    string app_name;
    string user_name;
    string password;
};

class displayData
{
public:
    // passwords passInfo;
    void loadUsersFromDB(database &datab, list<passwords> &passlist);
};
