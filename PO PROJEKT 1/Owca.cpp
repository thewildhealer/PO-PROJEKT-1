#include "Owca.h"


Owca::Owca(Swiat& swiat) : Zwierze(swiat) {
	inicjatywa = 4;
	sila = 4;
}

Owca::Owca(int x, int y, Swiat& swiat) : Zwierze(x, y, swiat) {
	inicjatywa = 4;
	sila = 4;
}

Owca::~Owca() {
}

void Owca::akcja() {
	Zwierze::akcja();
}

void Owca::kolizja() {
	Zwierze::kolizja();
}

char Owca::rysowanie() {
	return 'o';
}

void Owca::kopuluj(int x, int y) {
	swiat.dodajOrganizm(new Owca(x, y, swiat));
}
