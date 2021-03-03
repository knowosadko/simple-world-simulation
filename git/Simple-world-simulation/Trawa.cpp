#include "Trawa.h"
#include "Swiat.h"
Trawa::Trawa(Swiat& swiat) : Roslina(swiat)
{
	this->praw = 25;
	this->SetId(11);
	this->SetSila(0);
	this->SetInicjatywa(0);
	this->SetGatunek("Trawa");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
 }

void Trawa::rosnij(int x, int y)
{
	Trawa* potomek = new Trawa(GetId(),GetSila(),GetInicjatywa(),GetGatunek(),swiat,x,y,praw);
	swiat.DodajOrganizm(potomek);
}

Trawa::Trawa(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y,int praw) : Roslina(Id, sila, inicjatywa, gatunek, swiat, x, y,praw) {};

void Trawa::rysowanie()
{
	std::cout << "T";
}