#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazka;
    ksiazka.wypiszWszystkichUzytkownikow();
    ksiazka.logowanieUzytkownika();
    // ksiazka.rejestracjaUzytkownika();
    // ksiazka.rejestracjaUzytkownika();
    ksiazka.dodajAdresata();
    ksiazka.dodajAdresata();
    ksiazka.wypiszWszystkichAdresatow();

//       ksiazka.dodajAdresata();
//ksiazka.zmianaHaslaZalogowanegoUzytkownika();

    return 0;
}
