#pragma once
#include "Roslina.h"
class WilczeJagody :
	public Roslina
{
public:
	WilczeJagody(Swiat& swiat);
	WilczeJagody(int x, int y, Swiat& swiat);
	~WilczeJagody();

	char rysowanie() override;
	void zasiej(int x, int y) override;
	std::string getNazwa() override;
};

