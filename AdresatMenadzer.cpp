#include "AdresatMenadzer.h"
#include "KsiazkaAdresowa.h"

void AdresatMenadzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
    {
        cout << "Dodano nowego adresata" << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
    else
    {
        cout << "Nie udalo sie dodac adresata do pliku." << endl;
        cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
        getch();
    }
}

Adresat AdresatMenadzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata()+1));
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);
    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);
    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::sprawdzPoprawnoscTelefonu();
    adresat.ustawNumerTelefonu(numerTelefonu);
    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();
    adresat.ustawEmail(email);
    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenadzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << "Nacisnij dowolny przycisk, aby kontynuowac." << endl;
    getch();
}

void AdresatMenadzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.wczytajId() << endl;
    cout << "Imie:               " << adresat.wczytajImie() << endl;
    cout << "Nazwisko:           " << adresat.wczytajNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.wczytajNumerTelefonu() << endl;
    cout << "Email:              " << adresat.wczytajEmail() << endl;
    cout << "Adres:              " << adresat.wczytajAdres() << endl;
}

void AdresatMenadzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenadzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> wczytajImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenadzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> wczytajNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}
int AdresatMenadzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenadzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> wczytajId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }

}

char AdresatMenadzer::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}


void AdresatMenadzer::edytujAdresata()
{
    system("cls");

    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";


    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;
    string imie, nazwisko, numerTelefonu, email, adres;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].wczytajId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                imie = MetodyPomocnicze::wczytajLinie();
                MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
                adresaci[i].ustawImie(imie);
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                nazwisko = MetodyPomocnicze::wczytajLinie();
                MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
                adresaci[i].ustawNazwisko(nazwisko);
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                numerTelefonu = MetodyPomocnicze::sprawdzPoprawnoscTelefonu();
                adresaci[i].ustawNumerTelefonu(numerTelefonu);
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                email = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawEmail(email);
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adres = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawAdres(adres);
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}
