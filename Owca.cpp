#include "Owca.h"
Owca::Owca(Swiat& swiat) : Zwierze(swiat)
{
	plodny = 1;
	this->SetId(2);
	this->SetSila(4);
	this->SetInicjatywa(4);
	this->SetGatunek("Owca");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}

Owca::Owca(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y) :  Zwierze(Id, sila, inicjatywa, gatunek, swiat, x, y)
{
	//dane dla komentatora
}

void Owca::rozmnazanie()
{
	int new_x, new_y;
	if (losujWolne(x, y, new_x, new_y))
	{
		Owca* potomek = new Owca(this->GetId(), this->GetSila(), this->GetInicjatywa(), this->GetGatunek(), swiat, new_x, new_y);
		swiat.DodajOrganizm(potomek);	
	}
}

WynikKolizji Owca::walka(int index_ob)
{
	if (swiat.GetSilaOrganizmu(index_ob) >= this->GetSila())
	{
		
		return smierc;
	}
	else if (swiat.GetSilaOrganizmu(index_ob) < this->GetSila())
	{
		swiat.SmiercObserwator(swiat.GetGatunek(index_ob), GetGatunek());
		swiat.RemoveOrganizm(index_ob);
		return wygrana;
	};
}

void Owca::rysowanie()
{
	std::cout << 'O';
}
 