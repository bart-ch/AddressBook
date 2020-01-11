#ifndef RECIPIENTMANAGER_H
#define RECIPIENTMANAGER_H

#include "RecipientsFiles.h"
#include "AncillaryMethods.h"
#include "UserManager.h"

class RecipientManager
{
    const int LOGGED_USER_ID;
    vector <Recipient> recipients;
    RecipientsFiles recipientsFiles;

    Recipient enterNewRecipientData();
    int enterRecipientId();
    char selectChoiceFromEditMenu();
    void showRecipientData(Recipient recipient);
    void showNumberOfFoundRecipients(int iloscAdresatow);

public:

    RecipientManager(string recipientTextFile, string temporaryRecipientTextFile, int loggedUserId);
    void addRecipient();
    void listAllRecipients();
    int deleteRecipient();
    void editRecipient();
    void searchRecipientsByName();
    void searchRecipientsBySurname();
};

#endif // ADRESATMENEDZER_H
