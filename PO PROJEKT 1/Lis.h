#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
public:
	Lis(Swiat& swiat);
	Lis(int x, int y, Swiat& swiat);
	
	void akcja() override;
	char rysowanie() override;
	void kopuluj(int x, int y) override;

	std::string getNazwa() override;

	~Lis();
};

