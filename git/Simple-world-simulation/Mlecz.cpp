#include "Mlecz.h"
#include "Swiat.h"
Mlecz::Mlecz(Swiat& swiat) : Roslina(swiat)
{
	this->praw = 25;
	this->SetId(12);
	this->SetSila(0);
	this->SetInicjatywa(0);
	this->SetGatunek("Mlecz");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}

void Mlecz::rosnij(int new_x, int new_y)
{
	Mlecz* potomek = new Mlecz(GetId(), GetSila(), GetInicjatywa(), GetGatunek(), swiat, new_x, new_y, praw);
	swiat.DodajOrganizm(potomek);
}

Mlecz::Mlecz(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y ,int praw) : Roslina(Id, sila, inicjatywa, gatunek, swiat, x, y, praw) {};

void Mlecz::rysowanie()
{
	std::cout << "M";
}

void Mlecz::akcja()
{
	for (int i=0; i<3;i++)
	{
		if (1 == rand() % praw)
		{

			int new_x, new_y;
			if (losujWolne(x, y, new_x, new_y))
			{
				this->rosnij(new_x, new_y);
			}
		}
	}
}

