#include "Recipient.h"

void Recipient::setRecipientId(int id)
{
    this->id = id;
}

void Recipient::setUserId(int userId)
{
    this->userId = userId;
}

void Recipient::setName(string name)
{
    this->name = name;
}
void Recipient::setSurname(string surname)
{
    this->surname = surname;
}
void Recipient::setTelephone(string telephone)
{
    this->telephone = telephone;
}
void Recipient::setEmail(string email)
{
    this->email = email;
}
void Recipient::setAddress(string address)
{
    this->address = address;
}

int Recipient::getRecipientId()
{
    return id;
}
int Recipient::getUserId()
{
    return userId;
}
string Recipient::getName()
{
    return name;
}
string Recipient::getSurname()
{
    return surname;
}
string Recipient::getTelephone()
{
    return telephone;
}
string Recipient::getEmail()
{
    return email;
}
string Recipient::getAddress()
{
    return address;
}
