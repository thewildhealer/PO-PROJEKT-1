#pragma once
#include "Zwierze.h"
class Zolw :
	public Zwierze
{
public:
	Zolw(Swiat& swiat);
	Zolw(int x, int y, Swiat& swiat);

	void akcja() override;
	void kolizja(Organizm* napastnik) override;
	char rysowanie() override;
	void kopuluj(int x, int y) override;

	std::string getNazwa() override;
	
	~Zolw();
};

