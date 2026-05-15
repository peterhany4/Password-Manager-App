#ifndef DATABASE_H
#define DATABASE_H
#include "sqlite3.h"

class database
{
private:
    sqlite3 *db;

public:
    database();
    void openDB(char *fileName, sqlite3 *database);
    void createTables(sqlite3 *database);
    void insertUser(sqlite3 *database, string user_name, string password);
    void updateUser(sqlite3 *database, string user_name, string password);
    void insertApp(sqlite3 *database, int id, string app_name, string app_username, string app_password);
    void updateApp(sqlite3 *database, int id, string app_name, string app_username, string app_password);
    void closeDB(sqlite3 *database);
};

#endif