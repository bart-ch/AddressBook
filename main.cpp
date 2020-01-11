#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazka;

    char choice;

    while (true)
    {
        if (ksiazka.isUserLoggedIn() == false)
        {
            choice = ksiazka.selectChoiceFromMainMenu();

            switch (choice)
            {
            case '1':
                ksiazka.registerUser();
                break;
            case '2':
                ksiazka.logIn();
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
            choice = ksiazka.selectChoiceFromUserMenu();

            switch (choice)
            {
            case '1':
                ksiazka.addRecipient();
                break;
            case '2':
                ksiazka.searchRecipientsByName();
                break;
            case '3':
                ksiazka.searchRecipientsBySurname();
                break;
            case '4':
                ksiazka.listAllRecipients();
                break;
            case '5':
                ksiazka.deleteRecipient();
                break;
            case '6':
                ksiazka.editRecipient();
                break;
            case '7':
                ksiazka.changePasswordOfLoggedInUser();
                break;
            case '8':
                ksiazka.logOut();
                break;
            }
        }
    }

    return 0;
}
