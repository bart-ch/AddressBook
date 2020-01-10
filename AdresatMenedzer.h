#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "PlikiZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"

class AdresatMenedzer
{
    const int LOGGED_USER_ID;
    vector <Adresat> recipients;
    PlikiZAdresatami recipientsFiles;

    Adresat enterNewRecipientData();
    int enterRecipientId();
    char selectChoiceFromEditMenu();
    void showRecipientData(Adresat recipient);
    void showNumberOfFoundRecipients(int iloscAdresatow);

public:

    AdresatMenedzer(string recipientTextFile, string temporaryRecipientTextFile, int loggedUserId);
    void addRecipient();
    void listAllRecipients();
    int deleteRecipient();
    void editRecipient();
    void searchRecipientsByName();
    void searchRecipientsBySurname();
};

#endif // ADRESATMENEDZER_H
