#include "Antylopa.h"


Antylopa::Antylopa(Swiat& swiat) : Zwierze(swiat) {
	sila = 4;
	inicjatywa = 4;
	mod = 2;
}

Antylopa::Antylopa(int x, int y, Swiat& swiat) : Zwierze(x, y, swiat) {
	sila = 4;
	inicjatywa = 4;
	mod = 2;
}


void Antylopa::akcja() {
	Zwierze::akcja();
}

void Antylopa::kolizja() {
	Zwierze::kolizja(); // tutaj dorzucic jakos trzeba 50% szans na ucieczke
}

char Antylopa::rysowanie() {
	return 'a';
}

void Antylopa::kopuluj(int x, int y) {
	swiat.dodajOrganizm(new Antylopa(x, y, swiat));
}

std::string Antylopa::getNazwa() {
	return "Antylopa";
}

Antylopa::~Antylopa() {
}
