#pragma once
#include "Zwierze.h"
#include "Swiat.h"
class Lis : public Zwierze {
public:
	Lis(Swiat& Swiat);
	Lis(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y);
	WynikKolizji walka(int index_ob) override;
	void rozmnazanie() override;
	void akcja();
	void rysowanie() override;
	bool losujSlabszego(int x,int y,int& new_x,int& new_y);
};