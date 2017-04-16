#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Organizm.h"

class Organizm;

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

	void umrzyj(Organizm* organizm);
private:
	int szerokosc, wysokosc;
	//	char *rysunek;
	Organizm** rysunek;
	std::vector<Organizm*> organizmy;
};
