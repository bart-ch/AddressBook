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
    char wybierzOpcjeZMenuEdycja();
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);

public:

    AdresatMenedzer(string recipientTextFile, string temporaryRecipientTextFile, int loggedUserId);
    void addRecipient();
    void listAllRecipients();
    int deleteRecipient();
    void editRecipient();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
};

#endif // ADRESATMENEDZER_H
