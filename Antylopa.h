#pragma once
#include "Zwierze.h"
#include "Swiat.h"

class Antylopa : public Zwierze
{
public:
	Antylopa(Swiat& Swiat);
	Antylopa(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y);
	WynikKolizji walka(int index_ob) override;
	void akcja() override;
	void rozmnazanie() override;
	void rysowanie() override;
};