#pragma once
#include "Zwierze.h"

class Wilk :
	public Zwierze {
public:
	Wilk(Swiat& swiat);
	Wilk(int x, int y, Swiat& swiat);
	~Wilk();

	char rysowanie() override;
	void kopuluj(int x, int y) override;
	std::string getNazwa() override;
};
