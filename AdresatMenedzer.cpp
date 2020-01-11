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
    name = MetodyPomocnicze::getSingleLine();
    name = MetodyPomocnicze::replaceFirstLetterUppercaseAndOtherLowercase(name);

    cout << "Enter surname: ";
    surname = MetodyPomocnicze::getSingleLine();
    surname = MetodyPomocnicze::replaceFirstLetterUppercaseAndOtherLowercase(surname);

    cout << "Enter phone number: ";
    phoneNumber = MetodyPomocnicze::getSingleLine();

    cout << "Enter email address: ";
    email = MetodyPomocnicze::getSingleLine();

    cout << "Enter address: ";
    address = MetodyPomocnicze::getSingleLine();

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

    char choice;
    bool doesRecipientExist = false;

    for (int i = 0; i < recipients.size(); i++)
    {
        if (recipients[i].getRecipientId() == deletedRecipientId)
        {
            doesRecipientExist = true;
            cout << endl << "To confirm press 't': ";
            choice = MetodyPomocnicze::getCharacter();
            if (choice == 't')
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
    if (doesRecipientExist == false)
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
    recipientId  = MetodyPomocnicze::getInteger();
    return recipientId;
}

void AdresatMenedzer::editRecipient()
{
    system("cls");
    string newSingleData = "";
    int editedRecipientId = 0;

    cout << ">>> EDIT RECIPIENT <<<" << endl << endl;
    editedRecipientId = enterRecipientId();

    char sign;
    bool doesRecipientExist = false;

    for (int i = 0; i < recipients.size(); i++)
    {
        if (recipients[i].getRecipientId() == editedRecipientId)
        {
            doesRecipientExist = true;
            sign = selectChoiceFromEditMenu();

            switch (sign)
            {
            case '1':
                cout << "Enter new name: ";
                newSingleData = MetodyPomocnicze::getSingleLine();
                newSingleData = MetodyPomocnicze::replaceFirstLetterUppercaseAndOtherLowercase(newSingleData);
                recipients[i].setName(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '2':
                cout << "Enter new surname: ";
                newSingleData = MetodyPomocnicze::getSingleLine();
                newSingleData = MetodyPomocnicze::replaceFirstLetterUppercaseAndOtherLowercase(newSingleData);
                recipients[i].setSurname(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '3':
                cout << "Enter new phone number: ";
                newSingleData = MetodyPomocnicze::getSingleLine();
                recipients[i].setTelephone(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '4':
                cout << "Enter new email address: ";
                newSingleData = MetodyPomocnicze::getSingleLine();
                recipients[i].setEmail(newSingleData);
                recipientsFiles.updateDataOfEditedRecipient(recipients[i]);
                break;
            case '5':
                cout << "Enter new address: ";
                newSingleData = MetodyPomocnicze::getSingleLine();
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
        cout << endl << "Wrong ID number." << endl << endl;
    }
    system("pause");
}

char AdresatMenedzer::selectChoiceFromEditMenu()
{
    char choice;

    cout << endl << "   >>> EDIT MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "What would you like to edit: " << endl;
    cout << "1 - Name" << endl;
    cout << "2 - Surname" << endl;
    cout << "3 - Phone number" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Address" << endl;
    cout << "6 - Return " << endl;
    cout << endl << "Your choice: ";
    choice = MetodyPomocnicze::getCharacter();

    return choice;
}

void AdresatMenedzer::searchRecipientsByName()
{
    string searchedName = "";
    int recipientsNumber = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> SEARCHING BY NAME <<<" << endl << endl;

        cout << "Enter the name you are looking for: ";
        searchedName = MetodyPomocnicze::getSingleLine();
        searchedName = MetodyPomocnicze::replaceFirstLetterUppercaseAndOtherLowercase(searchedName);

        for (vector <Adresat>::iterator  itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getName() == searchedName)
            {
                showRecipientData(*itr);
                recipientsNumber++;
            }
        }
        showNumberOfFoundRecipients(recipientsNumber);
    }
    else
    {
        cout << endl << "Address book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::showRecipientData(Adresat recipient)
{
    cout << endl << "Id:                 " << recipient.getRecipientId() << endl;
    cout << "Name:               " << recipient.getName() << endl;
    cout << "Surname:           " << recipient.getSurname() << endl;
    cout << "Phone number:     " << recipient.getTelephone() << endl;
    cout << "Email:              " << recipient.getEmail() << endl;
    cout << "Address:              " << recipient.getAddress() << endl;
}

void AdresatMenedzer::showNumberOfFoundRecipients(int recipientsNumber)
{
    if (recipientsNumber == 0)
        cout << endl << "No recipients with the data." << endl;
    else
        cout << endl << "The number of recipients is: " << recipientsNumber << endl << endl;
}

void AdresatMenedzer::searchRecipientsBySurname()
{
    string searchedSurname;
    int recipientsNumber = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> SEARCHING BY SURNAME <<<" << endl << endl;

        cout << "Enter the surname you are looking for: : ";
        searchedSurname = MetodyPomocnicze::getSingleLine();
        searchedSurname = MetodyPomocnicze::replaceFirstLetterUppercaseAndOtherLowercase(searchedSurname);

        for (vector <Adresat>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getSurname() == searchedSurname)
            {
                showRecipientData(*itr);
                recipientsNumber++;
            }
        }
        showNumberOfFoundRecipients(recipientsNumber);
    }
    else
    {
        cout << endl << "Address book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}

