#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string usersFileName,string recipientsFileName,string temporaryRecipientsFileName)
    : userManager(usersFileName),
      RECIPIENTS_FILE_NAME(recipientsFileName),
    TEMPORARY_RECIPIENTS_FILE_NAME(temporaryRecipientsFileName)
{
}

KsiazkaAdresowa::~KsiazkaAdresowa()
{
    delete recipientManager;
    recipientManager = NULL;
}

void KsiazkaAdresowa::registerUser()
{
    userManager.registerAUser();
}

void KsiazkaAdresowa::listAllUsers()
{
    userManager.listAllUsers();
}

void KsiazkaAdresowa::logIn()
{
    userManager.logIn();
    if(userManager.isUserLoggedIn())
    {
        recipientManager = new AdresatMenedzer(RECIPIENTS_FILE_NAME,TEMPORARY_RECIPIENTS_FILE_NAME,userManager.getLoggedInUserId());
    }
}

void KsiazkaAdresowa::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedInUser();
}

void KsiazkaAdresowa::addRecipient()
{
    if(userManager.isUserLoggedIn())
    {
        recipientManager->addRecipient();
    }
}

void KsiazkaAdresowa::listAllRecipients()
{
    recipientManager->listAllRecipients();
}

void KsiazkaAdresowa::logOut()
{
    userManager.logOut();
    delete recipientManager;
    recipientManager = NULL;
}

char KsiazkaAdresowa::selectChoiceFromUserMenu()
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
    choice = MetodyPomocnicze::getCharacter();

    return choice;
}

char KsiazkaAdresowa::selectChoiceFromMainMenu()
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
    choice = MetodyPomocnicze::getCharacter();

    return choice;
}

bool KsiazkaAdresowa::isUserLoggedIn()
{
    if(userManager.isUserLoggedIn())
        return true;
    else
        return false;
}

void KsiazkaAdresowa::deleteRecipient()
{
     recipientManager->deleteRecipient();
}

void KsiazkaAdresowa::editRecipient()
{
    recipientManager->editRecipient();
}

void KsiazkaAdresowa::searchRecipientsByName()
{
    recipientManager->searchRecipientsByName();
}

void KsiazkaAdresowa::searchRecipientsBySurname()
{
    recipientManager->searchRecipientsBySurname();
}




