#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"

class KsiazkaAdresowa
{

    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer *adresatMenadzer;
    PlikZAdresatami plikZAdresatami;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), plikZAdresatami(nazwaPlikuZAdresatami)
    {

        adresatMenadzer = NULL;
    };

    ~KsiazkaAdresowa()
    {

        delete adresatMenadzer;
        adresatMenadzer = NULL;
    };


    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void zmianaHaslaZalogowanegoUzytkownika();
    void usunAdresata();
    void edytujAdresata();

};

#endif
