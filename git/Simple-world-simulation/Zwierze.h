#pragma once
#include "Organizm.h"
#include "Swiat.h"
#include <string>
#include <iostream>
class Zwierze : public Organizm
{
private:
	int GetPraw() { return 0; };
protected:
	int plodny;
public:
	Zwierze() = default;
	Zwierze(Swiat& swiat) : Organizm(swiat) {};
	Zwierze(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y);
	void akcja();
	WynikKolizji kolizja(int ID) override;
	virtual void rozmnazanie() = 0;
	virtual WynikKolizji walka(int ID) = 0;
	bool CzyPlodny()
	{
		if (plodny >= 4)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};