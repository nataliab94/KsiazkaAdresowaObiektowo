#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int id;
    string login;
    string haslo;

public:
    void ustawId (int noweId);
    void ustawLogin (string login);
    void ustawHaslo(string noweHaslo);

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();

};

#endif
