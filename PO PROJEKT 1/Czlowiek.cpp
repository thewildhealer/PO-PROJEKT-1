#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat& swiat) : Zwierze(swiat) {
	sila = 5;
	inicjatywa = 4;
}

Czlowiek::Czlowiek(int x, int y, Swiat& swiat) : Zwierze(x, y, swiat) {
	sila = 5;
	inicjatywa = 4;
}

void Czlowiek::akcja() {
	swiat.aktualizujRysunek();
	prevX = x;
	prevY = y;
	
	int zn = _getch();
	if (zn == 'w') y--;
	else if (zn == 's') y++;
	else if (zn == 'a') x--;
	else if (zn == 'd') x++;
	
	/*
	int zn;
	zn = _getch();
	zn = _getch();
	// dwa razy bo raz to strzalki sie wywalaly
	if (zn == 0x48) y--;
	else if (zn == 0x50) y++;
	else if (zn == 0x4b) x--;
	else if (zn == 0x4d) x++;
	*/

	while (x < 0) x++;
	while (y < 0) y++;
	while (y > swiat.getWysokosc() - 1) y--;
	while (x > swiat.getSzerokosc() - 1) x--;

	if (x == prevX && y == prevY) return;
	if (swiat.getRysunek(x, y) == nullptr) {
		swiat.setRysunek(x, y, this);
		swiat.setRysunek(prevX, prevY, nullptr);
	}
	else if (swiat.getRysunek(x, y) != this) swiat.getRysunek(x, y)->kolizja(this);
}

void Czlowiek::kolizja(Organizm* napastnik) {
	if (napastnik->getSila() >= this->sila) {
		swiat.setRysunek(napastnik->getPrevX(), napastnik->getPrevY(), nullptr);
		swiat.umrzyj(napastnik, this);
	}
	if (napastnik->getSila() < this->sila) {
		swiat.setRysunek(napastnik->getPrevX(), napastnik->getPrevY(), nullptr);
		swiat.umrzyj(this, napastnik);
	}
}

char Czlowiek::rysowanie() {
	return 'c';
}

void Czlowiek::kopuluj(int x, int y) {
}

std::string Czlowiek::getNazwa() {
	return "Czlowiek";
}

Czlowiek::~Czlowiek()
{
}
