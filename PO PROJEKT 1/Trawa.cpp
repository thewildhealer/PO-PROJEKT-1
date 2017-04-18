#include "Trawa.h"



Trawa::Trawa(Swiat& swiat) : Roslina(swiat) {
	sila = 0;
}

Trawa::Trawa(int x, int y, Swiat& swiat) : Roslina(x, y, swiat) {
	sila = 0;
}

Trawa::~Trawa()
{
}

char Trawa::rysowanie() {
	return 'T';
}

void Trawa::zasiej(int x, int y) {
	swiat.dodajOrganizm(new Trawa(x, y, swiat));
}

std::string Trawa::getNazwa() {
	return "Trawa";
}
