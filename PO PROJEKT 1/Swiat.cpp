#include "Swiat.h"


Swiat::Swiat() : szerokosc(5), wysokosc(5), komentator(new Komentator) {
	inicjalizujRysunek();
}

Swiat::Swiat(int x, int y) : szerokosc(x), wysokosc(y), komentator(new Komentator) {
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

void Swiat::inicjalizujRysunek() {
	rysunek = new Organizm*[szerokosc * wysokosc];
	for (int i = 0; i < szerokosc * wysokosc; i++)
		rysunek[i] = nullptr;
}

void Swiat::wykonajTure() {
	for (int i = 0; i < organizmy.size(); i++) {
		organizmy[i]->akcja();
	}
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
		std::cout << i;
	std::cout << std::endl;
	for (int i = 0; i < wysokosc; i++) {
		std::cout << i << "|";
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
}
