#include "PlikiZAdresatami.h"

using namespace std;

PlikiZAdresatami::PlikiZAdresatami(string fileName,string temporaryFileName)
    :   PlikTekstowy(fileName),
        TEMPORARY_RECIPIENTS_FILE_NAME(temporaryFileName)
{
    lastRecipientId = 0;
}

bool PlikiZAdresatami::appendRecipientToFile(Adresat recipient)
{
    string lineWithRecipientData = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithRecipientData = changeRecipientDataOnLineWithDataSeparatedByPipe(recipient);

        if (isFileEmpty() == true)
        {
            textFile << lineWithRecipientData;
        }
        else
        {
            textFile << endl << lineWithRecipientData ;
        }
        lastRecipientId++;
        textFile.close();
        return true;
    }
    return false;
}

string PlikiZAdresatami::changeRecipientDataOnLineWithDataSeparatedByPipe(Adresat recipient)
{
    string lineWithRecipientData = "";

    lineWithRecipientData += MetodyPomocnicze::konwerjsaIntNaString(recipient.getRecipientId()) + '|';
    lineWithRecipientData += MetodyPomocnicze::konwerjsaIntNaString(recipient.getUserId()) + '|';
    lineWithRecipientData += recipient.getName() + '|';
    lineWithRecipientData += recipient.getSurname() + '|';
    lineWithRecipientData += recipient.getTelephone() + '|';
    lineWithRecipientData += recipient.getEmail() + '|';
    lineWithRecipientData += recipient.getAddress() + '|';

    return lineWithRecipientData;
}

vector <Adresat> PlikiZAdresatami::loadLoggedUserRecipientsFromFile(int loggedUserId)
{
    vector <Adresat> recipients;
    Adresat recipient;
    string recipientDataSeparatedByPipe = "";
    string lastRecipientInFileData = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, recipientDataSeparatedByPipe))
        {
            if(loggedUserId == getUserIdFromDataSepararatedByPipe(recipientDataSeparatedByPipe))
            {
                recipient = getRecipientData(recipientDataSeparatedByPipe);
                recipients.push_back(recipient);
            }
        }
        lastRecipientInFileData = recipientDataSeparatedByPipe;
    }
    else
        cout << "Could not open a file and load data." << endl;

    textFile.close();

    if (lastRecipientInFileData != "")
    {
        lastRecipientId = getRecipientIdFromDataSepararatedByPipe(lastRecipientInFileData);
    }
    return recipients;
}

int PlikiZAdresatami::getUserIdFromDataSepararatedByPipe(string userDataSeparatedByPipe)
{
    int userIdStartPosition = userDataSeparatedByPipe.find_first_of('|') + 1;
    int userId = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(userDataSeparatedByPipe, userIdStartPosition));

    return userId;
}

int PlikiZAdresatami::getRecipientIdFromDataSepararatedByPipe(string recipientDataSeparatedByPipe)
{
    int recipientIdStartPosition = 0;
    int recipientId = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(recipientDataSeparatedByPipe, recipientIdStartPosition));
    return recipientId;
}

Adresat PlikiZAdresatami::getRecipientData(string recipientDataSeparatedByPipe)
{
    Adresat recipient;
    string separatedRecipientData = "";
    int numberOfSeparatedRecipientData = 1;

    for (int signPosition = 0; signPosition < recipientDataSeparatedByPipe.length(); signPosition++)
    {
        if (recipientDataSeparatedByPipe[signPosition] != '|')
        {
            separatedRecipientData += recipientDataSeparatedByPipe[signPosition];
        }
        else
        {
            switch(numberOfSeparatedRecipientData)
            {
            case 1:
                recipient.setRecipientId(atoi(separatedRecipientData.c_str()));
                break;
            case 2:
                recipient.setUserId(atoi(separatedRecipientData.c_str()));
                break;
            case 3:
                recipient.setName(separatedRecipientData);
                break;
            case 4:
                recipient.setSurname(separatedRecipientData);
                break;
            case 5:
                recipient.setTelephone(separatedRecipientData);
                break;
            case 6:
                recipient.setEmail(separatedRecipientData);
                break;
            case 7:
                recipient.setAddress(separatedRecipientData);
                break;
            }
            separatedRecipientData = "";
            numberOfSeparatedRecipientData++;
        }
    }
    return recipient;
}

int PlikiZAdresatami::getlastRecipientId()
{
    return lastRecipientId;
}

int PlikiZAdresatami::removeRecipientFromFile(int recipientId)
{
    fstream baseTextFile, temporaryTextFile;
    string recipientDataSeparatedByPipe = "";
    int loadedLineNumber = 1;
    int removedLineNumber = 0;
    string loadedLine = "";
    baseTextFile.open(getFileName().c_str(), ios::in);
    temporaryTextFile.open(TEMPORARY_RECIPIENTS_FILE_NAME.c_str(), ios::out | ios::app);

    if (baseTextFile.good() == true && recipientId != 0)
    {
        while(getline(baseTextFile, recipientDataSeparatedByPipe))
        {
            loadedLine = recipientDataSeparatedByPipe;

            if(recipientId == getRecipientIdFromDataSepararatedByPipe(recipientDataSeparatedByPipe))
            {
                removedLineNumber = loadedLineNumber;
            }

            if (loadedLineNumber == removedLineNumber) {}
            else if (loadedLineNumber == 1 && loadedLineNumber != removedLineNumber)
                temporaryTextFile << loadedLine;
            else if (loadedLineNumber == 2 && removedLineNumber == 1)
                temporaryTextFile << loadedLine;
            else if (loadedLineNumber > 2 && removedLineNumber == 1)
                temporaryTextFile << endl << loadedLine;
            else if (loadedLineNumber > 1 && removedLineNumber != 1)
                temporaryTextFile << endl << loadedLine;
            loadedLineNumber++;
        }
    }

    baseTextFile.close();
    temporaryTextFile.close();

    removeFile(getFileName());
    changeFileName(TEMPORARY_RECIPIENTS_FILE_NAME, getFileName());

    lastRecipientId = giveLastRecipientIdAfterRemovingRecipient(recipientId);

    return lastRecipientId;

}

void PlikiZAdresatami::removeFile(string fileNameWithExtension)
{
    if (remove(fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "Failed to delete the file " << fileNameWithExtension << endl;
}

void PlikiZAdresatami::changeFileName(string oldName, string newName)
{
    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Name of the file could not be changed." << oldName << endl;
}

int PlikiZAdresatami::giveLastRecipientIdAfterRemovingRecipient(int removedRecipientId)
{
    if (removedRecipientId == lastRecipientId)
        return getLastRecipientIdFromFile();
    else
        return lastRecipientId;
}

int PlikiZAdresatami::getLastRecipientIdFromFile()
{
    string recipientDataSeparatedByPipe = "";
    string lastRecipientInFileData = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, recipientDataSeparatedByPipe)) {}
        lastRecipientInFileData = recipientDataSeparatedByPipe;
        textFile.close();
    }
    else
        cout << "Could not open a file and load data." << endl;

    if (lastRecipientInFileData != "")
    {
        lastRecipientId = getRecipientIdFromDataSepararatedByPipe(lastRecipientInFileData);
    }
    return lastRecipientId;
}

void PlikiZAdresatami::updateDataOfEditedRecipient(Adresat recipient)
{
    fstream baseTextFile, temporaryTextFile;
    string loadedLine = "";
    string recipientDataSeparatedByPipe = "";
    string recipientDataInLineSeparatedByPipe = "";
    int loadedLineNumber = 1;

    baseTextFile.open(getFileName().c_str(), ios::in);
    temporaryTextFile.open(TEMPORARY_RECIPIENTS_FILE_NAME.c_str(), ios::out | ios::app);

    if (baseTextFile.good() == true && recipient.getRecipientId() != 0)
    {
        while (getline(baseTextFile, recipientDataSeparatedByPipe))
        {
            loadedLine = recipientDataSeparatedByPipe;

            if (recipient.getRecipientId() == getRecipientIdFromDataSepararatedByPipe(recipientDataSeparatedByPipe))
            {
                recipientDataInLineSeparatedByPipe = changeRecipientDataOnLineWithDataSeparatedByPipe(recipient);

                if (loadedLineNumber == 1)
                    temporaryTextFile << recipientDataInLineSeparatedByPipe;
                else if (loadedLineNumber > 1)
                    temporaryTextFile << endl << recipientDataInLineSeparatedByPipe;
            }
            else
            {
                if (loadedLineNumber == 1)
                    temporaryTextFile << loadedLine;
                else if (loadedLineNumber > 1)
                    temporaryTextFile << endl << loadedLine;
            }
            loadedLineNumber++;
        }
        baseTextFile.close();
        temporaryTextFile.close();

        removeFile(getFileName());
        changeFileName(TEMPORARY_RECIPIENTS_FILE_NAME, getFileName());
    }
}
