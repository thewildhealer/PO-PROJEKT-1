#pragma once
#include "Zwierze.h"
#include <conio.h>

class Czlowiek :
	public Zwierze
{
public:
	Czlowiek(Swiat& swiat);
	Czlowiek(int x, int y, Swiat& swiat);

	void akcja() override;
	void kolizja(Organizm* napastnik) override;
	char rysowanie() override;
	void kopuluj(int x, int y) override;
	
	std::string getNazwa() override;

	~Czlowiek();
private: 
	void calopalenie();
	int licznik;
	int cooldown;
	int czasTrwania;
	bool umiejetnoscWlaczona;
};

