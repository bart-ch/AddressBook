#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id, userId;
    string name, surname, telephone, email, address;

public:
    void setRecipientId(int id);
    void setUserId(int userId);
    void setName(string name);
    void setSurname(string surname);
    void setTelephone(string telephone);
    void setEmail(string email);
    void setAddress(string address);

    int getRecipientId();
    int getUserId();
    string getName();
    string getSurname();
    string getTelephone();
    string getEmail();
    string getAddress();
};

#endif // ADRESAT_H
