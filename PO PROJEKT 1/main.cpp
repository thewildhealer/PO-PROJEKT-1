#pragma once

#include <iostream>
#include <ctime>
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Komentator.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "WilczeJagody.h"
#include "Guarana.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"

int main() {
	srand(time(NULL));

	Swiat swiat(40, 20);
	std::vector<Organizm *> organizmy;


	organizmy.push_back(new Czlowiek(swiat));
	organizmy.push_back(new Trawa(swiat));
	organizmy.push_back(new Mlecz(swiat));
	organizmy.push_back(new Guarana(swiat));
	organizmy.push_back(new WilczeJagody(swiat));
	organizmy.push_back(new BarszczSosnowskiego(swiat));

	for (int i = 0; i < 5; i++) {
		organizmy.push_back(new Zolw(swiat));
		organizmy.push_back(new Antylopa(swiat));
		//		organizmy.push_back(new Lis(swiat));
		organizmy.push_back(new Owca(swiat));
		organizmy.push_back(new Wilk(swiat));
	}

	for (Organizm* org : organizmy) {
		swiat.dodajOrganizm(org);
	}
	swiat.rysujSwiat();
	//	while (std::cin.get()) {
	while (true) {
		swiat.wykonajTure();
		system("cls");
		swiat.rysujSwiat();

	}

	return 0;
}
