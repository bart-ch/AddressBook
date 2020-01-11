#ifndef RECIPIENTSFILES_H
#define RECIPIENTSFILES_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Recipient.h"
#include "AncillaryMethods.h"
#include "UserManager.h"
#include <fstream>

using namespace std;

class RecipientsFiles :public TextFile
{
    const string TEMPORARY_RECIPIENTS_FILE_NAME;
    int lastRecipientId;

    string changeRecipientDataOnLineWithDataSeparatedByPipe(Recipient recipient);
    int getUserIdFromDataSepararatedByPipe(string userDataSeparatedByPipe);
    Recipient getRecipientData(string recipientDataSeparatedByPipe);
    int getRecipientIdFromDataSepararatedByPipe(string recipientDataSeparatedByPipe);
    void removeFile(string fileNameWithExtension);
    void changeFileName(string oldName, string newName);
    int giveLastRecipientIdAfterRemovingRecipient(int removedRecipientId);
    int getLastRecipientIdFromFile();

public:
    RecipientsFiles(string,string);
    bool appendRecipientToFile(Recipient recipient);
    vector <Recipient> loadLoggedUserRecipientsFromFile(int loggedUserId);
    int getlastRecipientId();
    int removeRecipientFromFile(int recipientId);
    void updateDataOfEditedRecipient(Recipient adresat);
};

#endif
