#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "PlikTekstowy.h"


using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI = "Adresaci-tymczasowy.txt";

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

public:
   PlikZAdresatami(string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void wczytajIdOstatniegoAdresata(int Id);
    void zapiszWszystkichUzytkownikowDoPliku();
    void usunWybranaLinieWPliku(int idUsuwanegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    void edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami, int idEdytowanegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();
    string pobierzNazweTymczasowegoPliku();
    void usunPlik(string NAZWA_PLIKU_Z_ADRESATAMI);
    void zmienNazwePliku(string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, string NAZWA_PLIKU_Z_ADRESATAMI);



};

#endif
