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
    void insertAppName(string appName);
    void insertPassword(string password);
    void updatePassword(string password);
    void passwordEncryption(string password);
};
#endif