#pragma once
#include "Swiat.h"
class Swiat;

class Organizm {
public:
	Organizm(Swiat& swiat);
	Organizm(int x, int y, Swiat& swiat);
	virtual ~Organizm();

	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual char rysowanie() = 0;

	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);
	int getSila() const;
	int getInicjatywa() const;

protected:
	int sila;
	int inicjatywa;
	int x, y;
	int prevX, prevY;
	Swiat& swiat;
};