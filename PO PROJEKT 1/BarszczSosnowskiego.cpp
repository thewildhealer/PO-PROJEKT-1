#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& swiat) : Roslina(swiat) {
	sila = 10;
}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat& swiat) : Roslina(x, y, swiat) {
	sila = 10;
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}

char BarszczSosnowskiego::rysowanie() {
	return 'B';
}

void BarszczSosnowskiego::zasiej(int x, int y) {
	swiat.dodajOrganizm(new BarszczSosnowskiego(x, y, swiat));
}

void BarszczSosnowskiego::akcja() {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++)
			if (x + i >= 0 && y + j >= 0 && x + i <= swiat.getSzerokosc() - 1 && y + j <= swiat.getWysokosc() - 1 &&
				swiat.getRysunek(x + i, y + j) != nullptr && swiat.getRysunek(x + i, y + j)->getType() != 'r') {
				swiat.umrzyj(this, swiat.getRysunek(x + i, y + j));
			}
	}
	Roslina::akcja();
}

std::string BarszczSosnowskiego::getNazwa() {
	return "Barszcz sosnowskiego";
}
