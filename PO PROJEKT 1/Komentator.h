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

private:
	std::vector<std::string> komentarze;
	void wyczyscKomentarze();
	

};

