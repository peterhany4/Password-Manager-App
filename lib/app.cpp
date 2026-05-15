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

// void app::insertAppName(string appName);
// void app::insertPassword(string password);
// void app::updatePassword(string password);
// void app::passwordEncryption(string password);