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
		if (los == 0) x += mod;
		else if (los == 1) x -= mod;
		else if (los == 2) y += mod;
		else if (los == 3) y -= mod;

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
	else swiat.getRysunek(x, y)->kolizja(this);
}

void Zwierze::kolizja(Organizm* napastnik) {
	
	//if (typeid(*napastnik) == typeid(*napastnik)) {
	if(napastnik->rysowanie() == this->rysowanie()) {
		int count = 0;
		int los = rand() % 10;
		int i = 0, j = 0;
		if (!los) {
			while (count < 5 && swiat.getRysunek(x + i, y + j) != nullptr &&
				x + i < swiat.getSzerokosc() - 1 && x + i > 0 &&
				y + j < swiat.getWysokosc() - 1 && y + j > 0) {

				i = (rand() % 3) - 1;
				j = (rand() % 3) - 1;
				count++;
			};
		}

		if (swiat.getRysunek(x + i, y + j) == nullptr) {
			swiat.narodziny(this, x + i, y + j);
			this->kopuluj(x + i, y + j);
		}
		napastnik->setX(napastnik->getPrevX());
		napastnik->setY(napastnik->getPrevY());
	}
	else {
		if (napastnik->getSila() >= this->sila) {
			swiat.setRysunek(napastnik->getPrevX(), napastnik->getPrevY(), nullptr);
			swiat.umrzyj(napastnik, this);
		}
		if (napastnik->getSila() < this->sila) {
			swiat.setRysunek(napastnik->getPrevX(), napastnik->getPrevY(), nullptr);
			swiat.umrzyj(this, napastnik);
		}

	}
}
