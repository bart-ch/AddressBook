#include "RecipientsFiles.h"

using namespace std;

RecipientsFiles::RecipientsFiles(string fileName,string temporaryFileName)
    :   TextFile(fileName),
        TEMPORARY_RECIPIENTS_FILE_NAME(temporaryFileName)
{
    lastRecipientId = 0;
}

bool RecipientsFiles::appendRecipientToFile(Recipient recipient)
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

string RecipientsFiles::changeRecipientDataOnLineWithDataSeparatedByPipe(Recipient recipient)
{
    string lineWithRecipientData = "";

    lineWithRecipientData += AncillaryMethods::IntToStringConversion(recipient.getRecipientId()) + '|';
    lineWithRecipientData += AncillaryMethods::IntToStringConversion(recipient.getUserId()) + '|';
    lineWithRecipientData += recipient.getName() + '|';
    lineWithRecipientData += recipient.getSurname() + '|';
    lineWithRecipientData += recipient.getTelephone() + '|';
    lineWithRecipientData += recipient.getEmail() + '|';
    lineWithRecipientData += recipient.getAddress() + '|';

    return lineWithRecipientData;
}

vector <Recipient> RecipientsFiles::loadLoggedUserRecipientsFromFile(int loggedUserId)
{
    vector <Recipient> recipients;
    Recipient recipient;
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

int RecipientsFiles::getUserIdFromDataSepararatedByPipe(string userDataSeparatedByPipe)
{
    int userIdStartPosition = userDataSeparatedByPipe.find_first_of('|') + 1;
    int userId = AncillaryMethods::StringToIntConversion(AncillaryMethods::getNumber(userDataSeparatedByPipe, userIdStartPosition));

    return userId;
}

int RecipientsFiles::getRecipientIdFromDataSepararatedByPipe(string recipientDataSeparatedByPipe)
{
    int recipientIdStartPosition = 0;
    int recipientId = AncillaryMethods::StringToIntConversion(AncillaryMethods::getNumber(recipientDataSeparatedByPipe, recipientIdStartPosition));
    return recipientId;
}

Recipient RecipientsFiles::getRecipientData(string recipientDataSeparatedByPipe)
{
    Recipient recipient;
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

int RecipientsFiles::getlastRecipientId()
{
    return lastRecipientId;
}

int RecipientsFiles::removeRecipientFromFile(int recipientId)
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

void RecipientsFiles::removeFile(string fileNameWithExtension)
{
    if (remove(fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "Failed to delete the file " << fileNameWithExtension << endl;
}

void RecipientsFiles::changeFileName(string oldName, string newName)
{
    if (rename(oldName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "Name of the file could not be changed." << oldName << endl;
}

int RecipientsFiles::giveLastRecipientIdAfterRemovingRecipient(int removedRecipientId)
{
    if (removedRecipientId == lastRecipientId)
        return getLastRecipientIdFromFile();
    else
        return lastRecipientId;
}

int RecipientsFiles::getLastRecipientIdFromFile()
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

void RecipientsFiles::updateDataOfEditedRecipient(Recipient recipient)
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
