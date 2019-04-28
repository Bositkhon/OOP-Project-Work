#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Library.h"

class Customer : public User {
public:
    void buyBook();
    void refund();
    void showInterface(string username);
};

#endif
