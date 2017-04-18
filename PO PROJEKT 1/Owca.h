#pragma once
#include "Zwierze.h"

class Owca :
	public Zwierze {
public:
	Owca(Swiat& swiat);
	Owca(int x, int y, Swiat& swiat);
	~Owca();

	char rysowanie() override;
	void kopuluj(int x, int y) override;
	std::string getNazwa() override;
};
