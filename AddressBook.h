#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <iostream>

#include "UserManager.h"
#include "RecipientManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    RecipientManager *recipientManager;
    const string RECIPIENTS_FILE_NAME;
    const string TEMPORARY_RECIPIENTS_FILE_NAME;

public:

    AddressBook(string usersFileName="Users.txt",string recipientsFileName="Recipients.txt",string temporaryRecipientsFileName="Recipients_temp.txt");
    ~AddressBook();
    void registerUser();
    void listAllUsers();
    void logIn();
    void changePasswordOfLoggedInUser();
    void addRecipient();
    void listAllRecipients();
    void logOut();
    char selectChoiceFromUserMenu();
    char selectChoiceFromMainMenu();
    bool isUserLoggedIn();
    void deleteRecipient();
    void editRecipient();
    void searchRecipientsByName();
    void searchRecipientsBySurname();

};

#endif
