#include "Zolw.h"


Zolw::Zolw(Swiat& swiat) : Zwierze(swiat) {
	sila = 2;
	inicjatywa = 1;
}

Zolw::Zolw(int x, int y, Swiat& swiat) : Zwierze(x, y, swiat) {
	sila = 2;
	inicjatywa = 1;
}


void Zolw::akcja() {
	int los = rand() % 4;
	if (!los) Zwierze::akcja();
}

void Zolw::kolizja(Organizm* napastnik) {
	if (napastnik->getSila() < 5 && napastnik->rysowanie() != 'z') {
		napastnik->setX(getPrevX());
		napastnik->setY(getPrevY());
		swiat.nieudanyAtak(napastnik, this);
	}
	else Zwierze::kolizja(napastnik); 
}

char Zolw::rysowanie() {
	return 'z';
}

void Zolw::kopuluj(int x, int y) {
	swiat.dodajOrganizm(new Zolw(x, y, swiat));
}

std::string Zolw::getNazwa() {
	return "Zolw";
}

Zolw::~Zolw() {
}
