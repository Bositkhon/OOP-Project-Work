#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Log {
public:
    void logUserInfo(string login, string username, string operation, int status); 
    void logBookInfo(string login, string isbn, string operation, int number);
    void logCashInfo(string login, string isbn, string operation, double money);
};

#endif
