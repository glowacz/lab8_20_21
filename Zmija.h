#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Zmija
{	
protected:
	int punktyZycia = 8;
	int sila_ataku = 3;
	int poziom_ochrony = 3;

public:
	virtual ~Zmija() {};
	bool czyZyje() const { return punktyZycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony; }

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const = 0;
	void przyjmij_atak(int obrazenia);

	virtual void info(ostream&) const = 0;
	friend ostream& operator<<(ostream&, const Zmija&);
};

class Zmija_Zwyczajna : public Zmija
{
protected:
	virtual int ugryzienie() const { return sila_ataku; }
public:
	virtual ~Zmija_Zwyczajna() {};
	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const;
	virtual void info(ostream&) const;
	// uzupelnij
};

class Zmija_Jadowita : public Zmija_Zwyczajna
{
	static int ile_zmij;
	const int numer_zmiji;
protected:
	//int ugryzienie() const override;
	int zatrucie() const;
public:
	// uzupelnij
	Zmija_Jadowita() : numer_zmiji{ ++ile_zmij } {
		punktyZycia *= 2;
		//sila_ataku *= 2;
		sila_ataku += 2;
		poziom_ochrony *= 2;
	}
	virtual ~Zmija_Jadowita() {};
	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const;
	virtual void info(ostream&) const;
};