#include "UzytkownikMenedzer.h"

UzytkownikMenedzer::UzytkownikMenedzer(string nazwaPlikuZUzytkownikami)
    : usersFiles(nazwaPlikuZUzytkownikami)
{
    loggedInUserId = 0;
    users = usersFiles.loadUsersFromFile();
}

void UzytkownikMenedzer::registerAUser()
{
    Uzytkownik user = enterNewUserData();

    users.push_back(user);
    usersFiles.addUserToFile(user);

    cout << endl << "The account has been successfully created." << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::enterNewUserData()
{
    Uzytkownik user;

    user.setId(getNewUserId());

    string login;
    do
    {
        cout << "Enter login: ";
        login = MetodyPomocnicze::getSingleLine();
        user.setLogin(login);
    }
    while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    password = MetodyPomocnicze::getSingleLine();
    user.setPassword(password);

    return user;
}

int UzytkownikMenedzer::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UzytkownikMenedzer::doesLoginExist(string login)
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

void UzytkownikMenedzer::listAllUsers()
{
    for(int i = 0; i<users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UzytkownikMenedzer::changePasswordOfLoggedInUser()
{
    users = usersFiles.changePasswordOfLoggedInUser(loggedInUserId,users);
}

int UzytkownikMenedzer::logIn()
{
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = MetodyPomocnicze::getSingleLine();

    for (int i = 0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Enter password. Attempts remaining: " << iloscProb << ": ";
                password = MetodyPomocnicze::getSingleLine();

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

int UzytkownikMenedzer::getLoggedInUserId()
{
    return loggedInUserId;
}

bool UzytkownikMenedzer::isUserLoggedIn()
{
    if(loggedInUserId == 0)
        return false;
    else
        return true;
}

void UzytkownikMenedzer::logOut()
{
    loggedInUserId = 0;
}
