#include "Zolw.h"


Zolw::Zolw(Swiat& swiat) : Zwierze(swiat) {
	sila = 4;
	inicjatywa = 4;
}

Zolw::Zolw(int x, int y, Swiat& swiat) : Zwierze(x, y, swiat) {
	sila = 4;
	inicjatywa = 4;
}


void Zolw::akcja() {
	int los = rand() % 2;
	if (los) Zwierze::akcja();
}

void Zolw::kolizja() {
	Zwierze::kolizja(); // tutaj dorzucic jakos trzeba odpieranie ataku
}

char Zolw::rysowanie() {
	return 'z';
}

void Zolw::kopuluj(int x, int y) {
	swiat.dodajOrganizm(new Zolw(x, y, swiat));
}

std::string Zolw::getNazwa() {
	return "Antylopa";
}

Zolw::~Zolw() {
}
