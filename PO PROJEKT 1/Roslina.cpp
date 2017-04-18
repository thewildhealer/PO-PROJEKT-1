#include "Roslina.h"

Roslina::Roslina(Swiat& swiat) : Organizm(swiat) {
	prevX = x;
	prevY = y;
	nowoZasiana = true;
	inicjatywa = 0;
}

Roslina::Roslina(int x, int y, Swiat& swiat) : Organizm(x, y, swiat) {
	inicjatywa = 0;
}

void Roslina::akcja() {
	//	prevX = x;
	//	prevY = y;
	/*
	 */


	if (!nowoZasiana) {
		int count = 0;
		int los = rand() % 50;
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

void Roslina::kolizja() {
}

Roslina::~Roslina() {
}
