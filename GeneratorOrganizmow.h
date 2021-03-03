#pragma once
#include "Organizm.h"
#include "Swiat.h"
#include "Roslina.h"

class GeneratorOrganizmow
{
private:
	Swiat& swiat;
public:
	GeneratorOrganizmow(Swiat& swiat);
	void ProsteGenerowanie(int ilosc);
	Organizm* RozkladOrganizmow(int i);
};