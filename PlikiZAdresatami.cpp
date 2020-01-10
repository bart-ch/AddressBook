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

        if (ifFileEmpty() == true)
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
    string singleRecipientData = "";
    int numberOfSingleRecipientData = 1;

    for (int signPosition = 0; signPosition < recipientDataSeparatedByPipe.length(); signPosition++)
    {
        if (recipientDataSeparatedByPipe[signPosition] != '|')
        {
            singleRecipientData += recipientDataSeparatedByPipe[signPosition];
        }
        else
        {
            switch(numberOfSingleRecipientData)
            {
            case 1:
                recipient.setRecipientId(atoi(singleRecipientData.c_str()));
                break;
            case 2:
                recipient.setUserId(atoi(singleRecipientData.c_str()));
                break;
            case 3:
                recipient.setName(singleRecipientData);
                break;
            case 4:
                recipient.setSurname(singleRecipientData);
                break;
            case 5:
                recipient.setTelephone(singleRecipientData);
                break;
            case 6:
                recipient.setEmail(singleRecipientData);
                break;
            case 7:
                recipient.setAddress(singleRecipientData);
                break;
            }
            singleRecipientData = "";
            numberOfSingleRecipientData++;
        }
    }
    return recipient;
}

int PlikiZAdresatami::getlastRecipientId()
{
    return lastRecipientId;
}

int PlikiZAdresatami::removeRecipientFromFile(int idUsuwanegoAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string recipientDataSeparatedByPipe = "";
    int numerWczytanejLinii = 1;
    int numerUsuwanejLinii = 0;
    string wczytanaLinia = "";
    odczytywanyPlikTekstowy.open(getFileName().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(TEMPORARY_RECIPIENTS_FILE_NAME.c_str(), ios::out | ios::app);


    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0)
    {
        while(getline(odczytywanyPlikTekstowy, recipientDataSeparatedByPipe))
        {
            wczytanaLinia = recipientDataSeparatedByPipe;

            if(idUsuwanegoAdresata == getRecipientIdFromDataSepararatedByPipe(recipientDataSeparatedByPipe))
            {
                numerUsuwanejLinii = numerWczytanejLinii;
            }

            if (numerWczytanejLinii == numerUsuwanejLinii) {}
            else if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << wczytanaLinia;
            else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
            numerWczytanejLinii++;
        }
    }

    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    removeFile(getFileName());
    changeFileName(TEMPORARY_RECIPIENTS_FILE_NAME, getFileName());

    lastRecipientId = giveLastRecipientIdafterRemovingRecipient(idUsuwanegoAdresata);

    return lastRecipientId;

}

void PlikiZAdresatami::removeFile(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikiZAdresatami::changeFileName(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

int PlikiZAdresatami::giveLastRecipientIdafterRemovingRecipient(int idUsuwanegoAdresata)
{
    if (idUsuwanegoAdresata == lastRecipientId)
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
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (lastRecipientInFileData != "")
    {
        lastRecipientId = getRecipientIdFromDataSepararatedByPipe(lastRecipientInFileData);
    }
    return lastRecipientId;
}

void PlikiZAdresatami::updateDataOfEditedRecipient(Adresat adresat)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    string recipientDataSeparatedByPipe = "";
    string liniaZDanymiAdresataOddzielonePionowymiKreskami = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(getFileName().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(TEMPORARY_RECIPIENTS_FILE_NAME.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && adresat.getRecipientId() != 0)
    {
        while (getline(odczytywanyPlikTekstowy, recipientDataSeparatedByPipe))
        {
            wczytanaLinia = recipientDataSeparatedByPipe;

            if (adresat.getRecipientId() == getRecipientIdFromDataSepararatedByPipe(recipientDataSeparatedByPipe))
            {
                liniaZDanymiAdresataOddzielonePionowymiKreskami = changeRecipientDataOnLineWithDataSeparatedByPipe(adresat);

                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        removeFile(getFileName());
        changeFileName(TEMPORARY_RECIPIENTS_FILE_NAME, getFileName());
    }
}
