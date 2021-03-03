#pragma once
#include "Roslina.h"

class WilczaJagoda : public Roslina {
public:
	WilczaJagoda(Swiat& swiat);
	WilczaJagoda(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y, int praw);
	WynikKolizji efektZjedzenia(int index) override;
	void specjalna() {};
	void rosnij(int x, int y) override;
	void rysowanie() override;
};