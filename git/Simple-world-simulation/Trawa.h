#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
public:
	Trawa(Swiat& swiat);
	Trawa(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y,int praw);
	WynikKolizji efektZjedzenia(int index) { return smierc; };
	void specjalna() {};
	void rosnij(int x, int y) override;
	void rysowanie() override;

};