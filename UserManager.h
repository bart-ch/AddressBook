#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UsersFiles.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    UsersFiles usersFiles;

    User enterNewUserData();
    int getNewUserId();
    bool doesLoginExist(string login);

public:
    UserManager(string);
    void registerAUser();
    void listAllUsers();
    int logIn();
    void changePasswordOfLoggedInUser();
    int getLoggedInUserId();
    bool isUserLoggedIn();
    void logOut();
};

#endif
