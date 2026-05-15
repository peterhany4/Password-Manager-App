#include <iostream>
#include <string>
#include "lib/database.h"
#include "lib/authentication.h"
#include "lib/password_class.h"
using namespace std;

class app
{
    private:
    database db;
    public:
    app()
    {
        cout << "running...\n";
        authentication user1 = authentication();
        user1.insertUser(db, "Peter", "123123123");

        password_class pass1;
        pass1.insertApp(db, user1, "youtube", "peter12", "abcde1");
        
    }

    void menu()
    {
        /*          Menu            */
    }



};

int main()
{
    app();

    return 0;
}