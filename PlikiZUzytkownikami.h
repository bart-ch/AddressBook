#ifndef PLIKIZUZYTKOWNIKAMI_H
#define PLIKIZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikiZUzytkownikami :public PlikTekstowy
{
    string convertUserDataToLineWithDataSeparatedByPipe(Uzytkownik user);
    Uzytkownik getUserData(string userDataSeparatedByPipe);
    void saveAllUsersToFile(vector <Uzytkownik> users);

public:
    PlikiZUzytkownikami(string);
    void addUserToFile(Uzytkownik user);
    vector <Uzytkownik> loadUsersFromFile();
    vector <Uzytkownik> changePasswordOfLoggedInUser(int idZalogowanegoUzytkownika,vector <Uzytkownik> users);
};

#endif
