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

    char wybor;

    while (true)
    {
        if (UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika() == 0)
        {
            wybor = wybierzOpcjeZMenuGlownego();

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

            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazka.dodajAdresata()
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
            //    idUsunietegoAdresata = usunAdresata(adresaci);
           //     idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
           //     edytujAdresata(adresaci);
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
