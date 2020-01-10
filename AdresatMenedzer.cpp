#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer(string recipientTextFile, string temporaryRecipientTextFile, int loggedUserId)
    : recipientsFiles(recipientTextFile,temporaryRecipientTextFile),
      LOGGED_USER_ID(loggedUserId)
{
    recipients = recipientsFiles.loadLoggedUserRecipientsFromFile(LOGGED_USER_ID);
}

void AdresatMenedzer::addRecipient()
{
    Adresat recipient;

    system("cls");
    cout << " >>> NEW RECIPIENT MENU <<<" << endl << endl;
    recipient = enterNewRecipientData();

    recipients.push_back(recipient);
    if(recipientsFiles.appendRecipientToFile(recipient))
        cout << "New recipient has been added." << endl;
    else
        cout << "Failed to append new recipient to file." << endl;

    system("Pause");

}

Adresat AdresatMenedzer::enterNewRecipientData()
{
    Adresat recipient;
    string name,surname,phoneNumber,email,address;

    recipient.setRecipientId(recipientsFiles.getlastRecipientId() + 1);
    recipient.setUserId(LOGGED_USER_ID);

    cout << "Enter name: ";
    name = MetodyPomocnicze::wczytajLinie();
    name = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(name);

    cout << "Enter surname: ";
    surname = MetodyPomocnicze::wczytajLinie();
    surname = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(surname);

    cout << "Enter phone number: ";
    phoneNumber = MetodyPomocnicze::wczytajLinie();

    cout << "Enter email address: ";
    email = MetodyPomocnicze::wczytajLinie();

    cout << "Enter address: ";
    address = MetodyPomocnicze::wczytajLinie();

    recipient.setName(name);
    recipient.setSurname(surname);
    recipient.setTelephone(phoneNumber);
    recipient.setEmail(email);
    recipient.setAddress(address);

    return recipient;
}

void AdresatMenedzer::listAllRecipients()
{
    if(recipients.empty() == true)
    {
        cout << "Address book is empty." << endl;
        system("pause");
        return;
    }
    else
    {
        for(int i = 0; i < recipients.size(); i++)
        {
            cout << "ID: " << recipients[i].getRecipientId() << endl;
            cout << "Name: " << recipients[i].getName() << endl;
            cout << "Surname: " << recipients[i].getSurname() << endl;
            cout << "Phone number: " << recipients[i].getTelephone() << endl;
            cout << "Email address: " << recipients[i].getEmail() << endl;
            cout << "Address: " << recipients[i].getAddress() << endl << endl;
        }
        system("pause");
    }
}

int AdresatMenedzer::deleteRecipient()
{
    int deletedRecipientId = 0;

    system("cls");
    cout << ">>> DELETE RECIPIENT MENU <<<" << endl << endl;
    deletedRecipientId = enterRecipientId();

    char sign;
    bool isRecipientExists = false;

    for (int i = 0; i < recipients.size(); i++)
    {
        if (recipients[i].getRecipientId() == deletedRecipientId)
        {
            isRecipientExists = true;
            cout << endl << "To confirm press 't': ";
            sign = MetodyPomocnicze::wczytajZnak();
            if (sign == 't')
            {
                recipientsFiles.removeRecipientFromFile(deletedRecipientId);
                recipients.erase(recipients.begin()+ i);
                cout << endl << endl << "The recipient has been DELETED" << endl << endl;
                system("pause");
                return deletedRecipientId;
            }
            else
            {
                cout << endl << endl << "Failed to delete the recipient" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (isRecipientExists == false)
    {
        cout << endl << "The recipient does not exist." << endl << endl;
        system("pause");
    }
    return 0;
}

int AdresatMenedzer::enterRecipientId()
{
    int recipientId = 0;
    cout << "Enter recipient ID: ";
    recipientId  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return recipientId;
}

void AdresatMenedzer::editRecipient()
{
    system("cls");
    string newSingleData = "";
    int editedRecipientId = 0;

    cout << ">>> EDIT RECIPIENT MENU <<<" << endl << endl;
    editedRecipientId = enterRecipientId();

    char sign;
    bool doesRecipientExist = false;

    for (int i = 0; i < recipients.size(); i++)
    {
        if (recipients[i].getRecipientId() == editedRecipientId)
        {
            doesRecipientExist = true;
            sign = wybierzOpcjeZMenuEdycja();

            switch (sign)
            {
            case '1':
                cout << "Enter new name: ";
                newSingleData = MetodyPomocnicze::wczytajLinie();
                newSingleData = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(newSingleData);
                recipients[i].setName(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '2':
                cout << "Enter new surname: ";
                newSingleData = MetodyPomocnicze::wczytajLinie();
                newSingleData = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(newSingleData);
                recipients[i].setSurname(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '3':
                cout << "Enter new phone number: ";
                newSingleData = MetodyPomocnicze::wczytajLinie();
                recipients[i].setTelephone(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '4':
                cout << "Enter new email address: ";
                newSingleData = MetodyPomocnicze::wczytajLinie();
                recipients[i].setEmail(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '5':
                cout << "Enter new address: ";
                newSingleData = MetodyPomocnicze::wczytajLinie();
                recipients[i].setAddress(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '6':
                cout << endl << "Returning to the user menu." << endl << endl;
                break;
            default:
                cout << endl << "Invalid number! Returning to the user menu." << endl << endl;
                break;
            }
        }
    }
    if (doesRecipientExist == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja()
{
    char sign;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    sign = MetodyPomocnicze::wczytajZnak();

    return sign;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getName() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.getRecipientId() << endl;
    cout << "Imie:               " << adresat.getName() << endl;
    cout << "Nazwisko:           " << adresat.getSurname() << endl;
    cout << "Numer telefonu:     " << adresat.getTelephone() << endl;
    cout << "Email:              " << adresat.getEmail() << endl;
    cout << "Adres:              " << adresat.getAddress() << endl;
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getSurname() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

