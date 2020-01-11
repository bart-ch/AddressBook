#include "AddressBook.h"

AddressBook::AddressBook(string usersFileName,string recipientsFileName,string temporaryRecipientsFileName)
    : userManager(usersFileName),
      RECIPIENTS_FILE_NAME(recipientsFileName),
    TEMPORARY_RECIPIENTS_FILE_NAME(temporaryRecipientsFileName)
{
}

AddressBook::~AddressBook()
{
    delete recipientManager;
    recipientManager = NULL;
}

void AddressBook::registerUser()
{
    userManager.registerAUser();
}

void AddressBook::listAllUsers()
{
    userManager.listAllUsers();
}

void AddressBook::logIn()
{
    userManager.logIn();
    if(userManager.isUserLoggedIn())
    {
        recipientManager = new RecipientManager(RECIPIENTS_FILE_NAME,TEMPORARY_RECIPIENTS_FILE_NAME,userManager.getLoggedInUserId());
    }
}

void AddressBook::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedInUser();
}

void AddressBook::addRecipient()
{
    if(userManager.isUserLoggedIn())
    {
        recipientManager->addRecipient();
    }
}

void AddressBook::listAllRecipients()
{
    recipientManager->listAllRecipients();
}

void AddressBook::logOut()
{
    userManager.logOut();
    delete recipientManager;
    recipientManager = NULL;
}

char AddressBook::selectChoiceFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add recipient" << endl;
    cout << "2. Search by name" << endl;
    cout << "3. Search by surname" << endl;
    cout << "4. Show all recipients" << endl;
    cout << "5. Delete recipient" << endl;
    cout << "6. Edit recipient" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AncillaryMethods::getCharacter();

    return choice;
}

char AddressBook::selectChoiceFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AncillaryMethods::getCharacter();

    return choice;
}

bool AddressBook::isUserLoggedIn()
{
    if(userManager.isUserLoggedIn())
        return true;
    else
        return false;
}

void AddressBook::deleteRecipient()
{
     recipientManager->deleteRecipient();
}

void AddressBook::editRecipient()
{
    recipientManager->editRecipient();
}

void AddressBook::searchRecipientsByName()
{
    recipientManager->searchRecipientsByName();
}

void AddressBook::searchRecipientsBySurname()
{
    recipientManager->searchRecipientsBySurname();
}




