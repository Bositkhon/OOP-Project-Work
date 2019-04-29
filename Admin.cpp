#include "Admin.h"

extern Log rec;
extern Library lib;
extern string account;

void Admin::addUser() {
    system("cls");
    User newuser;
    string name, pwd;
    cout << "Please enter the username" << endl;
    cin >> name;
    for (size_t i = 0; i < lib.users.size(); i++)
        if (lib.users[i].getUsername() == name) {
            if (lib.users[i].getStatus() != 0) {
                cout << "User already exist! " << endl;
                Sleep(1000);
                return;
            } else {
                cout << "Please enter your password" << endl;
                cin >> pwd;
                lib.users[i].setUsername(name);
                lib.users[i].setPassword(pwd);
                lib.users[i].setStatus(3);
                cout << "User has been added successfully! " << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.logUserInfo(account, name, "add", 0);
                saveUsers();
                return;
            }
        }
    cout << "Please enter your password" << endl;
    cin >> pwd;
    newuser.setUsername(name);
    newuser.setPassword(pwd);
    newuser.setStatus(3);
    lib.users.push_back(newuser);
    cout << "User has been added successfully!" << endl;
    Sleep(1000);
    cout << "Automatic quit after 3 seconds." << endl;
    Sleep(2000);
    rec.logUserInfo(account, name, "add", 0);
    saveUsers();
}

void Admin::deleteUser() {
    system("cls");
    int choice;
    string name;
    cout << "Please enter the username that you want to delete" << endl;
    cin >> name;
    for (size_t i = 0; i < lib.users.size(); i++)
        if (lib.users[i].getUsername() == name) {
            if (lib.users[i].getStatus() != 0) {
                cout << "Are you sure you want to delete this user? (1. Yes 0. No)" << endl;
                cin >> choice;
                if (choice == 1) {
                    lib.users[i].setStatus(0);
                    cout << "User has been deleted successfully!" << endl;
                } else cout << "Delete canceled" << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.logUserInfo(account, name, "del", 0);
                saveUsers();
                return;
            }
        }
    cout << "User does not exist!" << endl;
    Sleep(1000);
}

void Admin::modifyUser() {
    system("cls");
    int choice;
    string name;
    cout << "Please enter the username that you want to change status" << endl;
    cin >> name;
    for (size_t i = 0; i < lib.users.size(); i++)
        if (name == lib.users[i].getUsername()) {
            if (lib.users[i].getStatus() != 0) {
                cout << "Please choose an option: (3. Customer 2. Staff 1. Admin 0. Quit)" << endl;
                cin >> choice;
                if (choice != 0) {
                    lib.users[i].setStatus(choice);
                    cout << "User status has been changed successfully! " << endl;
                } else cout << "Change canceled." << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.logUserInfo(account, name, "set", choice);
            saveUsers();
                return;
            }
        }
    cout << "User does not exist!" << endl;
    Sleep(1000);
}

void Admin::listUsers() {
    system("cls");
    string temp;
    vector<string> Stat;
    temp = "Admin";
    Stat.push_back(temp);
    temp = "Staff";
    Stat.push_back(temp);
    temp = "Customer";
    Stat.push_back(temp);
    cout << "This is the list of all the user:" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "|       Username      |    Password    |   Status   |" << endl;
    cout << "-----------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.users.size(); i++)
        if (lib.users[i].getStatus() != 0)
            cout << "|" << setw(21) << lib.users[i].getUsername() << "|" <<  setw(36) << lib.users[i].getPassword()
                << "|" << setw(12) << Stat[lib.users[i].getStatus() - 1] << "|" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void Admin::showInterface(string username) {
    char command;
    bool alive = true;
    int stop = 0;
    while (true) {
        system("cls");
        cout << "Welcome! " << username << " You are administartor" << endl;
        cout << "Please choose an option" << endl;
        while (true) {
            cout << "1. Add new user" << endl;
            cout << "2. Delete user" << endl;
            cout << "3. Change user privilage" << endl;
            cout << "4. Add new book" << endl;
            cout << "5. Delete book" << endl;
            cout << "6. Change book information" << endl;
            cout << "7. List all books" << endl;
            cout << "8. Search book by category" << endl;
            cout << "9. Search book by name" << endl;
            cout << "*. Show more book information by ISBN number" << endl;
            cout << "&. List all users' information" << endl;
            cout << "$. Lookup net profit" << endl;
            cout << "%. Change my password" << endl;
            cout << "0. Exit;" << endl;
            cin >> command;
            if (command != '*' && command != '&' && command != '%' && command != '$' && (command < '0' || command > '9')) {
                cout << endl << "Invalud input. You should input '*','&','%','$' or number between 0-9" << endl;
                cout << "Please try again " << endl;
            } else break;
        }
        switch (command) {
            case '1':
                addUser();
                break;
            case '2':
                deleteUser();
                break;
            case '3':
                modifyUser();
                break;
            case '4':
                addBook();
                break;
            case '5':
                deleteBook();
                break;
            case '6':
                modifyBook();
                break;
            case '7':
                listAllBooks();
                break;
            case '8':
                listBooksByCategory();
                break;
            case '9':
                listBooksByName();
                break;
            case '*':
                showBookInfo();
                break;
            case '%':
                changePassword();
                break;
            case '$':
                viewProfit();
                break;
            case '&':
                listUsers();
                break;
            case '0':
                alive = false;
                cout << "System will quit after 3 seconds " <<endl;
                Sleep(3000);
                break;
        }
        if (!alive) break;
    }
}
