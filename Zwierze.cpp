#include "Zwierze.h"

void Zwierze::akcja()
{
	int new_x;
	int new_y;
	plodny++;
	losuj(x, y, new_x, new_y);
	if ( new_y != y || new_x != x)
	{

		int index_ob = swiat.GetOrganizm(new_x, new_y);
		int index_at = swiat.GetOrganizm(x, y);
		if (index_ob != -1)
		{
			WynikKolizji wynikkolizjiPrzeciwnik = swiat.ExecKolizja(index_ob,index_at);
			if(wynikkolizjiPrzeciwnik == smierc)
			{
				y = new_y;
				x = new_x;
				this->walka(index_ob);
			}
			else if(wynikkolizjiPrzeciwnik == ucieczka)
			{
				y = new_y;
				x = new_x;
			}
			else if (wynikkolizjiPrzeciwnik == potomek && CzyPlodny())
			{
				plodny = 0;
				this->rozmnazanie();
			}
			else if (wynikkolizjiPrzeciwnik == zatrucie)
			{
				index_at = swiat.GetOrganizm(x, y);
				swiat.RemoveOrganizm(index_at);//usuwa samego siebie
			}
		}
		else
		{
			y = new_y;
			x = new_x;
		}
	}
}

WynikKolizji Zwierze::kolizja(int index)
{
	if ( this->GetGatunek() == swiat.GetGatunek(index))
	{
		if (CzyPlodny())
			return potomek;
		else
			return brak;
	}
	else
	{
		return this->walka(index);
	}
}

Zwierze::Zwierze(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int new_x, int new_y) : Organizm(Id, sila, inicjatywa, gatunek, swiat, new_x, new_y) 
{
	plodny = 3;
	this->swiat = swiat;
	SetId(Id);
	SetSila(sila);
	SetInicjatywa(inicjatywa);
	SetGatunek(gatunek);
	swiat.NarodzinyObserwator(GetGatunek());
	this->x = new_x;
	this->y = new_y;
	
}