#include "Roslina.h"

Roslina::Roslina(Swiat& swiat) : Organizm(swiat) {
	inicjatywa = 0;
}

Roslina::Roslina(int x, int y, Swiat& swiat) : Organizm(x, y, swiat) {
	inicjatywa = 0;
}

void Roslina::akcja() {
	int los = 0;
	int i = 0, j = 0;
	if (!los) {
		while (swiat.getRysunek(x + i, y + j) != nullptr) {
			i = (rand() % 3) - 1;
			j = (rand() % 3) - 1;
		}
		swiat.nowaRoslina(this, x + i, y + j);
		this->zasiej(x + i, y + j);
	}
}

void Roslina::kolizja() {
}

Roslina::~Roslina()
{
}
