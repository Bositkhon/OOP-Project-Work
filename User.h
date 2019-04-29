#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include "Log.h"

using namespace std;

class User {
public:
    void listAllBooks();
    void listBooksByCategory();
    void listBooksByName();
    void showBookInfo();
    void saveUsers();
    void saveBooks();
    void saveCash();
    int checkForDigits(const string& str);

    string getUsername() { return username; };
    string getPassword() { return password; };
    int    getStatus() { return status; };

    void setUsername(string name) { username = name; };
    void setPassword(string pwd) { password = pwd; };
    void setStatus(int number) { status = number; };

    void changePassword();
    
    virtual void showInterface(string username) {};
private:
    int status;
    string username;
    string password;
};

#endif
