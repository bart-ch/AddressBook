#include "UserManager.h"

UserManager::UserManager(string nazwaPlikuZUzytkownikami)
    : usersFiles(nazwaPlikuZUzytkownikami)
{
    loggedInUserId = 0;
    users = usersFiles.loadUsersFromFile();
}

void UserManager::registerAUser()
{
    User user = enterNewUserData();

    users.push_back(user);
    usersFiles.addUserToFile(user);

    cout << endl << "The account has been successfully created." << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;

    user.setId(getNewUserId());

    string login;
    do
    {
        cout << "Enter login: ";
        login = AncillaryMethods::getSingleLine();
        user.setLogin(login);
    }
    while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    password = AncillaryMethods::getSingleLine();
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExist(string login)
{
    for(int i = 0; i<users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "The login is already taken." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::listAllUsers()
{
    for(int i = 0; i<users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserManager::changePasswordOfLoggedInUser()
{
    users = usersFiles.changePasswordOfLoggedInUser(loggedInUserId,users);
}

int UserManager::logIn()
{
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AncillaryMethods::getSingleLine();

    for (int i = 0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int numberOfTest = 3; numberOfTest > 0; numberOfTest--)
            {
                cout << "Enter password. Attempts remaining: " << numberOfTest << ": ";
                password = AncillaryMethods::getSingleLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You've logged in." << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].getId();
                    return loggedInUserId;
                }
            }
            cout << "You have entered wrong password 3 times." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "The user does not exist." << endl << endl;
    system("pause");
    return 0;
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

bool UserManager::isUserLoggedIn()
{
    if(loggedInUserId == 0)
        return false;
    else
        return true;
}

void UserManager::logOut()
{
    loggedInUserId = 0;
}
