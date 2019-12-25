#include "Adresat.h"

void Adresat::ustawIdAdresata(int noweId)
{
    id = noweId;
}

void Adresat::ustawIdUzytkownika(int noweId)
{
    idUzytkownika = noweId;
}

void Adresat::ustawImie(string noweImie)
{
    imie = noweImie;
}
void Adresat::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}
void Adresat::ustawNumerTelefonu(string nowyNrTelefonu)
{
    numerTelefonu = nowyNrTelefonu;
}
void Adresat::ustawEmail(string nowyEmail)
{
    email = nowyEmail;
}
void Adresat::ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}

int Adresat::pobierzIdAdresata()
{
    return id;
}
int Adresat::pobierzidUzytkownika()
{
    return idUzytkownika;
}
string Adresat::pobierzImie()
{
    return imie;
}
string Adresat::pobierzNazwisko()
{
    return nazwisko;
}
string Adresat::pobierzNumerTelefonu()
{
    return numerTelefonu;
}
string Adresat::pobierzEmail()
{
    return email;
}
string Adresat::pobierzAdres()
{
    return adres;
}
