#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook;

    char choice;

    while (true)
    {
        if (addressBook.isUserLoggedIn() == false)
        {
            choice = addressBook.selectChoiceFromMainMenu();

            switch (choice)
            {
            case '1':
                addressBook.registerUser();
                break;
            case '2':
                addressBook.logIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = addressBook.selectChoiceFromUserMenu();

            switch (choice)
            {
            case '1':
                addressBook.addRecipient();
                break;
            case '2':
                addressBook.searchRecipientsByName();
                break;
            case '3':
                addressBook.searchRecipientsBySurname();
                break;
            case '4':
                addressBook.listAllRecipients();
                break;
            case '5':
                addressBook.deleteRecipient();
                break;
            case '6':
                addressBook.editRecipient();
                break;
            case '7':
                addressBook.changePasswordOfLoggedInUser();
                break;
            case '8':
                addressBook.logOut();
                break;
            }
        }
    }

    return 0;
}
