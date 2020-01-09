#include "Uzytkownik.h"

void Uzytkownik::setId(int id)
{
    if(id >= 0)
        this->id = id;
}
void Uzytkownik::setLogin(string login)
{
    this->login = login;
}
void Uzytkownik::setPassword(string password)
{
    this->password = password;
}

int Uzytkownik::getId()
{
    return id;
}
string Uzytkownik::getLogin()
{
    return login;
}
string Uzytkownik::getPassword()
{
    return password;
}
