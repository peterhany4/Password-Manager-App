#include <iostream>
#include <string>
#include <list>
#include <database.h>
#include <sqlite3.h>
#include "databaseToObject.h"
using namespace std;

void displayData::loadUsersFromDB(database &datab, list<passwords> &passlist)
{
    sqlite3_stmt *stmt = nullptr;

    char fileName[] = "Password_Manager.db";

    if (sqlite3_open(fileName, &datab.db) != SQLITE_OK)
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(datab.db) << "\n";
        return;
    }

    const char *sql = "SELECT * FROM passwords;";

    if (sqlite3_prepare_v2(datab.db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(datab.db) << "\n";
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        // FIX 4: Corrected return types to const unsigned char* and explicit casting
        int id = sqlite3_column_int(stmt, 0);

        const unsigned char *raw_user = sqlite3_column_text(stmt, 1);
        string user = raw_user ? reinterpret_cast<const char *>(raw_user) : "";

        const unsigned char *raw_app = sqlite3_column_text(stmt, 2);
        string app_name = raw_app ? reinterpret_cast<const char *>(raw_app) : "";

        const unsigned char *raw_username = sqlite3_column_text(stmt, 3);
        string user_name = raw_username ? reinterpret_cast<const char *>(raw_username) : "";

        const unsigned char *raw_pass = sqlite3_column_text(stmt, 4);
        string password = raw_pass ? reinterpret_cast<const char *>(raw_pass) : "";

        // FIX 5: Standard std::list uses push_back to append items
        passlist.push_back({id, user, app_name, user_name, password});
    }
}
