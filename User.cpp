#include "User.h"

void User::setId(int id)
{
    if(id >= 0)
        this->id = id;
}
void User::setLogin(string login)
{
    this->login = login;
}
void User::setPassword(string password)
{
    this->password = password;
}

int User::getId()
{
    return id;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
