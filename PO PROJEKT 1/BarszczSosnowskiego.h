#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
	public Roslina
{
public:
	BarszczSosnowskiego(Swiat& swiat);
	BarszczSosnowskiego(int x, int y, Swiat& swiat);
	~BarszczSosnowskiego();

	char rysowanie() override;
	void zasiej(int x, int y) override;
	void akcja() override;
	std::string getNazwa() override;

};

