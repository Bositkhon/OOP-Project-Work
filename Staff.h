#ifndef STAFF_H
#define STAFF_H

#include "User.h"
#include "Library.h"

class Staff : public User {
public:
    void addBook();
    void deleteBook();
    void modifyBook();
    void showInterface(string username);
protected:
    void viewProfit();
};

#endif
