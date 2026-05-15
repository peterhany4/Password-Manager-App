#include <iostream>
#include <string>
#include <database.h>
using namespace std;

database::database()
{
    char fileName[] = "Password_Manager.db";
    database::openDB(fileName, database::db);
    database::createTables(database::db);
}

void database::openDB(char *fileName, sqlite3 *database)
{
    int opened = sqlite3_open(fileName, &database);
    if (opened)
    {
        cout << "Error... Can't open the Database: " << sqlite3_errmsg(database) << '\n';
    }
    else
    {
        cout << "opened database successfuly \n";
        db = database;
    }
}
void database::createTables(sqlite3 *database)
{
    char *errMsg;
    char command_1[] = "CREATE TABLE users ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                       "username TEXT UNIQUE NOT NULL,"
                       "password TEXT NOT NULL );";

    char *sql = command_1;

    int rc = sqlite3_exec(database, sql, NULL, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cout << "Error in executing SQL: %s \n"
             << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    else
    {
        cout << "table User made successfully\n";
    }

    char command_2[] = "CREATE TABLE passwords ("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                       "user_id INTEGER,"
                       "app_name TEXT,"
                       "app_username TEXT,"
                       "app_password TEXT,"
                       "FOREIGN KEY(user_id) REFERENCES users(id) );";

    sql = command_2;

    rc = sqlite3_exec(database, sql, NULL, 0, &errMsg);

    if (rc != SQLITE_OK)
    {
        cout << "Error in executing SQL: %s \n"
             << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    else
    {
        cout << "table Password made successfully\n";
    }
}

void database::insertUser(sqlite3 *database, string user_name, string password)
{
    sqlite3_stmt *stmt;

    char *errMsg;
    char command[] = "INSERT INTO users(username, password)"
                     "VALUES (?, ?);";

    char *sql = command;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, user_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "User inserted successfully." << std::endl;
    }

    sqlite3_finalize(stmt);
}

// void database::updateUser(sqlite3 *database);
void database::insertApp(sqlite3 *database, int id, string app_name, string app_username, string app_password)
{
    sqlite3_stmt *stmt;

    // 1. Defined the SQL command string clearly
    const char *sql = "INSERT INTO passwords(user_id, app_name, app_username, app_password) VALUES (?, ?, ?, ?);";

    if (sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        cerr << "Prepare failed: " << sqlite3_errmsg(database) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, id);
    sqlite3_bind_text(stmt, 2, app_name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, app_username.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, app_password.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        cerr << "Execution failed: " << sqlite3_errmsg(database) << endl;
    }
    else
    {
        cout << "Application data inserted successfully." << endl;
    }

    sqlite3_finalize(stmt);
}

// void database::updateApp(sqlite3 *database);

void database::closeDB(sqlite3 *database)
{
    sqlite3_close(database);
}