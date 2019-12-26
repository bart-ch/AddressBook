#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazka;
    ksiazka.logowanieUzytkownika();
    ksiazka.dodajAdresata();
    ksiazka.wypiszWszystkichAdresatow();
    ksiazka.zmianaHaslaZalogowanegoUzytkownika();
    ksiazka.wyloguj();
    ksiazka.logowanieUzytkownika();
    ksiazka.wypiszWszystkichAdresatow();


    return 0;
}
