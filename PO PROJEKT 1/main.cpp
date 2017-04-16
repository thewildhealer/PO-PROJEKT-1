#pragma once

#include <iostream>
#include <ctime>
#include "Swiat.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"

int main() {
	srand(time(NULL));

	Swiat swiat(20, 10);
	std::vector<Organizm *> organizmy;

//	organizmy.push_back(new Owca(0,0, swiat));
//	organizmy.push_back(new Owca(1,1, swiat));
//	swiat.dodajOrganizm(new Owca(swiat));
	for (int i = 0; i < 10; i++) {
		organizmy.push_back(new Wilk(swiat));
	}

	for (Organizm* org : organizmy) {
		swiat.dodajOrganizm(org);
	}
	swiat.rysujSwiat();
	while (std::cin.get()) {
		swiat.wykonajTure();
		system("cls");
		swiat.rysujSwiat();

	}

	return 0;
}
