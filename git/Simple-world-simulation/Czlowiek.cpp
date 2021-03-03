#include "Czlowiek.h"
#include <conio.h>
void Czlowiek::akcja()
{
	int new_x, new_y;
	if (umiejetnosc.GetMoc(swiat) == true)
	{
		swiat.UmiejetnoscObserwator();
	}
	std::cout << "Czlowiek: Co mam zrobic? " << std::endl;
	int c = 0;
	do
	{
		new_x = 0;
		new_y = 0;
		c = _getch();
		if( c != S)
			c = _getch();
		std::cout << "Podaj prawidlowy kierunek: ";
		switch (c) {
		case KEY_RIGHT:
			new_x = x + 1;
			std::cout << "Prawo";
			break;
		case KEY_LEFT:
			new_x = x - 1;
			std::cout << "Lewo";
			break;
		case KEY_UP:
			new_y = y - 1;
			std::cout << "Gora";
			break;
		case KEY_DOWN:
			std::cout << "Dol";
			new_y = y + 1;
			break;
		case S:
			if (umiejetnosc.SprawdzDostepnosc(swiat))
			{
				std::cout << "Moc";
				swiat.UmiejetnoscObserwator();
			}
			else
				std::cout << "Brak Mocy";
			break;

		}
		std::cout << std::endl;
	} while (((new_y > swiat.GetY() || new_y < 1) && (new_x > swiat.GetX() || new_x < 1))&&c!=S);
		if (c == S)
		{
			new_x = x;
			new_y = y;
		}
		else if (new_x == 0)
			new_x = x;
		else
			new_y = y;
	
	
	
	int index_ob = swiat.GetOrganizm(new_x, new_y);
	int index_at = swiat.GetOrganizm(x, y);
	if (index_ob != -1)
	{
		WynikKolizji wynikkolizjiPrzeciwnik;
		if (umiejetnosc.GetMoc(swiat) && swiat.GetSilaOrganizmu(index_ob) >= this->GetSila() )
		{
			wynikkolizjiPrzeciwnik = brak;
		}
		else
		{
			wynikkolizjiPrzeciwnik = swiat.ExecKolizja(index_ob, index_at);
		}

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
		else if (wynikkolizjiPrzeciwnik == odstraszenie)
		{
			
		}
		else if (wynikkolizjiPrzeciwnik == brak)
		{
			swiat.UcieczkaObserwator(GetGatunek());
			//nic nie robi bo dziala moc  a czlowiek zaatakowal organizm mocniejszy od siebie
			// jesli chce aby czlowiek nie zostawal po nie udanym ataku (na silniejszego) na swoim polu to musze wywolac metoda akcja dla zwierzecia a nie dla czlowiek z tego miejsca 
		}
		else if (wynikkolizjiPrzeciwnik == zatrucie)
		{
			index_at = swiat.GetOrganizm(x, y);
			swiat.RemoveOrganizm(index_at);
		}
		
	}
	else
	{
		x = new_x;
		y = new_y;
	}
}

WynikKolizji Czlowiek::walka(int index_ob) {
	if (swiat.GetSilaOrganizmu(index_ob) >= this->GetSila())
	{
		if ( umiejetnosc.GetMoc(swiat) )
		{
			
			int new_x, new_y;
			if (losujWolne(x, y, new_x, new_y))
			{
			y = new_y;
			x = new_x;
			}
			swiat.UcieczkaObserwator(this->GetGatunek());
			return ucieczka;
		}
			else
			{
				return smierc;
			}
	}
	else if (swiat.GetSilaOrganizmu(index_ob) < this->GetSila())
	{
		swiat.SmiercObserwator(swiat.GetGatunek(index_ob), GetGatunek());
		swiat.RemoveOrganizm(index_ob);
		return wygrana;
	}
}

Czlowiek::Czlowiek( Swiat& swiat) : Zwierze(swiat)
{
	
	this->SetId(0);
	this->SetSila(5);
	this->SetInicjatywa(4);
	this->SetGatunek("Czlowiek");
	int new_x, new_y;
	do {
		new_x = 1 + rand() % this->swiat.GetY();
		new_y = 1 + rand() % this->swiat.GetX();
	} while (swiat.GetOrganizm(new_x, new_y) != -1);
	x = new_x;
	y = new_y;
}

Czlowiek::Czlowiek(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y) : Zwierze(Id, sila, inicjatywa, gatunek, swiat, x, y)
{
	this->swiat = swiat;
	this->SetId(Id);
	this->SetSila(sila);
	this->SetInicjatywa(inicjatywa);
	this->SetGatunek(gatunek);
	int new_x, new_y;
	do {
		if (x < swiat.GetX() && x > 1)// numeracja pol w polu powinna zaczyna sie od jeden 
		{
			new_x = x + rand() % 3 - 1;
		}
		else if (x < swiat.GetX() )
		{
			new_x = x + rand() % 2 - 1;
		}
		else if (x > 1)
		{
			new_x = x + rand() % 2;
		}

		if (y < swiat.GetY() && y > 1)// numeracja pol w swiecie powinna zaczynac sie od jeden 
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
		new_y = rand() % this->swiat.GetY();
	} while (swiat.GetOrganizm(new_x, new_y) == -1);
	this->x = new_x;
	this->y = new_y;
}

void Czlowiek::rysowanie()
{
	std::cout <<green<< 'H'<<white;
}

void Czlowiek::rozmnazanie()
{
	Czlowiek* potomek = new Czlowiek(this->GetId(), this->GetSila(), this->GetInicjatywa(), this->GetGatunek(), swiat, x, y);
	swiat.DodajOrganizm(potomek);
}
