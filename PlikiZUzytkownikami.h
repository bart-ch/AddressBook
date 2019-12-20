#ifndef PLIKIZUZYTKOWNIKAMI_H
#define PLIKIZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikiZUzytkownikami
{
    string nazwaPlikuZUzytkownikami;
        fstream plikTekstowy;

    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
    PlikiZUzytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
};

#endif
