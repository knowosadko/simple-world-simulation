#include "Wilk.h"

Wilk::Wilk(Swiat& swiat) : Zwierze(swiat)
{
	plodny = 3;
	this->SetId(1);
	this->SetSila(9);
	this->SetInicjatywa(5);
	this->SetGatunek("Wilk");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}


Wilk::Wilk(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y) : Zwierze(Id, sila, inicjatywa, gatunek, swiat, x, y)
{
	//dane dla komentatora
}

void Wilk::rozmnazanie()
{
	int new_x, new_y;
	if (losujWolne(x, y, new_x, new_y))
	{
		Wilk* potomek = new Wilk(this->GetId(), this->GetSila(), this->GetInicjatywa(), this->GetGatunek(), swiat, x, y);
		swiat.DodajOrganizm(potomek);
	}
	
}

WynikKolizji Wilk::walka(int index_ob)
{

	if (swiat.GetSilaOrganizmu(index_ob) >= this->GetSila())
	{
			return smierc;
	}
	else if (swiat.GetSilaOrganizmu(index_ob) < this->GetSila())
	{

		swiat.SmiercObserwator(swiat.GetGatunek(index_ob), GetGatunek() );
		swiat.RemoveOrganizm(index_ob);
		return wygrana;
	}
}

void Wilk::rysowanie()
{
	std::cout << 'W';
}
