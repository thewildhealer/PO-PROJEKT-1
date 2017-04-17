#pragma once

#include <iostream>
#include <ctime>
#include "Swiat.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Komentator.h"
#include "Lis.h"

int main() {
	srand(time(NULL));

	Swiat swiat(50, 20);
	std::vector<Organizm *> organizmy;

	organizmy.push_back(new Owca(0,0, swiat));
	organizmy.push_back(new Owca(1,1, swiat));
	organizmy.push_back(new Lis(0, 1, swiat));
//	swiat.dodajOrganizm(new Owca(swiat));
	for (int i = 0; i < 10; i++) {
		organizmy.push_back(new Lis(swiat));
	}

	for (Organizm* org : organizmy) {
		swiat.dodajOrganizm(org);
	}
//	swiat.rysujSwiat();
	while (std::cin.get()) {
//	while (true) {
		swiat.wykonajTure();
		system("cls");
		swiat.rysujSwiat();

	}

	return 0;
}
