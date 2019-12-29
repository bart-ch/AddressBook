#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "PlikiZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"

class AdresatMenedzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikiZAdresatami plikiZAdresatami;
    Adresat podajDaneNowegoAdresata();


    int podajIdWybranegoAdresata();

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika);
    void dodajAdresata();
    void wypiszWszystkichAdresatow();

    int usunAdresata();
};

#endif // ADRESATMENEDZER_H
