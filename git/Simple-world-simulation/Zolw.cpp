#include "Zolw.h"

Zolw::Zolw(Swiat& swiat) : Zwierze(swiat)
{
	plodny = 3;
	this->SetId(4);
	this->SetSila(2);
	this->SetInicjatywa(1);
	this->SetGatunek("Zolw");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}

Zolw::Zolw(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y) : Zwierze(Id, sila, inicjatywa, gatunek, swiat, x, y)
{
	//dane dla komentatora
}

void Zolw::rozmnazanie()
{
	int new_x, new_y;
	if (losujWolne(x,y,new_x,new_y))
	{
		Zolw* potomek = new Zolw(this->GetId(), this->GetSila(), this->GetInicjatywa(), this->GetGatunek(), swiat, x, y);
		swiat.DodajOrganizm(potomek);
	}
}

WynikKolizji Zolw::walka(int index_ob)
{
	if (swiat.GetSilaOrganizmu(index_ob) >= this->GetSila())
	{
		return smierc;
	}
	else if (swiat.GetSilaOrganizmu(index_ob) < 5 )
	{
		swiat.ObronaObserwator(this->GetGatunek(),swiat.GetGatunek(index_ob));
		return odstraszenie;
	}
}

void Zolw::akcja()
{
	plodny++;
	if (0 == rand() % 4)
	{
		int new_x;
		int new_y;
		losuj(x, y, new_x, new_y);
		if (new_y != y || new_x != x)
		{

			int index_ob = swiat.GetOrganizm(new_x, new_y);
			int index_at = swiat.GetOrganizm(x, y);
			if (index_ob != -1)
			{
				if (swiat.GetSilaOrganizmu(index_ob) < 5)
				{
					this->walka(index_ob);
				}
				else
					{
						WynikKolizji wynikkolizjiPrzeciwnik = swiat.ExecKolizja(index_ob, index_at);
						if (wynikkolizjiPrzeciwnik == smierc)
						{
							y = new_y;
							x = new_x;
							this->walka(index_ob);
						}
						else if (wynikkolizjiPrzeciwnik == ucieczka)
						{
							y = new_y;
							x = new_x;
						}
						else if (wynikkolizjiPrzeciwnik == potomek)
						{
							this->rozmnazanie();
						}
						else if (wynikkolizjiPrzeciwnik == zatrucie)
						{
							index_at = swiat.GetOrganizm(x, y);
							swiat.RemoveOrganizm(index_at);
						}
					}
				}
			else
			{
				y = new_y;
				x = new_x;
			}
		}
	}
}


void Zolw::rysowanie()
{
	std::cout << 'Z';
}


