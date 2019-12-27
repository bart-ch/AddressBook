#include "AdresatMenedzer.h"

AdresatMenedzer::AdresatMenedzer(string nazwaPlikuZAdresatami)
    : plikiZAdresatami(nazwaPlikuZAdresatami)
{
}

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;
    int idZalogowanegoUzytkownika = UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika();

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikiZAdresatami.dopiszAdresataDoPliku(adresat);
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string imie,nazwisko,numerTelefonu,email,adres;

    adresat.ustawIdAdresata(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    idOstatniegoAdresata = plikiZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci);
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

void AdresatMenedzer::wyloguj()
{
    adresaci.clear();
    UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(0);
    cout << "Zostales wylogowany." << endl;
    system("pause");
}


