#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
    : plikiZAdresatami(nazwaPlikuZAdresatami),
      ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
{
    adresaci = plikiZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
}

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikiZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;

    system("Pause");

}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie,nazwisko,numerTelefonu,email,adres;

    adresat.ustawIdAdresata(plikiZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wypiszWszystkichAdresatow()
{
    if(adresaci.empty() == true)
    {
        cout << "Ksiazka adresowa jest pusta." << endl;
        system("pause");
        return;
    }
    else
    {
        for(int i = 0; i<adresaci.size(); i++)
        {
            cout << "ID: " << adresaci[i].pobierzIdAdresata() << endl;
            cout << "Imie: " << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko: " << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu: " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email: " << adresaci[i].pobierzEmail() << endl;
            cout << "Adres: " << adresaci[i].pobierzAdres() << endl << endl;
        }
        system("pause");
    }
}

int AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdAdresata() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikiZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(adresaci.begin()+ i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}

int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    string nowaDana = "";
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdAdresata() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                nowaDana = MetodyPomocnicze::wczytajLinie();
                nowaDana = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowaDana);
                adresaci[i].ustawImie(nowaDana);
                plikiZAdresatami.zaktualizujDaneEdytowanegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                nowaDana = MetodyPomocnicze::wczytajLinie();
                nowaDana = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nowaDana);
                adresaci[i].ustawNazwisko(nowaDana);
                plikiZAdresatami.zaktualizujDaneEdytowanegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                nowaDana = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawNumerTelefonu(nowaDana);
                plikiZAdresatami.zaktualizujDaneEdytowanegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                nowaDana = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawEmail(nowaDana);
                plikiZAdresatami.zaktualizujDaneEdytowanegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                nowaDana = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawAdres(nowaDana);
                plikiZAdresatami.zaktualizujDaneEdytowanegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja()
{
    char wybor;

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
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}


