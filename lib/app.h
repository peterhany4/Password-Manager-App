#ifndef APP_H
#define APP_H
#include <string>
using namespace std;

class app
{
private:
    string appName;
    string password;
public:
    app();
    app(string appName, string password);
    
    string showAppName();
    string showPassword();
    string insertAppName(string appName);
    string insertPassword(string password);
    string updatePassword(string password);
    string passwordEncryption(string password);
};
#endif