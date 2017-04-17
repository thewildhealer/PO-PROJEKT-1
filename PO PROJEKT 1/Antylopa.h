#pragma once
#include "Zwierze.h"
class Antylopa :
	public Zwierze
{
public:
	Antylopa(Swiat& swiat);
	Antylopa(int x, int y, Swiat& swiat);

	void akcja() override;
	void kolizja() override;
	char rysowanie() override;
	void kopuluj(int x, int y) override;

	std::string getNazwa() override;

	~Antylopa();
};

