#include "Password.h"

void Password::InputPassword() {
    char temp_c;
    psw = "";
    while (true) {
        temp_c = _getch();
        if(temp_c != char(13)) {
            switch (temp_c) {
                case 8:
                    if (length != 0) {
                        cout << "\b \b";
                        psw = psw.substr(0, length-1);
                        length--;
                    }
                    break;
                default:
                    cout << "*";
                    psw += temp_c;
                    length++;
                    break;
            }
        } else break;
    }
    cout << endl;
}
