#pragma once
#include "Roslina.h"
class Guarana :
	public Roslina
{
public:
	Guarana(Swiat& swiat);
	Guarana(int x, int y, Swiat& swiat);
	~Guarana();

	char rysowanie() override;
	void zasiej(int x, int y) override;
	void kolizja(Organizm* napastnik) override;
	std::string getNazwa() override;
};

