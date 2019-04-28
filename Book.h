#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {
public:
    string getName() { return name; }
    string getISBN() { return isbn; }
    string getAuthor() { return author; }
    int getNumber() { return number; }
    int getCategory() { return category; }
    double getPrice() { return price; }
    double getDiscount() { return discount; }
    int getDiscNum() { return disc_num; }
    string getInformation() { return information; }

    void setName(string _name) { name = _name; }
    void setISBN(string _isbn) { isbn = _isbn; }
    void setAuthor(string _author) { author = _author; }
    void setNumber(int _number) { number = _number; }
    void setCategory(int _category) { category = _category; }
    void setPrice(double _price) { price = _price; }
    void setDiscount(double _discount) { discount = _discount; }
    void setDiscNum(int _disc_num) { disc_num = _disc_num; }
    void setInformation(string _info) { information = _info; }

    double getNetPrice(int num) {
        if (num > number)
            return ((double)num * price * discount);
        else
            return ((double)num * price);
    }
private:
    string name;
    string isbn;
    string author;
    int number;
    int category;
    double price;
    double discount;
    int disc_num;
    string information;
};

#endif
