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

char Owca::rysowanie() {
	return 'o';
}

void Owca::kopuluj(int x, int y) {
	swiat.dodajOrganizm(new Owca(x, y, swiat));
}

std::string Owca::getNazwa() {
	return "Owca";
}
