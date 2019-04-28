#include "Log.h"
#include "Book.h"
#include "User.h"
#include "Staff.h"
#include "Admin.h"
#include "Library.h"
#include "Customer.h"
#include "Password.h"

Log rec;
Library lib;
Password pwd;
string account;

int Login(string username, string password) {
    for (size_t i = 0; i < lib.users.size(); i++ )
        if (username == lib.users[i].getUsername() && password == lib.users[i].getPassword())
            return lib.users[i].getStatus();
    return 0;
}

void LoadData() {
    lib.loadUsers();
    lib.loadBooks();
    lib.loadCashes();
}

void Welcome() {
    system("cls");
    int status = 0;
    int time = 0;
    cout << "Welcome to Book Store Management System " << endl;
    cout << "You have to login first" << endl;
    while (status == 0) {
        cout << "Username: " << endl;
        cin >> account;
        cout << "Password: " << endl;
        pwd.InputPassword();
        status = Login(account, pwd.getPassword());
        if (status < 1 || status > 3) {
            time++;
            if (time < 3) cout << "You should have entered wrong credentials! Please try again.. " << endl;
            else if (time < 4) cout << "Are you sure you remember the password? Please try again... " << endl;
            else if (time < 5) cout << "You have tried a lot of time and this is you last chance" << endl;
            else {
                cout << "Maybe you should register a new account..." << endl;
                Sleep(1500);
                return;
            }
            Sleep(1500);
        } else {
            if (status == 1) {
                Admin member;
                member.showInterface(account);
            } else if (status == 2) {
                Staff member;
                member.showInterface(account);
            } else if (status == 3) {
                Customer member;
                member.showInterface(account);
            }
            break;
        }
        system("cls");
    }
}

int main(void) {
    LoadData();
    Welcome();
}
