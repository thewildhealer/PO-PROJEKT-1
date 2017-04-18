#include "Guarana.h"


Guarana::Guarana(Swiat& swiat) : Roslina(swiat) {
}

Guarana::Guarana(int x, int y, Swiat& swiat) : Roslina(x, y, swiat) {
}

Guarana::~Guarana()
{
}

char Guarana::rysowanie() {
	return 'G';
}

void Guarana::zasiej(int x, int y) {
	swiat.dodajOrganizm(new Guarana(x, y, swiat));

}

void Guarana::kolizja(Organizm* napastnik) {
	swiat.umrzyj(napastnik, this);
	napastnik->setSila(napastnik->getSila() + 3);
	swiat.setRysunek(x, y, napastnik);
	swiat.setRysunek(napastnik->getPrevX(), napastnik->getPrevY(), nullptr);
}

std::string Guarana::getNazwa() {
	return "Guarana";
}
