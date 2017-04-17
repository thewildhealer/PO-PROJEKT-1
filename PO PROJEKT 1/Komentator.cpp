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
	std::string komentarz = napastnik->getNazwa() + " zjadl/a: " + ofiara->getNazwa();
	komentarze.push_back(pos + komentarz);
}

void Komentator::wyczyscKomentarze() {
	komentarze.erase(komentarze.begin(), komentarze.end());
}