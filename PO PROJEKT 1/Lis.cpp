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
	Zwierze::akcja();
	// tu moze cos bedzie jeszcze, a jak nei to wyrzuce te metode
}

void Lis::kolizja() {
	// ten if wywala wyjatki (juz rzadziej)
	// ale zaczal wywalac stack overflow :<
	if (swiat.getRysunek(x, y) != nullptr && swiat.getRysunek(x, y)->getSila() > sila) {
		x = prevX;
		y = prevY;
		this->akcja();
	}
	else if (swiat.getRysunek(x, y) != nullptr) Zwierze::kolizja();
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
