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
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);


    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();

public:
    PlikiZAdresatami(string,string);
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    int usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    void zaktualizujDaneEdytowanegoAdresata(Adresat adresat);
};



#endif
