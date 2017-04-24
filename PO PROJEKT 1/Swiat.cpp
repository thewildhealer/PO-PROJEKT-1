#include "Swiat.h"
#include "Wilk.h"
#include "Czlowiek.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Owca.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"


Swiat::Swiat() : szerokosc(5), wysokosc(5), komentator(new Komentator), breakFlag(false) {
	inicjalizujRysunek();
}

Swiat::Swiat(int x, int y) : szerokosc(x), wysokosc(y), komentator(new Komentator), breakFlag(false) {
	inicjalizujRysunek();
}

int Swiat::getSzerokosc() const {
	return szerokosc;
}

int Swiat::getWysokosc() const {
	return wysokosc;
}

void Swiat::dodajOrganizm(Organizm* organizm) {

	organizmy.push_back(organizm);

	if (organizmy.size() > 1) {
		int i = organizmy.size() - 1;
		while (organizmy[i - 1]->getInicjatywa() < organizmy[i]->getInicjatywa()) {
			std::swap(organizmy[i - 1], organizmy[i]);
			if (i > 1) i--;
			else break;
		}
	}
}

void Swiat::umrzyj(Organizm* napastnik, Organizm* ofiara) {
	komentator->komentujSmierc(napastnik, ofiara);
	setRysunek(ofiara->getX(), ofiara->getY(), nullptr);
	setRysunek(napastnik->getX(), napastnik->getY(), napastnik);
	organizmy.erase(std::remove(organizmy.begin(), organizmy.end(), ofiara), organizmy.end());
}

void Swiat::narodziny(Organizm* org, int x, int y) {
	komentator->komentujNarodziny(org, x, y);
}

void Swiat::nowaRoslina(Organizm* org, int x, int y) {
	komentator->komentujNowaRoslina(org, x, y);
}

void Swiat::nieudanyAtak(Organizm* napastnik, Organizm* ofiara) {
	komentator->komentujNieudanyAtak(napastnik, ofiara);
}

void Swiat::umiejetnoscAktywowana(Organizm* org, int czasTrwania) {
	komentator->komentujUmiejetnosc(org, czasTrwania);
}

void Swiat::zapiszSwiat() {
	std::ofstream plik;
	plik.open("zapis.sav");
	plik << organizmy.size() << " " << wysokosc << " " << szerokosc << std::endl;
	for (Organizm* org : organizmy) {
		plik << org->rysowanie() << " " << org->getX() << " " << org->getY() << std::endl;
	}
	plik.close();
}

void Swiat::otworzSwiat() {
	FILE* file = fopen("zapis.sav", "r");
	if (file == NULL) {
		return;
	}
	char gatunek;
	int orgX, orgY, size;
	fscanf(file, "%d %d %d\n", &size, &wysokosc, &szerokosc);
	delete[] rysunek;
	inicjalizujRysunek();
	int rozmiarOrg = organizmy.size();
	breakFlag = true;
	organizmy.clear();
	while (size--) {
		fscanf(file, "%c %d %d\n", &gatunek, &orgX, &orgY);
		if (gatunek == 'w') dodajOrganizm(new Wilk(orgX, orgY, *this));
		if (gatunek == 'o') dodajOrganizm(new Owca(orgX, orgY, *this));
		if (gatunek == 'l') dodajOrganizm(new Lis(orgX, orgY, *this));
		if (gatunek == 'z') dodajOrganizm(new Zolw(orgX, orgY, *this));
		if (gatunek == 'a') dodajOrganizm(new Antylopa(orgX, orgY, *this));
		if (gatunek == 'c') dodajOrganizm(new Czlowiek(orgX, orgY, *this));
		
		if (gatunek == 'T') dodajOrganizm(new Trawa(orgX, orgY, *this));
		if (gatunek == 'M') dodajOrganizm(new Mlecz(orgX, orgY, *this));
		if (gatunek == 'G') dodajOrganizm(new Guarana(orgX, orgY, *this));
		if (gatunek == 'J') dodajOrganizm(new WilczeJagody(orgX, orgY, *this));
		if (gatunek == 'B') dodajOrganizm(new BarszczSosnowskiego(orgX, orgY, *this));
	}
}
void Swiat::aktualizujRysunek() {
	// w razie czego, usuwanie duplikatow pod koniec tury , tego pewnie mogloby nawet tu nie byc jakby zalezalo mi na wydajnosci
	for (int i = 0; i < szerokosc * wysokosc; i++)
		rysunek[i] = nullptr;
	for (Organizm* org : organizmy)
		setRysunek(org->getX(), org->getY(), org);
}

void Swiat::inicjalizujRysunek() {
	rysunek = new Organizm*[szerokosc * wysokosc];
	for (int i = 0; i < szerokosc * wysokosc; i++)
		rysunek[i] = nullptr;
}

void Swiat::wykonajTure() {

	for (int i = 0; i < organizmy.size(); i++) {
		if (!breakFlag) organizmy[i]->akcja();
	}
	if (breakFlag) breakFlag = false;

	aktualizujRysunek();
}



void Swiat::rysujSwiat() {
	/*
	for (Organizm* org : organizmy)
	{
		rysunek[org->getX()*szerokosc + org->getY()] = org;
	}
	*/
	std::cout << "X|";
	for (int i = 0; i < szerokosc; i++)
		std::cout << i%10;
	std::cout << std::endl;
	for (int i = 0; i < wysokosc; i++) {
		std::cout << i%10 << "|";
		for (int j = 0; j < szerokosc; j++)
			if (rysunek[j + i * szerokosc] == nullptr) std::cout << "_";
			else std::cout << rysunek[i * szerokosc + j]->rysowanie();
			std::cout << std::endl;
	}
	std::cout << organizmy.size() << "| " << std::endl;
	/*
	for (int i = 0; i < organizmy.size(); i++)
		std::cout << organizmy[i]->getInicjatywa() << " ";
		*/
	komentator->komentujTure();
}

void Swiat::setRysunek(int x, int y, Organizm* org) {
	rysunek[x + y * szerokosc] = org;
}
Organizm* Swiat::getRysunek(int x, int y) {
	return rysunek[x + y * szerokosc];
}

Swiat::~Swiat() {
	delete[] rysunek;
	organizmy.clear();
}
