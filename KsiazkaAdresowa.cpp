#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami,string nazwaPlikuZAdresatami,string nazwaPlikuTymczasowegoZAdresatami)
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
      NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami),
    NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI(nazwaPlikuTymczasowegoZAdresatami)
{
}

KsiazkaAdresowa::~KsiazkaAdresowa()
{
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.registerAUser();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.listAllUsers();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logIn();
    if(uzytkownikMenedzer.isUserLoggedIn())
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI,uzytkownikMenedzer.getLoggedInUserId());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.changePasswordOfLoggedInUser();
}

void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenedzer.isUserLoggedIn())
    {
        adresatMenedzer->addRecipient();
    }
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatMenedzer->listAllRecipients();
}

void KsiazkaAdresowa::wyloguj()
{
    uzytkownikMenedzer.logOut();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
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

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
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

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if(uzytkownikMenedzer.isUserLoggedIn())
        return true;
    else
        return false;
}

void KsiazkaAdresowa::usunaAdresata()
{
     adresatMenedzer->deleteRecipient();
}

void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenedzer->editRecipient();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatMenedzer->searchRecipientsByName();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    adresatMenedzer->searchRecipientsBySurname();
}




