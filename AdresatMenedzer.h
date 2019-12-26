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
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami);
    void dodajAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wypiszWszystkichAdresatow();
    void wyloguj();
};

#endif // ADRESATMENEDZER_H
