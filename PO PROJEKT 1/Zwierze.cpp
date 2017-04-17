#include "Zwierze.h"
// testowo
#include "Owca.h"


Zwierze::Zwierze(Swiat& swiat) : Organizm(swiat) {
	mod = 1;
}

Zwierze::Zwierze(int x, int y, Swiat& swiat) : Organizm(x, y, swiat) {
	mod = 1;
}


Zwierze::~Zwierze() {
}

void Zwierze::akcja() {
	prevX = x;
	prevY = y;
	int los;
	for (int i = 0; i < 4 && prevX == x && prevY == y; i++) {
		los = rand() % 4;
		if (los == 0) x+=mod;
		else if (los == 1) x-=mod;
		else if (los == 2) y+=mod;
		else if (los == 3) y-=mod;

		while (x < 0) x++;
		while (y < 0) y++;
		while (y > swiat.getWysokosc() - 1) y--;
		while (x > swiat.getSzerokosc() - 1) x--;
	}
	if (x == prevX && y == prevY) return;
	if (swiat.getRysunek(x, y) == nullptr) {
		swiat.setRysunek(x, y, this);
		swiat.setRysunek(prevX, prevY, nullptr);
	}
	else kolizja();
}

void Zwierze::kolizja() {
	// TODO: sprawdzic dlaczego rozmnazaja sie do max rozmiar-1 
	// ten if chyba nie do konca dziala jak nalezy
	int atakowanySila = swiat.getRysunek(x, y)->getSila();
	if (typeid(*swiat.getRysunek(x, y)) == typeid(*this)) {
		int i = -1, j = -1;
		bool success = false;
		for (; i < 1; ++i) {
			for (; j < 1; ++j) {
				if (x + i < swiat.getSzerokosc() - 1 && x + i >= 0 && // nie wykracza poza szerokoœæ
					y + j < swiat.getWysokosc() - 1 && y + j > 0 && // nie wykracza poza wysokoœæ
					swiat.getRysunek(x + i, y + j) == nullptr) { // nie rozmnaza sie gdy cos juz tam jest
					success = true;
					break;
				}
			}
		}
		if (success && swiat.getRysunek(x + i, y + j) == nullptr) {
			swiat.narodziny(this, x + i, y + j);
			this->kopuluj(x + i, y + j);
		}
		x = prevX;
		y = prevY;
	}
	else {
		if (atakowanySila > this->sila) swiat.umrzyj(swiat.getRysunek(x, y), this);
		if (atakowanySila <= this->sila) {
			swiat.umrzyj(this, swiat.getRysunek(x, y));
			swiat.setRysunek(x, y, this);
			swiat.setRysunek(prevX, prevY, nullptr);
		}
	}
}
