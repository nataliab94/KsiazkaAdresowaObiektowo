#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>

#include "MetodyPomocnicze.h"
#include "UzytkownikMenadzer.h"


using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    Adresat(int id=0,int idUzytkownika=0,string imie="",string nazwisko="",string numerTelefonu="",string email="",string adres="")
    {
        this->id = id;
        this->idUzytkownika = idUzytkownika;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;


    }

    //setery
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawId(int noweId);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);
    //getery
    int wczytajIdUzytkownika();
    int wczytajId();
    string wczytajImie();
    string wczytajNazwisko();
    string wczytajNumerTelefonu();
    string wczytajEmail();
    string wczytajAdres();


};

#endif
