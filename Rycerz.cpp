#include <iostream> 
using namespace std;
#include "Rycerz.h"
#include "Przedmiot.h"
#include "Bron.h"
#include "Zbroja.h"
#include "Artefakt.h"
#include "Zdolnosc.h"

// klasa Rycerz


Rycerz::Rycerz(string imie, int punktyZycia, int zrecznosc, int sila, int poziom) : Postac(imie, punktyZycia, zrecznosc, sila, poziom)
{
	zdolnosci = new (nothrow) Zdolnosc*[liczba_zdolnosci];
	zdolnosci[0] = new Zdolnosc_Specjalna("Perfekcyjne ostrzenie broni", "dodatkwe 2 obrazenia", 2);
	zdolnosci[1] = new Zdolnosc_Uzdrawiajaca("Opatrywanie ran", "leczy 4 obrazenia", 4);

	for (int i = 0; i < wielkosc_ekwipunku; i++)
		ekwipunek[i] = nullptr;
	ekwipunek[0] = new Bron("Miecz", "doskonaly miecz", 5);
	ekwipunek[1] = new Przedmiot("Butelka", "butelka z woda pitna");
	ekwipunek[2] = new Bron("Sztylet", "sztylet krotki", 1);
	ekwipunek[3] = new Zbroja("Kolczuga", "klasyczna kolczuga", 3);
}

Rycerz::~Rycerz()
{
	for (int i = 0; i < liczba_zdolnosci; i++)
		delete zdolnosci[i];
	delete[] zdolnosci;
	
	for (int i = 0; i < wielkosc_ekwipunku; i++)
		delete ekwipunek[i];
}

int Rycerz::czy_dostepna_specjalna() const
{
	for (int i = 0; i < liczba_zdolnosci; i++) {
		if (dynamic_cast<Zdolnosc_Specjalna*>(zdolnosci[i]))
			return 1;
	}
	return 0;
}

int Rycerz::czy_dostepna_uzdrawiajaca() const
{
	for (int i = 0; i < liczba_zdolnosci; i++) {
		if (dynamic_cast<Zdolnosc_Uzdrawiajaca*>(zdolnosci[i]))
			return 1;
	}
	return 0;
}

void Rycerz::przygotowanie()
{
	for (int i = 0; i < liczba_zdolnosci; i++)
		zdolnosci[i]->przywroc_dostepnosc();

	for (int i = 0; i < wielkosc_ekwipunku; i++)
		if (dynamic_cast<Bron*>(ekwipunek[i])) {
			bron_w_reku = (Bron*)ekwipunek[i];
			//delete ekwipunek[i];
			ekwipunek[i] = nullptr;
			break;
		}

	for (int i = 0; i < wielkosc_ekwipunku; i++)
		if ( dynamic_cast<Zbroja*>(ekwipunek[i]) ) 
		{
			zbroja_na_ciele = (Zbroja*)ekwipunek[i];
			poziom_ochrony += zbroja_na_ciele->wykorzystaj_ochrone();
			ekwipunek[i] = nullptr;
			break;
		}

	for (int i = 0; i < wielkosc_ekwipunku; i++)
		if (dynamic_cast<Artefakt*>(ekwipunek[i]))
		{
			artefakt = (Artefakt*)ekwipunek[i];
			//if( artefakt->jaki_typ_artefaktu() == typ_artefaktu::MODYFIKUJACY_OCHRONE)
			if (artefakt->jaki_typ_artefaktu() == Artefakt::typ_artefaktu::MODYFIKUJACY_OCHRONE)
				poziom_ochrony += artefakt->wykorzystaj_artefakt();
			else
				sila_ataku += artefakt->wykorzystaj_artefakt();
			ekwipunek[i] = nullptr;
			break;
		}

	for (int i = 0; i < liczba_zdolnosci; i++)
		if( dynamic_cast<Zdolnosc_Specjalna *>(zdolnosci[i]) )
			modyfikator_obrazen += zdolnosci[i]->wykorzystaj_zdolnosc();
}

void Rycerz::info(ostream& out) const
{
	Postac::info(out);
	cout << "Modyfikator obrazen: " << modyfikator_obrazen << endl;
	cout << "Zdolnosci: " << endl;
	for (int i = 0; i < liczba_zdolnosci; i++)
		out << *zdolnosci[i];
	cout << "Ekwipunek: " << endl;
	for (int i = 0; i < wielkosc_ekwipunku; i++)
	{
		if (ekwipunek[i])
			out << i + 1 << ". " << *ekwipunek[i];
		else
			out << i + 1 << ". " << "pusto" << endl;
	}
}


