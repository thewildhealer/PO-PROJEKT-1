#pragma once
#include "Zwierze.h"

class Owca :
	public Zwierze {
public:
	Owca(Swiat& swiat);
	Owca(int x, int y, Swiat& swiat);
	~Owca();

	void akcja() override;
	void kolizja() override;
	char rysowanie() override;
	void kopuluj(int x, int y) override;
	std::string getNazwa() override;
};
