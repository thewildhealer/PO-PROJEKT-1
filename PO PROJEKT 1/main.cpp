#pragma once

#include <iostream>
#include <ctime>
#include "Swiat.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Wilk.h"
#include "Owca.h"
#include "Komentator.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "WilczeJagody.h"

int main() {
	srand(time(NULL));

	Swiat swiat(50, 20);
	std::vector<Organizm *> organizmy;
//	organizmy.push_back(new Mlecz(5, 5, swiat));
//	organizmy.push_back(new Trawa(swiat));
	organizmy.push_back(new WilczeJagody(swiat));
	
	for (int i = 0; i < 30; i++) {
//		organizmy.push_back(new Zolw(swiat));
		organizmy.push_back(new Antylopa(swiat));
//		 organizmy.push_back(new Lis(swiat));
//		organizmy.push_back(new Owca(swiat));
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
