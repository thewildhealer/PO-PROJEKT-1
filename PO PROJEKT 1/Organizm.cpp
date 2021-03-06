#include "Organizm.h"

Organizm::Organizm(Swiat& swiat) : swiat(swiat) {
	do {
		x = rand() % swiat.getSzerokosc();
		y = rand() % swiat.getWysokosc();
	}
	while (swiat.getRysunek(x, y) != nullptr);
	swiat.setRysunek(x, y, this);
}

Organizm::Organizm(int x, int y, Swiat& swiat) : x(x), y(y), swiat(swiat) {
	if (swiat.getRysunek(x, y) == nullptr)
		swiat.setRysunek(x, y, this);
	else Organizm::~Organizm();
}

Organizm::~Organizm() {
}

int Organizm::getX() const {
	return x;
}

int Organizm::getY() const {
	return y;
}

int Organizm::getInicjatywa() const {
	return inicjatywa;
}

int Organizm::getPrevX() const {
	return prevX;
}

int Organizm::getPrevY() const {
	return prevY;
}

void Organizm::setPrevX(int prevX) {
	this->prevX = prevX;
}

void Organizm::setPrevY(int prevY) {
	this->prevY = prevY;
}

int Organizm::getSila() const {	
	return sila;
}

void Organizm::setX(int x) {
	this->x = x;
}

void Organizm::setY(int y) {
	this->y = y;
}
