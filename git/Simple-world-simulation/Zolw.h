#pragma once
#include "Zwierze.h"
#include "Swiat.h"

class Zolw : public Zwierze
{
public:
	Zolw(Swiat& swiat);
	Zolw(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y);
	WynikKolizji walka(int index_ob) override;
	void akcja();
	void rozmnazanie() override;
	void rysowanie() override;
};