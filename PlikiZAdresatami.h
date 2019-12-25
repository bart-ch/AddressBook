#ifndef PLIKIZADRESATAMI_H
#define PLIKIZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include <fstream>

using namespace std;

class PlikiZAdresatami
{
    const string nazwaPlikuZAdresatami;
    vector <Adresat> adresaci;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);

public:
    PlikiZAdresatami(string);
    void dopiszAdresataDoPliku(Adresat adresat);

};



#endif
