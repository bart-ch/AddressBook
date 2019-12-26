#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "PlikiZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"

class AdresatMenedzer
{

    vector <Adresat> adresaci;
    PlikiZAdresatami plikiZAdresatami;
    int idOstatniegoAdresata;

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami);
    void dodajAdresata();
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wypiszWszystkichAdresatow();
};

#endif // ADRESATMENEDZER_H
