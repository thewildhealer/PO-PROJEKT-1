#pragma once
#include "Zwierze.h"

class Wilk :
	public Zwierze {
public:
	Wilk(Swiat& swiat);
	Wilk(int x, int y, Swiat& swiat);
	~Wilk();

	void akcja() override;
	void kolizja() override;
	char rysowanie() override;
	Wilk* kopuluj(int x, int y) override;
};
