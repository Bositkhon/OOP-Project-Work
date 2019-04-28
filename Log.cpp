#include "Log.h"
#include "Library.h"
#include "windows.h"

extern Library lib;

void Log::logUserInfo(string login, string username, string operation, int status) {
    ofstream fout;
    fout.open("UserLog.txt", ios::app);
    if (!fout) {
        cerr << "UserLog.txt can't open" << endl;
        abort();
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]";
    if (operation == "add")
        fout << " Admin(" << login << ") add a new user(" << username << ")" << endl;
    else if (operation == "del")
        fout << " Admin(" << login << ") delete a user(" << username << ")" << endl;
    else if (operation == "set")
        fout << " Admin(" << login << ") set user(" << username << ")'s status to (" << status <<") " << endl;
    else if (operation == "psw")
        fout << " User(" << login << ") change his/her password " << endl;
    fout.close();
}

void Log::logBookInfo(string login, string isbn, string operation, int number) {
    ofstream fout;
    fout.open("BookLog.txt", ios::app);
    if (!fout) {
        cerr << "BookLog.txt can't open" << endl;
        abort();
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]";
    if (operation == "buy")
        fout << " Customer(" << login << ") buy books(ISBN:" << isbn << ") with " << number << " copy(s)" << endl;
    else if (operation == "ref")
        fout << " Customer(" << login << ") refund books(ISBN:" << isbn << ") with " << number << " copy(s)" << endl;
    else if (operation == "add")
        fout << " Manager(" << login << ") add new books(ISBN:" << isbn << ") with " << number << " copy(s)" << endl;
    else if (operation == "del")
        fout << " Manager(" << login << ") delete books(ISBN:" << isbn << ") with " << number << " copy(s)" << endl;
    else if (operation == "set")
        fout << " Manager(" << login << ") change book(ISBN:" << isbn << ")'s information " << endl;
    fout.close();
}

void Log::logCashInfo(string login, string isbn, string operation, double money) {
    ofstream fout;
    fout.open("CashLog.txt", ios::app);
    if (!fout) {
        cerr << "CashLog.txt can't open" << endl;
        abort();
    }
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]";
    if (operation == "add") {
        fout << " Manager(" << login << ") add new books(ISBN:" << isbn << ") ---------- Outcome: " << money << endl;
        lib.setOutcome(money + lib.getOutcome());
    } else if (operation == "buy") {
        fout << " Customer(" << login << ") buy books(ISBN:" << isbn << ") ---------- Income: " << money << endl;
        lib.setIncome(money + lib.getIncome());
    } else if (operation == "ref") {
        fout << " Customer(" << login << ") refund books(ISBN:" << isbn << ") ---------- Outcome: " << money << endl;
        lib.setOutcome(money + lib.getOutcome());
    }
    fout.close();
}
