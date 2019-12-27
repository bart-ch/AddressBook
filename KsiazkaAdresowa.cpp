#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami,string nazwaPlikuZAdresatami)
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
      adresatMenedzer(nazwaPlikuZAdresatami)
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
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatMenedzer.wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::wyloguj()
{
    adresatMenedzer.wyloguj();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}


