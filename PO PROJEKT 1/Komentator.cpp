#include "Komentator.h"



Komentator::Komentator()
{
}


Komentator::~Komentator()
{
}

void Komentator::komentujTure() {
	for (std::string kom : komentarze)
		std::cout << kom << std::endl;
	wyczyscKomentarze();
}

void Komentator::komentujSmierc(Organizm* napastnik, Organizm* ofiara) {
	std::string pos = "[" + std::to_string(ofiara->getX()) + "," + std::to_string(ofiara->getY()) + "] ";
	std::string komentarz = napastnik->getNazwa() + " annihiluje: " + ofiara->getNazwa();
	komentarze.push_back(pos + komentarz);
}

void Komentator::komentujNarodziny(Organizm* org, int x, int y) {
	std::string pos = "[" + std::to_string(x) + "," + std::to_string(y) + "] ";
	std::string komentarz = "Narodzil/a sie nowy/a " + org->getNazwa() + "!";
	komentarze.push_back(pos + komentarz);
}

void Komentator::komentujNowaRoslina(Organizm* org, int x, int y) {
	std::string pos = "[" + std::to_string(x) + "," + std::to_string(y) + "] ";
	std::string komentarz = "Urosla nowa roslina: " + org->getNazwa() + "!";
	komentarze.push_back(pos + komentarz);
}

void Komentator::komentujNieudanyAtak(Organizm* napastnik, Organizm* ofiara) {
	std::string pos = "[" + std::to_string(ofiara->getX()) + "," + std::to_string(ofiara->getY()) + "] ";
	std::string komentarz = ofiara->getNazwa() + " odparl/a atak od: " + napastnik->getNazwa() + "!";
	komentarze.push_back(pos + komentarz);
}

void Komentator::komentujUmiejetnosc(Organizm* org, int czasTrwania) {
	std::string pos = "[" + std::to_string(org->getX()) + "," + std::to_string(org->getY()) + "] ";
	std::string komentarz = org->getNazwa() + " wlaczyl calopalenie! Bedzie trwac jeszcze przez " + std::to_string(5 - czasTrwania) + "tury.";
	komentarze.push_back(pos + komentarz);
}

void Komentator::wyczyscKomentarze() {
	komentarze.erase(komentarze.begin(), komentarze.end());
}
