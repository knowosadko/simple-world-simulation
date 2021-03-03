#include "Lis.h"

Lis::Lis(Swiat& swiat) : Zwierze(swiat)
{
	plodny = 3;
	this->SetId(3);
	this->SetSila(3);
	this->SetInicjatywa(7);
	this->SetGatunek("Lis");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	this->x = new_x;
	this->y = new_y;
}

Lis::Lis(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y) : Zwierze(Id, sila, inicjatywa, gatunek, swiat, x, y)
{
//dane dla komentatora
}

void Lis::rozmnazanie()
{
	int new_x, new_y;
	if (losujWolne(x, y, new_x, new_y))
	{
		Lis* potomek = new Lis(this->GetId(), this->GetSila(), this->GetInicjatywa(), this->GetGatunek(), swiat, new_x, new_y);
		swiat.DodajOrganizm(potomek);
	}
}

WynikKolizji Lis::walka(int index_ob)
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

void Lis::akcja()
{
	plodny++;
	int new_x = x;
	int new_y = y;
	losujSlabszego(x, y, new_x, new_y);
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
			else if (wynikkolizjiPrzeciwnik == odstraszenie){}
		}
		else
		{
			y = new_y;
			x = new_x;
		}
	}
}

void Lis::rysowanie()
{
	std::cout << 'L';
}

bool Lis::losujSlabszego(int x, int y, int& new_x, int& new_y)
{
	bool wolne[9];
	for (int i = 0; i < 9; i++)
		wolne[i] = false;

	int l = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (x + j - 1 >= 1 && x + j - 1 <= swiat.GetX())
			{
				if (y + i - 1 >= 1 && y + i - 1 <= swiat.GetY())
				{
					if (swiat.GetOrganizm(x + j - 1, y + i - 1) == -1)
					{
						wolne[i * 3 + j] = true;
						l++;
					}
					if (swiat.GetOrganizm(x + j - 1, y + i - 1) != -1)
					{
						if (swiat.GetSilaOrganizmu(swiat.GetOrganizm(x + j - 1, y + i - 1)) < this->GetSila())
						{
							wolne[i * 3 + j] = true;
							l++;
						}
					}
				}
			}
		}
	if (l == 0) return false;
	int whichOne = rand() % l + 1;
	int k = 0;
	int i = -1;
	while (k != whichOne)
	{
		++i;
		if (wolne[i] == true) k++;
	}
	new_x = x + i % 3 - 1;
	new_y = y + i / 3 - 1;

	return true;
}