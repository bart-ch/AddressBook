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
    cin >> imie;
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    cout << "Podaj numer telefonu: ";
    cin >> numerTelefonu;
    adresat.ustawNumerTelefonu(numerTelefonu);

    cout << "Podaj email: ";
    cin >> email;
    adresat.ustawEmail(email);

    cout << "Podaj adres: ";
    cin >> adres;
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    idOstatniegoAdresata = plikiZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci);
}

void AdresatMenedzer::wypiszWszystkichAdresatow()
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
}


