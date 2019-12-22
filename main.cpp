#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazka("Uzytk.txt");
    ksiazka.wypiszWszystkichUzytkownikow();
    ksiazka.rejestracjaUzytkownika();
    ksiazka.rejestracjaUzytkownika();
    ksiazka.wypiszWszystkichUzytkownikow();

    return 0;
}
