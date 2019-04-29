#include "Staff.h"

extern Library lib;
extern Log rec;
extern string account;

void Staff::addBook() {
    system("cls");
    Book newbook;
    string money, number, category, price, name, isbn, author, discount, disc_num, information;
    cout << "Please enter the ISBN number of the book" << endl;
    cin >> isbn;
    for (size_t i = 0; i < lib.books.size(); i++)
        if (lib.books[i].getISBN() == isbn) {
            cout << "This ISBN number already exist =. =" << endl;
            Sleep(1000);
            return;
        }
    cout << "Please enter the name of the book" << endl;
    cin >> name;
    cout << "Please enter the author of the book" << endl;
    cin >> author;
    cout << "Please enter the copy number of the book" << endl;
    while (1) {
        cin >> number;
        if (checkForDigits(number)) break;
        cout << "Invalid input. Please try again!" << endl;
    }
    cout << "Please enter the category of the book" << endl;
    while (1) {
        cin >> category;
        if (checkForDigits(category)) break;
        cout << "Invalid input. Please try again!" << endl;
    }
    cout << "Please input the price of the book" << endl;
    while (1) {
        cin >> price;
        if (checkForDigits(price)) break;
        cout << "Invalid input. Please try again!" << endl;
    }
    cout << "Please input the discount of the book" << endl;
    while (1) {
        cin >> discount;
        if (checkForDigits(discount)) break;
        cout << "Invalid input. Please try again!" << endl;
    }
    cout << "Please input the number of the book at least that can give a discount " << endl;
    while (1) {
        cin >> disc_num;
        if (checkForDigits(disc_num)) break;
        cout << "Invalid input. Please try again!" << endl;
    }
    cout << "Please input some information of this book" << endl;
    cin >> information;
    cout << "Please input the money that those book costs" << endl;
    while (1) {
        cin >> money;
        if (checkForDigits(money)) break;
        cout << "Invalid input. Please try again!" << endl;
    }
    newbook.setName(name);
    newbook.setISBN(isbn);
    newbook.setAuthor(author);
    newbook.setNumber(stoi(number));
    newbook.setCategory(stoi(category));
    newbook.setPrice(stod(price));
    newbook.setDiscount(stod(discount));
    newbook.setDiscNum(stoi(disc_num));
    newbook.setInformation(information);
    lib.books.push_back(newbook);
    cout << "Book has been added successfully" << endl;
    Sleep(1000);
    cout << "Automatic quit after 3 seconds." << endl;
    Sleep(2000);
    rec.logBookInfo(account, isbn, "add", stoi(number));
    rec.logCashInfo(account, isbn, "add", stod(money));
    saveBooks();
    saveCash();
}

void Staff::deleteBook() {
    system("cls");
    string isbn, temp;
    cout << "Please input the ISBN number of the book that you want to delete " << endl;
    cin >> isbn;
    for (size_t i = 0; i < lib.books.size(); i++)
        if (lib.books[i].getISBN() == isbn) {
            cout << "There are " << lib.books[i].getNumber() << " copies of this book, how many do you want to delete?  " << endl;
            while (1) {
                cin >> temp;
                if (checkForDigits(temp)) break;
                cout << "Invalid input. Please try again!" << endl;
            }
            if (stoi(temp) > lib.books[i].getNumber()) {
                cout << "Book number is not that much! " << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(3000);
            } else {
                lib.books[i].setNumber(lib.books[i].getNumber() - stoi(temp));
                cout << stoi(temp) <<  "copies has successfully been deleted from library!" << endl;
                Sleep(1000);
                cout << "Automatic quit after 3 seconds." << endl;
                Sleep(2000);
                rec.logBookInfo(account, isbn, "del", stoi(temp));
                saveBooks();
            }
            return;
        }
    cout << "Not found this book! " << endl;
    Sleep(1000);
}

void Staff::modifyBook() {
    system("cls");
    int choice;
    string number, category, price, name, isbn, author, discount, disc_num, information;
    cout << "Please enter the ISBN number of the book that you want to change the information." << endl;
    cin >> isbn;
    for (size_t i = 0; i < lib.books.size(); i++)
        if (lib.books[i].getISBN() == isbn ) {
            cout << "Do you want to change the name of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please enter the new name of the book" << endl;
                cin >> name;
                lib.books[i].setName(name);
            }
            cout << "Do you want to change the ISBN number of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please enter the new ISBN number of the book" << endl;
                cin >> isbn;
                lib.books[i].setISBN(isbn);
            }
            cout << "Do you want to change the author of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please enter the new author of the book" << endl;
                cin >> author;
                lib.books[i].setAuthor(author);
            }
            cout << "Do you want to change the copy number of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please enter the new copy number of the book" << endl;
                while (1) {
                    cin >> number;
                    if (checkForDigits(number)) break;
                    cout << "Invalid input. Please try again!" << endl;
                }
                lib.books[i].setNumber(stoi(number));
            }
            cout << "Do you want to change the category of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new category of the book" << endl;
                while (1) {
                    cin >> category;
                    if (checkForDigits(category)) break;
                    cout << "Invalid input. Please try again!" << endl;
                }
                lib.books[i].setCategory(stoi(category));
            }
            cout << "Do you want to change the price of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please enter the new price of the book" << endl;
                while (1) {
                    cin >> price;
                    if (checkForDigits(price)) break;
                    cout << "Invalid input. Please try again!" << endl;
                }
                lib.books[i].setPrice(stod(price));
            }
            cout << "Do you want to change the discount of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please enter the new discount of the book" << endl;
                while (1) {
                    cin >> discount;
                    if (checkForDigits(discount)) break;
                    cout << "Invalid input. Please try again!" << endl;
                }
                lib.books[i].setDiscount(stod(discount));
            }
            cout << "Do you want to change the disc_num of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please enter the new disc_num of the book" << endl;
                while (1) {
                    cin >> disc_num;
                    if (checkForDigits(disc_num)) break;
                    cout << "Invalid input. Please try again!" << endl;
                }
                lib.books[i].setDiscNum(stoi(disc_num));
            }
            cout << "Do you want to change the information of the book? (1. Yes 0. No )" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Please input the new information of the book" << endl;
                cin >> information;
                lib.books[i].setInformation(information);
            }
            cout << "Change book information succsessfully!~ " << endl;
            Sleep(1000);
            cout << "Automatic quit after 3 seconds." << endl;
            Sleep(2000);
            rec.logBookInfo(account, isbn, "set", 0);
            saveBooks();
            return;
        }
    cout << "Not found this book! " << endl;
    Sleep(1000);
}

void Staff::viewProfit() {
    system("cls");
    string temp;
    cout << "Total income: " << lib.getIncome() << endl;
    cout << "Total outcome: " << lib.getOutcome() << endl;
    cout << "Total net profit: " << lib.getIncome() - lib.getOutcome() << endl;
    system("pause");
    return;
}

void Staff::showInterface(string username) {
    char command;
    bool alive = true;
    string str;
    while (1) {
        system("cls");
        cout << "Welcome! " << username << " You are staff member" << endl;
        cout << "Please choose an option:" << endl;
        while (1) {
            cout << "1. Add new book" << endl;
            cout << "2. Delete book" << endl;
            cout << "3. Change book information" << endl;
            cout << "4. List all books" << endl;
            cout << "5. Search book by category" << endl;
            cout << "6. Search book by name" << endl;
            cout << "7. Show more book information by ISBN number" << endl;
            cout << "8. Lookup net profit" << endl;
            cout << "9. Change my password" << endl;
            cout << "0. Exit;" << endl;
            cin >> command;
            if (command < '0' || command > '9') {
                cout << endl << "Invalid input" << endl;
                cout << "Please try again!" << endl;
            } else break;
        }
        switch (command) {
            case '1':
                addBook();
                break;
            case '2':
                deleteBook();
                break;
            case '3':
                modifyBook();
                break;
            case '4':
                listAllBooks();
                break;
            case '5':
                listBooksByCategory();
                break;
            case '6':
                listBooksByName();
                break;
            case '7':
                showBookInfo();
                break;
            case '8':
                viewProfit();
                break;
            case '9':
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
