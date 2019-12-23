#include "KsiazkaAdresowa.h"

 KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami)
 : uzytkownikMenedzer(nazwaPlikuZUzytkownikami)
{
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

 void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
 {
     uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
 }

  void KsiazkaAdresowa::logowanieUzytkownika()
 {
     uzytkownikMenedzer.logowanieUzytkownika();
 }



