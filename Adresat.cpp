#include "Adresat.h"

void Adresat::setRecipientId(int id)
{
    this->id = id;
}

void Adresat::setUserId(int userId)
{
    this->userId = userId;
}

void Adresat::setName(string name)
{
    this->name = name;
}
void Adresat::setSurname(string surname)
{
    this->surname = surname;
}
void Adresat::setTelephone(string telephone)
{
    this->telephone = telephone;
}
void Adresat::setEmail(string email)
{
    this->email = email;
}
void Adresat::setAddress(string address)
{
    this->address = address;
}

int Adresat::getRecipientId()
{
    return id;
}
int Adresat::getUserId()
{
    return userId;
}
string Adresat::getName()
{
    return name;
}
string Adresat::getSurname()
{
    return surname;
}
string Adresat::getTelephone()
{
    return telephone;
}
string Adresat::getEmail()
{
    return email;
}
string Adresat::getAddress()
{
    return address;
}
