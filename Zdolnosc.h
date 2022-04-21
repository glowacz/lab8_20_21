#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Rycerz;

class Zdolnosc
{
	friend class Rycerz;
protected:
	string nazwa;
	string opis;
	bool dostepnosc = false;
public:
	Zdolnosc(string nazwa, string opis);
	void przywroc_dostepnosc();
	virtual ~Zdolnosc() {};
	virtual int wykorzystaj_zdolnosc() = 0;
	virtual void info(ostream&) const;
	friend ostream& operator<<(ostream&, const Zdolnosc&);
};

class Zdolnosc_Specjalna : public Zdolnosc
{
protected:
	int modyfikator;
public:
	// uzupelnij
	Zdolnosc_Specjalna(string nazwa, string opis, int modyfikator);
	virtual ~Zdolnosc_Specjalna() {};
	virtual int wykorzystaj_zdolnosc();
	virtual void info(ostream&) const;
};

class Zdolnosc_Uzdrawiajaca : public Zdolnosc
{
protected:
	int uleczone_punkty_zycia;
public:
	// uzupelnij
	Zdolnosc_Uzdrawiajaca(string nazwa, string opis, int modyfikator);
	virtual ~Zdolnosc_Uzdrawiajaca() {};
	virtual int wykorzystaj_zdolnosc();
	virtual void info(ostream&) const;
};

