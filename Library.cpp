#include "Library.h"

void Library::loadUsers() {
    User olduser;
    string str;
    ifstream fin("User.txt");
    if(!fin) {
        cerr << "User.txt can't open" << endl;
        abort();
    }
    while (getline(fin, str)) {
        size_t i = str.find(" ");
        olduser.setUsername(str.substr(0, i));
        str = str.substr(i+1);

        i = str.find(" ");
        olduser.setPassword(str.substr(0, i));
        olduser.setStatus(stoi(str.substr(i+1)));

        users.push_back(olduser);
    }
    fin.close();
}

void Library::loadBooks() {
    Book oldbook;
    string str;
    ifstream fin("Book.txt");
    if(!fin) {
        cerr << "Book.txt can't open" << endl;
        abort();
    }
    while (getline(fin, str)) {
        size_t i = str.find(" ");
        oldbook.setName(str.substr(0, i));
        str = str.substr(i+1);

        i = str.find(" ");
        oldbook.setISBN(str.substr(0, i));
        str = str.substr(i+1);

        i = str.find(" ");
        oldbook.setAuthor(str.substr(0, i));
        str = str.substr(i+1);

        i = str.find(" ");
        oldbook.setNumber(stoi(str.substr(0, i)));
        str = str.substr(i+1);

        i = str.find(" ");
        oldbook.setCategory(stoi(str.substr(0, i)));
        str = str.substr(i+1);

        i = str.find(" ");
        oldbook.setPrice(stoi(str.substr(0, i)));
        str = str.substr(i+1);

        i = str.find(" ");
        oldbook.setDiscount(stod(str.substr(0, i)));
        str = str.substr(i+1);

        i = str.find(" ");
        oldbook.setDiscNum(stoi(str.substr(0, i)));
        oldbook.setInformation(str.substr(i+1));

        books.push_back(oldbook);
    }
    fin.close();
}

void Library::loadCashes() {
    ifstream fin("Cash.txt");
    if(!fin) {
        cerr << "Cash.txt can't open" << endl;
        abort();
    }
    fin >> income;
    fin >> outcome;
    fin.close();
}
