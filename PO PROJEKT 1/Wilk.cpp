#include "Wilk.h"


Wilk::Wilk(Swiat& swiat) : Zwierze(swiat) {
	inicjatywa = 5;
	sila = 9;
}

Wilk::Wilk(int x, int y, Swiat& swiat) : Zwierze(x, y, swiat) {
	inicjatywa = 5;
	sila = 9;
}


Wilk::~Wilk() {
}

void Wilk::akcja() {
	Zwierze::akcja();
}

void Wilk::kolizja() {
	Zwierze::kolizja();
}

char Wilk::rysowanie() {
	return 'w';
}

Wilk* Wilk::kopuluj(int x, int y) {
	return new Wilk(x, y, swiat);
}
