#pragma once
#include "Roslina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(Swiat& swiat);
	Trawa(int x, int y, Swiat& swiat);
	~Trawa();

	char rysowanie() override;
	void zasiej(int x, int y) override;
	std::string getNazwa() override;
};

