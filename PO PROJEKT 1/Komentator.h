#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Organizm.h"
class Organizm;
class Komentator
{
public:
	Komentator();
	~Komentator();

	void komentujTure();
	void komentujSmierc(Organizm * napastnik, Organizm * ofiara);
	void komentujNarodziny(Organizm * org, int x, int y);

private:
	std::vector<std::string> komentarze;
	void wyczyscKomentarze();
	

};

