#include "Antylopa.h"
Antylopa::Antylopa(Swiat& swiat) : Zwierze(swiat)
{
	plodny = 3;
	this->SetId(5);
	this->SetSila(4);
	this->SetInicjatywa(4);
	this->SetGatunek("Antylopa");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}

Antylopa::Antylopa(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y) : Zwierze(Id, sila, inicjatywa, gatunek, swiat, x, y)
{
	
	//dane dla komentatora
}
void Antylopa::rozmnazanie()
{
	int new_x, new_y;
	if (losujWolne(x, y, new_x, new_y))
	{
		Antylopa* potomek = new Antylopa(this->GetId(), this->GetSila(), this->GetInicjatywa(), this->GetGatunek(), swiat, x, y);
		swiat.DodajOrganizm(potomek);
	}
	
}

void Antylopa::akcja()
{
	plodny++;
		int new_x;
		int new_y;
		if (0 == rand() % 3)
		{

			if (x < swiat.GetX() && x > 1)// numeracja pol w polu powinna zaczyna sie od jeden 
			{
				new_x = x + rand() % 3 - 1;
			}
			else if (x < swiat.GetX())
			{
				new_x = x + rand() % 2;
			}
			else if (x > 1)
			{
				new_x = x + rand() % 2 - 1;
			}

			if (y < swiat.GetY() && y > 1)// numeracja pol w swiecie powinna zaczyna sie od jeden 
			{
				new_y = y + rand() % 3 - 1;
			}
			else if (y < swiat.GetY())
			{
				new_y = y + rand() % 2;
			}
			else if (y > 1)
			{
				new_y = y + rand() % 2 - 1;
			}
		}
		else
		{
			if (x < swiat.GetX() - 1 && x > 2)// numeracja pol w polu powinna zaczyna sie od jeden 
			{
				new_x = x + rand() % 5 - 2;
			}
			else if (x < swiat.GetX() - 1)
			{
				new_x = x + rand() % 3;
			}
			else if (x > 2)
			{
				new_x = x + rand() % 3 - 2;
			}

			if (y < swiat.GetY() - 1 && y > 2)// numeracja pol w swiecie powinna zaczyna sie od jeden 
			{
				new_y = y + rand() % 5 - 2;
			}
			else if (y < swiat.GetY() - 1 )
			{
				new_y = y + rand() % 3;
			}
			else if (y > 2)
			{
				new_y = y + rand() % 3 - 2;
			}
		}
		if (new_y != y || new_x != x)
		{

			int index_ob = swiat.GetOrganizm(new_x, new_y);
			int index_at = swiat.GetOrganizm(x, y);
			if (index_ob != -1)
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
			else
			{
				y = new_y;
				x = new_x;
			}
		}
	
}

WynikKolizji Antylopa::walka(int index_ob)
{
	if ( 0 == rand() % 2)
	{
		int new_x, new_y;
		do {
			if (x < swiat.GetX() && x > 1)// numeracja pol w polu powinna zaczyna sie od jeden 
			{
				new_x = x + rand() % 3 - 1;
			}
			else if (x < swiat.GetX())
			{
				new_x = x + rand() % 2 - 1;
			}
			else if (x > 1)
			{
				new_x = x + rand() % 2;
			}

			if (y < swiat.GetY() && y > 1)// numeracja pol w swiecie powinna zaczyna sie od jeden 
			{
				new_y = y + rand() % 3 - 1;
			}
			else if (y < swiat.GetY())
			{
				new_y = y + rand() % 2 - 1;
			}
			else if (y > 1)
			{
				new_y = y + rand() % 2;
			}
		} while (swiat.GetOrganizm(new_x, new_y) == -1);
		y = new_y;
		x = new_x;
		swiat.UcieczkaObserwator(GetGatunek());
		return ucieczka;
	}
	else
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
		}
	}

}

void Antylopa::rysowanie()
{
	std::cout << 'A';
}