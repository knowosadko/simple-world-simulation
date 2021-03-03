#include "WilczaJagoda.h"
#include "Swiat.h"
WilczaJagoda::WilczaJagoda(Swiat& swiat) : Roslina(swiat)
{
	this->praw = 35;
	this->SetId(13);
	this->SetSila(0);
	this->SetInicjatywa(0);
	this->SetGatunek("Wilcza jagoda");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}

void WilczaJagoda::rosnij(int x, int y)
{
	WilczaJagoda* potomek = new WilczaJagoda(GetId(), GetSila(), GetInicjatywa(), GetGatunek(), swiat, x, y, praw);
	swiat.DodajOrganizm(potomek);
}

WilczaJagoda::WilczaJagoda(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y,int praw) : Roslina(Id, sila, inicjatywa, gatunek, swiat, x, y, praw) {};

void WilczaJagoda::rysowanie()
{
	std::cout << "J";
}



WynikKolizji WilczaJagoda::efektZjedzenia(int index)
{
	int index_self = swiat.GetOrganizm(x,y);
	swiat.ZatruloObserwator(swiat.GetGatunek(index),GetGatunek());
	swiat.RemoveOrganizm(index_self);
	return zatrucie;
}