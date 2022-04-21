#include <iostream> 
using namespace std;
#include "Zdolnosc.h"

// klasa Zdolnosc

Zdolnosc::Zdolnosc(string nazwa, string opis) : nazwa(nazwa), opis(opis) {}

void Zdolnosc::przywroc_dostepnosc()
{
	dostepnosc = true;
}

void Zdolnosc::info(ostream& out) const
{
	out << nazwa << " (" << opis << ", dostepnosc " << dostepnosc << " ) ";
}

ostream& operator<<(ostream& out, const Zdolnosc& p)
{
	p.info(out);
	out << endl;
	return out;
}

// klasa Zdolnosc_Specjalna

// uzupelnij

Zdolnosc_Specjalna::Zdolnosc_Specjalna(string nazwa, string opis, int modyfikator) : Zdolnosc(nazwa, opis), modyfikator(modyfikator) {}

int Zdolnosc_Specjalna::wykorzystaj_zdolnosc()
{
	dostepnosc = false;
	return modyfikator;
}

void Zdolnosc_Specjalna::info(ostream& out) const
{
	Zdolnosc::info(out);
	out << "Modyfikator obrazen: "<< modyfikator;
}

// klasa Zdolnosc_Uzdrawiajaca

// uzupelnij

Zdolnosc_Uzdrawiajaca::Zdolnosc_Uzdrawiajaca(string nazwa, string opis, int uleczone_punkty_zycia) : Zdolnosc(nazwa, opis), uleczone_punkty_zycia(uleczone_punkty_zycia) {}

int Zdolnosc_Uzdrawiajaca::wykorzystaj_zdolnosc()
{
	dostepnosc = false;
	return uleczone_punkty_zycia;
}

void Zdolnosc_Uzdrawiajaca::info(ostream& out) const
{
	Zdolnosc::info(out);
	out << "Punkty zycia do uleczenia: " << uleczone_punkty_zycia;
}
