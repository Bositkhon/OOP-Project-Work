#ifndef ADMIN_H
#define ADMIN_H

#include "Staff.h"

class Admin : public Staff {
  public:
    void addUser();
    void deleteUser();
    void modifyUser();
    void showInterface(string username);
  private:
    void listUsers();
};

#endif
