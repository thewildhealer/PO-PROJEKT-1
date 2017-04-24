#include "Lis.h"

Lis::Lis(Swiat& swiat) : Zwierze::Zwierze(swiat) {
	inicjatywa = 7;
	sila = 3;
}

Lis::Lis(int x, int y, Swiat& swiat) : Zwierze::Zwierze(x, y, swiat) {
	inicjatywa = 7;
	sila = 3;
}

void Lis::akcja() {
	prevX = x;
	prevY = y;
	int los;
	int count = 0;
	while (swiat.getRysunek(x, y) != this && swiat.getRysunek(x, y) != nullptr && swiat.getRysunek(x, y)->getSila() > sila && count < 10) {
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
		count++;
	}
	if (count >= 10) return;
	if (x == prevX && y == prevY) return;
	if (swiat.getRysunek(x, y) == nullptr) {
		swiat.setRysunek(x, y, this);
		swiat.setRysunek(prevX, prevY, nullptr);
	}
	else swiat.getRysunek(x, y)->kolizja(this);
}

char Lis::rysowanie() {
	return 'l';
}

void Lis::kopuluj(int x, int y) {
	swiat.dodajOrganizm(new Lis(x, y, swiat));
}

std::string Lis::getNazwa() {
	return "Lis";
}

Lis::~Lis() {
}
