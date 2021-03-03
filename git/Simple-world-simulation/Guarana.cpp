#include "Guarana.h"
#include "Swiat.h"
Guarana::Guarana(Swiat& swiat) : Roslina(swiat)
{
	this->praw = 20;
	this->SetId(14);
	this->SetSila(0);
	this->SetInicjatywa(0);
	this->SetGatunek("Guarana");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}

void Guarana::rosnij(int x, int y)
{
	Guarana* potomek = new Guarana(GetId(), GetSila(), GetInicjatywa(), GetGatunek(), swiat, x, y, praw);
	swiat.DodajOrganizm(potomek);
}

Guarana::Guarana(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y, int praw) : Roslina(Id, sila, inicjatywa, gatunek, swiat, x, y,praw) {};

void Guarana::rysowanie()
{
	std::cout << "G";
}



WynikKolizji Guarana::efektZjedzenia(int index)
{
	swiat.ZwiekszSilaOrganizmu(index,5);
	return smierc;
}

