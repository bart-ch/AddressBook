#ifndef USERSFILES_H
#define USERSFILES_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "User.h"
#include "AncillaryMethods.h"
#include "TextFile.h"

using namespace std;

class UsersFiles :public TextFile
{
    string convertUserDataToLineWithDataSeparatedByPipe(User user);
    User getUserData(string userDataSeparatedByPipe);
    void saveAllUsersToFile(vector <User> users);

public:
    UsersFiles(string);
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    vector <User> changePasswordOfLoggedInUser(int idZalogowanegoUzytkownika,vector <User> users);
};

#endif
