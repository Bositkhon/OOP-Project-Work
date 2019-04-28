#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

class Library {
public:
    void loadUsers();
    void loadBooks();
    void loadCashes();
    void setIncome(double new_income) { income = new_income; };
    void setOutcome(double new_outcome) { outcome = new_outcome; };
    double getIncome() { return income; };
    double getOutcome() { return outcome; };
    vector<Book> books;
    vector<User> users;
private:
    double income;
    double outcome;
};

#endif
