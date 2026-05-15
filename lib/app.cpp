#include <iostream>
#include "app.h"
using namespace std;

app::app()
{
    app::appName = "";
    app::password = "";
}
app::app(string appName, string password)
{
    this->appName = appName;
    this->password = password;
}

string app::showAppName()
{
    return app::appName;
}

string app::showPassword()
{
    return app::password;
}

// string app::insertAppName(string appName);
// string app::insertPassword(string password);
// string app::updatePassword(string password);
// string app::passwordEncryption(string password);