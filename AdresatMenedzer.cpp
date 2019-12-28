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


