#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazka;

    char wybor;

    while (true)
    {
        if (ksiazka.czyUzytkownikJestZalogowany() == false)
        {
            wybor = ksiazka.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazka.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazka.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = ksiazka.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazka.dodajAdresata();
                break;
            case '2':
                //    wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                //        wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                ksiazka.wypiszWszystkichAdresatow();
                break;
            case '5':
                ksiazka.usunaAdresata();
                break;
            case '6':
                ksiazka.edytujAdresata();
                break;
            case '7':
                ksiazka.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazka.wyloguj();
                break;
            }
        }
    }

    return 0;
}
