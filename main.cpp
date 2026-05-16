#include <iostream>
#include <string>
#include "lib/database.h"
#include "lib/authentication.h"
#include "lib/password_class.h"
using namespace std;

class app
{
private:
    database datab;
    authentication user;
    password_class pass;

public:
    app()
    {
    }

    string handleUserInput()
    {
        string input;
        getline(cin, input);
        return input;
    }

    int handleMenuSelection()
    {
        int input;
        cin >> input;
        cin.ignore(1000, '\n');
        return input;
    }

    void login()
    {
        cout << "\t\t Password Manager \t\t\n\n";
        cout << "Username: ";
        user.user_name = handleUserInput();
        cout << '\n';
        cout << "password: ";
        user.password = handleUserInput();
        cout << '\n';
        user.insertUser(datab, user.user_name, user.password);
    }

    void addPassword()
    {
        cout << "\t\t Password Manager \t\t\n\n";
        cout << "App Name: ";
        pass.app_name = handleUserInput();
        cout << '\n';
        cout << "Username: ";
        pass.user_name = handleUserInput();
        cout << '\n';
        cout << "Password: ";
        pass.password = handleUserInput();
        cout << '\n';
        pass.insertApp(datab, user, pass.app_name, pass.user_name, pass.password);
    }

    void homeMenu()
    {
        cout << "\t\t Password Manager \t\t\n\n";
        cout << "1- show Password\n";
        cout << "2- Add Password\n";
        cout << "3- Edit Password\n";
        cout << "4- Delete Password\n";
        cout << "5- Sign out\n";
        cout << "0- Exit\n\n";
    }

    void home()
    {
        homeMenu();
        cout << "Choose an index: ";
        int input = handleMenuSelection();
        switch (input)
        {
        case 1:
            break;
        case 2:
            addPassword();
            return home();
        case 3:
            break;
        case 4:
            break;
        case 5:
            login();
            return home();
        case 0:
            cout << "\nExiting program. Goodbye!\n";
            exit(0);
        default:
            cout << "Please choose from 0 to 5\n\n\n";
            return home();
        }
    }

    void run()
    {
        login();
        home();
    }
};

int main()
{
    app().run();

    return 0;
}