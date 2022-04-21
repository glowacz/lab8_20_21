#include <iostream> 
using namespace std;
#include "Zmija.h"

int Zmija_Jadowita::ile_zmij = 0;

// Klasa Zmija

void Zmija::przyjmij_atak(int obrazenia)
{
	punktyZycia -= obrazenia;
}

ostream& operator<<(ostream& out, const Zmija& p)
{
	p.info(out);
	return out;
}

// Klasa Zmija_Zwyczjna

// uzupelnij

int Zmija_Zwyczajna::wykonaj_atak(int poziom_ochrony_przeciwnika) const
{
	if (sila_ataku > poziom_ochrony_przeciwnika)
	{
		return this->ugryzienie();
	}
	return 0;
}

void Zmija_Zwyczajna::info(ostream& out) const
{
	out << "Zmija Zwyczajna poziom ochrony: " << poziom_ochrony << " punkty zycia : " << punktyZycia << endl;
}

// Klasa Zmija_Jadowita

// uzupelnij

int Zmija_Jadowita::zatrucie() const
{
	return 2*sila_ataku;
}

int Zmija_Jadowita::wykonaj_atak(int poziom_ochrony_przeciwnika) const
{
	if( numer_zmiji % 2 == 0 ) return this->zatrucie();
	
	if (sila_ataku > poziom_ochrony_przeciwnika)
	{
		return this->ugryzienie();
	}
	return 0;
}

void Zmija_Jadowita::info(ostream& out) const
{
	out << "Zmija Jadowita poziom ochrony: " << poziom_ochrony << " punkty zycia : " << punktyZycia << endl;
}
