#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    ifstream fin;
    fin.open("text.txt");
    if (!fin.is_open()) {
        cout << "Невозможно открыть файл." << endl;
        return 1;
    }
    fin.seekg(0, ios::end);
    long len = fin.tellg();
    char* buf = new char[len + 1];
    char  str[80] = "";
    fin.seekg(0, ios::beg);
    fin.read(buf, len);
    buf[len] = '\0';
    long n = 0, i = 0, j = 0, h = 0;
    while (buf[i]) {
        if (buf[i] == '?') {
            for (j = n; j <= i; j++) {
                cout << buf[j];
            }
            cout << '\n';
            n = i + 1;
        }
        if (buf[i] == '!') {
            for (j = n; j <= i; j++) {
                str[h++] = buf[j];
            }
            str[h++] = '\n';
            n = i + 1;
        }

        if (buf[i] == '.' || buf[i] == '\n')
            n = i + 1;
        i++;
    }
    fin.close();
    cout << str << endl;
    delete[] buf;
    _getch();
    return 0;
}