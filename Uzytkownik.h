#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <iostream>


using namespace std;

class Uzytkownik
{
    int id;
    string login;
    string password;

public:
    void setId(int id);
    void setLogin(string login);
    void setPassword(string password);

    int getId();
    string getLogin();
    string getPassword();

};

#endif
