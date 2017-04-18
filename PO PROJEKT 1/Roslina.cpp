#include "Roslina.h"

Roslina::Roslina(Swiat& swiat) : Organizm(swiat) {
	prevX = x;
	prevY = y;
	nowoZasiana = true;
	inicjatywa = 0;
	sila = 0;
}

Roslina::Roslina(int x, int y, Swiat& swiat) : Organizm(x, y, swiat) {
	prevX = x;
	prevY = y;
	inicjatywa = 0;
	sila = 0;
}

void Roslina::akcja() {

	if (!nowoZasiana) {
		int count = 0;
		int los = rand() % 5;
		int i = 0, j = 0;
		if (!los) {
			while (count < 5 && swiat.getRysunek(x + i, y + j) != nullptr &&
				x + i < swiat.getSzerokosc() - 1 && x + i > 0 &&
				y + j < swiat.getWysokosc() - 1 && y + j > 0) {

				i = (rand() % 3) - 1;
				j = (rand() % 3) - 1;
				count++;
			};

			if (swiat.getRysunek(x + i, y + j) == nullptr) {
				swiat.nowaRoslina(this, x + i, y + j);
				this->zasiej(x + i, y + j);
			}
		}
	}
	else nowoZasiana = false;
}

void Roslina::kolizja(Organizm* napastnik) {
	if (napastnik->getSila() >= this->sila) {
		swiat.setRysunek(napastnik->getPrevX(), napastnik->getPrevY(), nullptr);
		swiat.umrzyj(napastnik, this);
	}
	if (napastnik->getSila() < this->sila) {
		swiat.setRysunek(napastnik->getPrevX(), napastnik->getPrevY(), nullptr);
		swiat.umrzyj(napastnik, this);
		swiat.umrzyj(this, napastnik);
		swiat.setRysunek(napastnik->getX(), napastnik->getY(), nullptr);
	}
}

char Roslina::getType() {
	return 'r';
}

Roslina::~Roslina() {
}
