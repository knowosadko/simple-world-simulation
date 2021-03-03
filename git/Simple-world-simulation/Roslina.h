#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
protected:
	int praw;
public:
	Roslina(Swiat& swiat);
	Roslina(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y, int praw);
	void akcja() override;
	virtual void rosnij(int x, int y) = 0;
	WynikKolizji kolizja(int index) override;
	virtual void specjalna() = 0;
	virtual WynikKolizji efektZjedzenia(int index) = 0;
	int GetPraw() { return praw; };
};


