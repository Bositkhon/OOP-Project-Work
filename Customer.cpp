#include "Customer.h"

extern Log rec;
extern Library lib;
extern string account;

void Customer::buyBook() {
    system("cls");
    string isbn, temp;
    cout << "Please enter the ISBN number of the book that you want to buy " << endl;
    cin >> isbn;
    for (size_t i = 0; i < lib.books.size(); i++)
        if (lib.books[i].getISBN() == isbn) {
            cout << "There are " << lib.books[i].getNumber() << " copies of this book, how many do you want to buy?  " << endl;
            while (1) {
                cin >> temp;
                if (checkForDigits(temp)) break;
                cout << "Invalid input! The input should contain only digits" << endl;
            }
            if (stoi(temp) > lib.books[i].getNumber()) {
                cout << "Book number is not that much! " << endl;
                Sleep(1000);
            } else {
                lib.books[i].setNumber(lib.books[i].getNumber() - stoi(temp));
                cout << "Buy " << stoi(temp) << " copies of that book, succsessfully!~ " << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.logBookInfo(account, isbn, "buy", stoi(temp));
                rec.logCashInfo(account, isbn, "buy", lib.books[i].getNetPrice(stoi(temp)));
                saveBooks();
                saveCash();
            }
            return;
        }
    cout << "Book does not exist! " << endl;
    Sleep(1000);
}

void Customer::refund() {
    system("cls");
    string isbn, temp;
    cout << "Please enter the ISBN number of the book that you want to ask for refund " << endl;
    cin >> isbn;
    for (size_t i = 0; i < lib.books.size(); i++)
        if (lib.books[i].getISBN() == isbn) {
            cout << " How many copies of that book do you want to ask for refund?  " << endl;
            while (1) {
                cin >> temp;
                if (checkForDigits(temp)) break;
                cout << "Invalid input! The input should contain only digits" << endl;
            }
            lib.books[i].setNumber(lib.books[i].getNumber() + stoi(temp));
            cout << "refund " << stoi(temp) << " copies of books, succsessfully! " << endl;
            Sleep(1000);
            cout << "Automatic quit after 3 seconds." << endl;
            Sleep(2000);        
            rec.logBookInfo(account, isbn, "ref", stoi(temp));
            rec.logCashInfo(account, isbn, "ref", lib.books[i].getNetPrice(stoi(temp)));
            saveBooks();
            saveCash();
            return;
        }
    cout << "Book does not exist!" << endl;
    Sleep(1000);
}

void Customer::showInterface(string username) {
    char command;
    int stop = 0;
    bool alive = true;
    while (1) {
        system("cls");
        cout << "Welcome! " << username << " You are a customer" << endl;
        cout << "Please choose an option:" << endl;
        while (1) {
            cout << "1. Buy book" << endl;
            cout << "2. Refund" << endl;
            cout << "3. List all books" << endl;
            cout << "4. Search book by category" << endl;
            cout << "5. Search book by name" << endl;
            cout << "6. Show more book information by ISBN number" << endl;
            cout << "7. Change my password" << endl;
            cout << "0. Exit;" << endl;
            cin >> command;
            if (command < '0' || command > '7') {
                cout << endl << "Invalid input" << endl;
                cout << "Please try again!" << endl;
            } else break;
        }
        switch (command) {
            case '1':
                buyBook();
                break;
            case '2':
                refund();
                break;
            case '3':
                listAllBooks();
                break;
            case '4':
                listBooksByCategory();
                break;
            case '5':
                listBooksByName();
                break;
            case '6':
                showBookInfo();
                break;
            case '7':
                changePassword();
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
