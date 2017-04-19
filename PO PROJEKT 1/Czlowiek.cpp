#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat& swiat) : Zwierze(swiat) {
	sila = 5;
	inicjatywa = 4;
	licznik = 5;
	cooldown = 5;
	umiejetnoscWlaczona = false;
	czasTrwania = 0;
}

Czlowiek::Czlowiek(int x, int y, Swiat& swiat) : Zwierze(x, y, swiat) {
	sila = 5;
	inicjatywa = 4;
	licznik = 5;
	cooldown = 5;
	umiejetnoscWlaczona = false;
	czasTrwania = 0;
}

void Czlowiek::akcja() {
	swiat.aktualizujRysunek();
	prevX = x;
	prevY = y;
	if (czasTrwania >= 5) {
		czasTrwania = 0;
		umiejetnoscWlaczona = false;
	}
	if (!umiejetnoscWlaczona && cooldown > licznik) licznik++;

	int zn = _getch();
	if (zn == 'w') y--;
	else if (zn == 's') y++;
	else if (zn == 'a') x--;
	else if (zn == 'd') x++;
	else if (zn == 'q' && licznik == 5) {
		licznik = 0;
		umiejetnoscWlaczona = true;
	};

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
	if (umiejetnoscWlaczona) {
		calopalenie(); 
		czasTrwania++;
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

void Czlowiek::calopalenie() {
	swiat.umiejetnoscAktywowana(this, czasTrwania);
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++)
			if (x + i >= 0 && y + j >= 0 && x + i <= swiat.getSzerokosc() - 1 && y + j <= swiat.getWysokosc() - 1 &&
				swiat.getRysunek(x + i, y + j) != nullptr && swiat.getRysunek(x + i, y + j)->rysowanie() != 'c') {
				swiat.umrzyj(this, swiat.getRysunek(x + i, y + j));
			}
	}
}
