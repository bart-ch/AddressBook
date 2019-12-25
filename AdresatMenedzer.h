#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "PlikiZAdresatami.h"
#include "MetodyPomocnicze.h"

class AdresatMenedzer
{

    vector <Adresat> adresaci;
    PlikiZAdresatami plikiZAdresatami;
    int idOstatniegoAdresata;

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami);
    void dodajAdresata(int idZalogowanegoAdresata);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
};

#endif // ADRESATMENEDZER_H
