#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Organizm.h"
#include "Komentator.h"

class Organizm;
class Komentator;

class Swiat {
public:
	Swiat();
	Swiat(int x, int y);
	~Swiat();

	void inicjalizujRysunek();

	void wykonajTure();
	void rysujSwiat();
	void setRysunek(int x, int y, Organizm* org);
	Organizm* getRysunek(int x, int y);

	int getWysokosc() const;
	int getSzerokosc() const;

	void dodajOrganizm(Organizm* organizm);

	void umrzyj(Organizm* napastnik, Organizm* ofiara);
	void narodziny(Organizm* org, int x, int y);
	void nowaRoslina(Organizm *org, int x, int y);

private:
	int szerokosc, wysokosc;
	//	char *rysunek;
	Organizm** rysunek;
	std::vector<Organizm*> organizmy;
	Komentator* komentator;
};
