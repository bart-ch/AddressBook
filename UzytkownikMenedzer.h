#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikiZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer
{
    int loggedInUserId;
    vector <Uzytkownik> users;
    PlikiZUzytkownikami usersFiles;

    Uzytkownik enterNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);

public:
    UzytkownikMenedzer(string);
    void registerAUser();
    void listAllUsers();
    int logIn();
    void changePasswordOfLoggedInUser();
    int getLoggedInUserId();
    bool isUserLoggedIn();
    void logOut();
};

#endif
