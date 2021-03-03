#include "Barszcz.h"
#include "Swiat.h"
Barszcz::Barszcz(Swiat& swiat) : Roslina(swiat)
{
	this->praw = 100;
	this->SetId(15);
	this->SetSila(10);
	this->SetInicjatywa(0);
	this->SetGatunek("Barszcz Sosnowskiego");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}

void Barszcz::rosnij(int x, int y)
{
	Barszcz* potomek = new Barszcz(GetId(), GetSila(), GetInicjatywa(), GetGatunek(), swiat, x, y, praw);
	swiat.DodajOrganizm(potomek);
}

Barszcz::Barszcz(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y, int praw) : Roslina(Id, sila, inicjatywa, gatunek, swiat, x, y, praw) {};

void Barszcz::rysowanie()
{
	std::cout << "B";
}



WynikKolizji Barszcz::efektZjedzenia(int index)
{
	
	int index_self = swiat.GetOrganizm(x, y);
	swiat.ZatruloObserwator(swiat.GetGatunek(index), GetGatunek());
	swiat.RemoveOrganizm(index_self);
	return zatrucie;
}

void Barszcz::specjalna()
{
	int index;
	index = swiat.GetOrganizm(x - 1, y);
	if (index != -1)
	{
		if (this->GetSila() >= swiat.GetSilaOrganizmu(index))
		{
			if (swiat.ExecKolizja(index, swiat.GetOrganizm(x, y)) == smierc)
			{
				swiat.PoparzonyObserwator(swiat.GetGatunek(index));
				swiat.RemoveOrganizm(index);
			}
		}
		
	}
	index = swiat.GetOrganizm(x + 1, y);
	if (index != -1)
	{
		if (this->GetSila() >= swiat.GetSilaOrganizmu(index))
		{
			if (swiat.ExecKolizja(index, swiat.GetOrganizm(x, y)) == smierc)
			{
				swiat.PoparzonyObserwator(swiat.GetGatunek(index));
				swiat.RemoveOrganizm(index);
			}
		}
	}
	index = swiat.GetOrganizm(x - 1, y - 1);
	if (index != -1)
	{
		if (this->GetSila() >= swiat.GetSilaOrganizmu(index))
		{
			if (swiat.ExecKolizja(index, swiat.GetOrganizm(x, y)) == smierc)
			{
				swiat.PoparzonyObserwator(swiat.GetGatunek(index));
				swiat.RemoveOrganizm(index);
			}
		}
	}
	index = swiat.GetOrganizm(x - 1, y + 1 );
	if (index != -1)
	{
		if (this->GetSila() >= swiat.GetSilaOrganizmu(index))
		{
			if (swiat.ExecKolizja(index, swiat.GetOrganizm(x, y)) == smierc)
			{
				swiat.PoparzonyObserwator(swiat.GetGatunek(index));
				swiat.RemoveOrganizm(index);
			}
		}
	}
	index = swiat.GetOrganizm(x + 1, y - 1);
	if (index != -1)
	{
		if (this->GetSila() >= swiat.GetSilaOrganizmu(index))
		{
			if (swiat.ExecKolizja(index, swiat.GetOrganizm(x, y)) == smierc)
			{
				swiat.PoparzonyObserwator(swiat.GetGatunek(index));
				swiat.RemoveOrganizm(index);
			}
		}
	}
	index = swiat.GetOrganizm(x + 1, y + 1);
	if (index != -1)
	{
		if (this->GetSila() >= swiat.GetSilaOrganizmu(index))
		{
			if (swiat.ExecKolizja(index, swiat.GetOrganizm(x, y)) == smierc)
			{
				swiat.PoparzonyObserwator(swiat.GetGatunek(index));
				swiat.RemoveOrganizm(index);
			}
		}
	}
	index = swiat.GetOrganizm(x, y - 1);
	if (index != -1)
	{
		if (this->GetSila() >= swiat.GetSilaOrganizmu(index))
		{
			if (swiat.ExecKolizja(index, swiat.GetOrganizm(x, y)) == smierc)
			{
				swiat.PoparzonyObserwator(swiat.GetGatunek(index));
				swiat.RemoveOrganizm(index);
			}
		}
	}
	index = swiat.GetOrganizm(x, y + 1);
	if (index != -1)
	{
		if (this->GetSila() >= swiat.GetSilaOrganizmu(index))
		{
			if (swiat.ExecKolizja(index, swiat.GetOrganizm(x, y)) == smierc)
			{
				swiat.PoparzonyObserwator(swiat.GetGatunek(index));
				swiat.RemoveOrganizm(index);
			}
		}
	}
	
	//swiat.PoparzonyObserwator(swiat.GetGatunek(index));
	

	

}