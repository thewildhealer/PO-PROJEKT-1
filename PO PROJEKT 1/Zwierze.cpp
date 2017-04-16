#include "Zwierze.h"
// testowo
#include "Owca.h"


Zwierze::Zwierze(Swiat& swiat) : Organizm(swiat) {
}

Zwierze::Zwierze(int x, int y, Swiat& swiat) : Organizm(x, y, swiat) {
}


Zwierze::~Zwierze() {
}

void Zwierze::akcja() {
	prevX = x;
	prevY = y;
	int los;
	while (prevX == x && prevY == y) {
		los = rand() % 4;
		if (los == 0) x++;
		else if (los == 1) x--;
		else if (los == 2) y++;
		else if (los == 3) y--;

		while (x < 0) x++;
		while (y < 0) y++;
		while (y > swiat.getWysokosc() - 1) y--;
		while (x > swiat.getSzerokosc() - 1) x--;
	}
	if (swiat.getRysunek(x, y) == nullptr) {
		swiat.setRysunek(x, y, this);
		swiat.setRysunek(prevX, prevY, nullptr);
	}
	else kolizja();
}

void Zwierze::kolizja() {
	// ten if chyba nie do konca dziala jak nalezy
	int atakowanySila = swiat.getRysunek(x, y)->getSila();
	if (typeid(*swiat.getRysunek(x, y)) == typeid(*this)) {
		int i = -1, j = -1;
		bool success = false;
		for (; i < 1; i++)
			for (; j < 1; j++)
				if (x + i < swiat.getSzerokosc() && x + i >= 0 && y + j < swiat.getWysokosc() && y + j > 0 && swiat.getRysunek(x + i, y + j) == nullptr) {
					success = true;
					break;
				};
		if (success) kopuluj(x + i, y + j);
		x = prevX;
		y = prevY;
	}
	else {
		if (atakowanySila > this->sila) swiat.umrzyj(this);
		if (atakowanySila <= this->sila) {
			swiat.umrzyj(swiat.getRysunek(x, y));
			swiat.setRysunek(x, y, this);
			swiat.setRysunek(prevX, prevY, nullptr);
		}
	}
}
