#include "Mlecz.h"


Mlecz::Mlecz(Swiat& swiat) : Roslina(swiat) {
}

Mlecz::Mlecz(int x, int y, Swiat& swiat) : Roslina(x,y,swiat) {
}

Mlecz::~Mlecz()
{
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		Roslina::akcja();
	}
}

char Mlecz::rysowanie() {
	return 'M';
}

void Mlecz::zasiej(int x, int y) {
	swiat.dodajOrganizm(new Mlecz(x, y, swiat));
}

std::string Mlecz::getNazwa() {
	return "Mlecz";
}
