#include "Roslina.h"
#include "Swiat.h"
Roslina::Roslina(Swiat& swiat) : Organizm(swiat) {}
Roslina::Roslina(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y, int praw) : Organizm(Id, sila, inicjatywa, gatunek, swiat, x, y,praw)
{
	this->praw = praw;
	SetId(Id);
	SetSila(sila);
	SetInicjatywa(inicjatywa);
	SetGatunek(gatunek);
	this->x = x;
	this->y = y;
	swiat.UrosloObserwator(this->GetGatunek());
}

void Roslina::akcja()
{
	if (1 == rand() % praw)
	{
		int new_x, new_y;
		if (losujWolne(x, y, new_x, new_y))
		{
			rosnij(new_x,new_y);
		}
	}
	specjalna();
}


WynikKolizji Roslina::kolizja(int index)// w barszczu do zasloniecia 
{

	return efektZjedzenia(index);
	
}