#pragma once
#include "Roslina.h"
class Mlecz :
	public Roslina
{
public:
	Mlecz(Swiat& swiat);
	Mlecz(int x, int y, Swiat& swiat);
	~Mlecz();

	void akcja() override;
	char rysowanie() override;
	void zasiej(int x, int y) override;
	std::string getNazwa() override;
};

