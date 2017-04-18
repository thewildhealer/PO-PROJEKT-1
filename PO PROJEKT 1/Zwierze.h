#pragma once
#include "Organizm.h"
#include <iostream>
#include <typeinfo>

class Zwierze :
	public Organizm {
public:
	Zwierze(Swiat& swiat);
	Zwierze(int x, int y, Swiat& swiat);
	~Zwierze();

	void akcja() override;
	void kolizja(Organizm* napastnik) override;
	char rysowanie() override = 0;
	virtual void kopuluj(int x, int y) = 0;

	virtual std::string getNazwa() = 0;
protected: 
	int mod;
};
