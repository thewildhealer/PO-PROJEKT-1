#pragma once
#include "Organizm.h"
class Roslina :
	public Organizm
{
public:
	Roslina(Swiat& swiat);
	Roslina(int x, int y, Swiat& swiat);

	void akcja() override;
	void kolizja() override;
	char rysowanie() override = 0;
	virtual void zasiej(int x, int y) = 0;

	virtual std::string getNazwa() = 0;
	~Roslina();
};

