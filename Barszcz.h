#pragma once
#include "Roslina.h"
class Barszcz : public Roslina
{
public:
	Barszcz(Swiat& swiat);
	Barszcz(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y,int praw);
	WynikKolizji efektZjedzenia(int index) override;
	void specjalna() override;
	void rosnij(int x, int y) override;
	void rysowanie() override;
};