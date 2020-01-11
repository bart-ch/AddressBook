#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer userManager;
    AdresatMenedzer *recipientManager;
    const string RECIPIENTS_FILE_NAME;
    const string TEMPORARY_RECIPIENTS_FILE_NAME;

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami="Uzytkownicy.txt",string nazwaPlikuZAdresatami="Adresaci.txt",string nazwaPlikuTymczasowegoZAdresatami="Adresaci_tymczas.txt");
    ~KsiazkaAdresowa();
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
