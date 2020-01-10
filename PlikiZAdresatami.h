#ifndef PLIKIZADRESATAMI_H
#define PLIKIZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"
#include <fstream>

using namespace std;

class PlikiZAdresatami :public PlikTekstowy
{
    const string TEMPORARY_RECIPIENTS_FILE_NAME;
    int lastRecipientId;

    string changeRecipientDataOnLineWithDataSeparatedByPipe(Adresat recipient);
    int getUserIdFromDataSepararatedByPipe(string userDataSeparatedByPipe);
    Adresat getRecipientData(string recipientDataSeparatedByPipe);
    int getRecipientIdFromDataSepararatedByPipe(string recipientDataSeparatedByPipe);
    void removeFile(string fileNameWithExtension);
    void changeFileName(string oldName, string newName);
    int giveLastRecipientIdAfterRemovingRecipient(int removedRecipientId);
    int getLastRecipientIdFromFile();

public:
    PlikiZAdresatami(string,string);
    bool appendRecipientToFile(Adresat recipient);
    vector <Adresat> loadLoggedUserRecipientsFromFile(int loggedUserId);
    int getlastRecipientId();
    int removeRecipientFromFile(int recipientId);
    void updateDataOfEditedRecipient(Adresat adresat);
};

#endif
