#include "GeneratorOrganizmow.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Lis.h"
#include "Trawa.h"
#include "Guarana.h"
#include "WilczaJagoda.h"
#include "Mlecz.h"
#include "Barszcz.h"


 void GeneratorOrganizmow::ProsteGenerowanie(int ilosc)
 {

	 Czlowiek* czlowiek = new Czlowiek(swiat);
	swiat.DodajOrganizm(czlowiek);
	ilosc--;
	for (int i = 0; i < ilosc; i++)
	{
		swiat.DodajOrganizm(RozkladOrganizmow(i));
	}
}

GeneratorOrganizmow::GeneratorOrganizmow(Swiat& swiat) : swiat(swiat){
	int ilosc = 0;
	do {
		std::cout << "Ilosc organizmow: ";
		std::cin >> ilosc;
		if (ilosc >= (swiat.GetX()*swiat.GetY()) / 2 )
			std::cout << "Za duzo organizmow :(" << std::endl;
	} while (ilosc >= ((swiat.GetX()*swiat.GetY()) / 2));
	ProsteGenerowanie(ilosc);
};

Organizm* GeneratorOrganizmow::RozkladOrganizmow(int i)
{
	i = i % 10;
	switch (i)
	{
		case 0:
		{
			Organizm* zolw = new Zolw(swiat);
			return zolw;
			break;
			
		}
		case 1:
		{

			Organizm* wilk = new Wilk(swiat);
			return wilk;
			break;
		}
		case 2:
		{
			Organizm*antylopa = new Antylopa(swiat);
			return antylopa;
			break;
		 
		}
		case 3:
		{
			Organizm* owca = new Owca(swiat);
			return owca;
			break;
		}
		case 4:
		{
			Organizm* lis = new Lis(swiat);
			return lis;
			break;
		}
		case 5:
		{
			Organizm* trawa = new Trawa(swiat);
			return trawa; 
				break;
		}
		case 6:
		{
			Organizm* mlecz = new Mlecz(swiat);
			return mlecz;
			break;
		}
		case 7:
		{
			Organizm* guarana = new Guarana(swiat);
			return guarana;
			break;
		}
		case 8:
		{
			Organizm* wilczjagoda = new WilczaJagoda(swiat);
			return wilczjagoda;
			break;
		}
		case 9:
		{
			Organizm* barszcz = new Barszcz(swiat);
			return barszcz;
			break;
		}
	}
}

