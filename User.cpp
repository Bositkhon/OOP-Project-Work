#include "User.h"
#include "Library.h"

extern Log rec;
extern Library lib;
extern string account;

void User::saveUsers() {
    ofstream fout;
    fout.open("User.txt");
    if (!fout) {
        cerr << "User.txt can't open" << endl;
        abort();
    }
    for (size_t i = 0; i < lib.users.size(); i++ )
        fout << lib.users[i].getUsername() << " " << lib.users[i].getPassword() << " " << lib.users[i].getStatus() << endl;
    fout.close();
}

void User::saveBooks() {
    ofstream fout;
    fout.open("Book.txt");
    if  (!fout) {
        cerr << "Book.txt can't open" << endl;
        abort();
    }
    for (size_t i = 0; i < lib.books.size(); i++ )
        fout << lib.books[i].getName() << " " << lib.books[i].getISBN() << " " << lib.books[i].getAuthor()
            << " " << lib.books[i].getNumber() << " " << lib.books[i].getCategory()
            << " " << lib.books[i].getPrice() << " " << lib.books[i].getDiscount()
            << " " << lib.books[i].getDiscNum() << " " << lib.books[i].getInformation() << endl;
    fout.close();
}

void User::saveCash() {
    ofstream fout;
    fout.open("Cash.txt");
    if (!fout) {
        cerr << "Cash.txt can't open" << endl;
        abort();
    }
    fout << lib.getIncome() << endl;
    fout << lib.getOutcome() << endl;
    fout.close();
}

 int User::checkForDigits(const string& str) {
    int i ;
    for(i = 0; i != str.length(); i++)
        if (!isdigit(str[i]) && (str[i]!='.')) return 0;
    return 1;
}

void User::listAllBooks() {
    system("cls");
    string temp;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|       ISBN       |             Name            | Number |    Price    | Category |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.books.size(); i++) {
        cout << "|" << setw(18) << lib.books[i].getISBN() << "|" <<  setw(29) << lib.books[i].getName() <<  "|"
            <<  setw(8) << lib.books[i].getNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.books[i].getPrice()  << "|" 
            << setw(10) << lib.books[i].getCategory() << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::listBooksByCategory() {
    system("cls");
    string temp, category;
    cout << "Please enter the category that you want to list: " << endl;
    while (1) {
        cin >> category;
        if (checkForDigits(category)) break;
        cout << "Invalid input. Please try again" << endl;
    }
    system("cls");
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|       ISBN       |             Name            | Number |    Price    | Category |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.books.size(); i++)
        if (lib.books[i].getCategory() == stoi(category)) {
            cout << "|" << setw(18) << lib.books[i].getISBN() << "|" <<  setw(29) << lib.books[i].getName() <<  "|"
                <<  setw(8) << lib.books[i].getNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.books[i].getPrice()  << "|" 
                << setw(10) << lib.books[i].getCategory() << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::listBooksByNumber() {
    system("cls");
    string temp, name;
    cout << "Please enter the name that you want to find: " << endl;
    cin >> name;
    system("cls");
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "|       ISBN       |             Name            | Number |    Price    | Category |" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    for (size_t i = 0; i < lib.books.size(); i++)
        if (lib.books[i].getName().find(name) != string::npos) {
            cout << "|" << setw(18) << lib.books[i].getISBN() << "|" <<  setw(29) << lib.books[i].getName() <<  "|"
                <<  setw(8) << lib.books[i].getNumber() << "|"<<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<lib.books[i].getPrice()  << "|" 
                << setw(10) << lib.books[i].getCategory() << "|" << endl;
        }
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Input 0 to exit" << endl;
    cin >> temp;
    while (temp != "0")
        cin >> temp;
}

void User::showBookInfo() {
    system("cls");
    string temp, isbn;
    cout << "Please enter the ISBN number of the book that you want to find: " << endl;
    cin >> isbn;
    for (size_t i = 0; i < lib.books.size(); i++)
        if (lib.books[i].getISBN() == isbn ) {
            system("cls");
            cout << "Detail information of the book with ISBN number " << isbn << " : " << endl;
            cout << "Name            : " << lib.books[i].getName() << endl;
            cout << "Author            : " << lib.books[i].getAuthor() << endl;
            cout << "Number            : " << lib.books[i].getNumber() << endl;
            cout << "Category        : " << lib.books[i].getCategory() << endl;
            cout << "Price            : " << setiosflags(ios::fixed) << setprecision(2) << lib.books[i].getPrice() << endl;
            cout << "Discount        : " << setiosflags(ios::fixed) << setprecision(2) << lib.books[i].getDiscount()  << endl;
            cout << "Disc_num        : " << lib.books[i].getDiscNum() << endl;
            cout << "Information        : " << lib.books[i].getInformation() << endl;
            cout << endl;
            cout << "Input 0 to exit" << endl;
            cin >> temp;
            while (temp != "0")
                cin >> temp;
            return;
        }
    cout << "Book does not exist " << endl;
    Sleep(1000);
}

void User::changePassword() {
    system("cls");
    string temp, password;
    cout << "Please enter the new password that you want: " << endl;
    cin >> password;
    cout << "Please repeat it: " << endl;
    cin >> temp;
    if (temp != password) {
        cout << "Password did not match! Please try again" << endl;
        Sleep(1500);
        return;
    } else {
        for (size_t i = 0; i < lib.books.size(); i++)
            if (lib.users[i].getUsername() == account )
                lib.users[i].setPassword(password);
        cout << "Password change successfully !~~ " << endl;
        rec.logUserInfo(account, account, "psw", 0);
        saveUsers();
        Sleep(2000);
    }
}
