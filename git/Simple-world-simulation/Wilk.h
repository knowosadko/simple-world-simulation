#pragma once
#include "Zwierze.h"
#include "Swiat.h"
class Wilk : public Zwierze
{
public:
	Wilk(Swiat& swiat);
	Wilk(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y);
	WynikKolizji walka(int index_ob) override;
	void rozmnazanie() override;
	void rysowanie() override;
};