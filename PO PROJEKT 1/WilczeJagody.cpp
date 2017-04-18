#include "WilczeJagody.h"



WilczeJagody::WilczeJagody(Swiat& swiat) : Roslina(swiat) {
	sila = 99;
}

WilczeJagody::WilczeJagody(int x, int y, Swiat& swiat) : Roslina(x, y, swiat) {
	sila = 99;
}

WilczeJagody::~WilczeJagody()
{
}

char WilczeJagody::rysowanie() {
	return 'J';
}

void WilczeJagody::zasiej(int x, int y) {
	swiat.dodajOrganizm(new WilczeJagody(x, y, swiat));
}

std::string WilczeJagody::getNazwa() {
	return "Wilcza jagoda";
}
