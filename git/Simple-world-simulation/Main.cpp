#include "Swiat.h"
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <conio.h>
int main()
{
	srand(time(NULL));
	int wybor;
	std::cout << "1. Nowa Symulacja"<<std::endl;
	std::cout << "2. Wczytaj symulacje" << std::endl;
	std::cout << "3. Wyjscie" << std::endl;
	std::cin >> wybor;
	if (wybor == 1)
	{
		int x, y;
		std::cout << "Podaj szerokosc swiata X: ";
		std::cin >> x;
		std::cout << std::endl;
		std::cout << "Podaj szerokosc swiata Y: ";
		std::cin >> y;
		std::cout << std::endl;
		Swiat swiat(x,y);
		GeneratorOrganizmow GeneratorOrganizmow(swiat);
		swiat.rysujSwiat();
		char c;
		while (1)
		{
			
			swiat.wykonajTure();
			swiat.sortujOrganizmy();
			std::cout << " s - zapisz ; l - wczytaj ; q - zakoncz  ; n - nastepna tura";
			c = _getch();
			std::cout << std::endl;
			if (c == 's')
				swiat.zapisz();
			if (c == 'l')
				swiat.wczytaj(swiat);
			if (c == 'q')
				return 0;
			
			
			
		}
	}
	else if (wybor == 2)
	{
		Swiat swiat(0, 0);
		swiat.wczytaj(swiat);
		swiat.rysujSwiat();
		char c;
		while (1)
		{
			swiat.wykonajTure();
			swiat.sortujOrganizmy();
			std::cout << " s - zapisz ; l - wczytaj ; q - zakoncz ; m - wiecej opcji ; n - nastepna tura";
			c = _getch();
			if (c == 's')
				swiat.zapisz();
			if (c == 'l')
				swiat.wczytaj(swiat);
			if (c == 'q')
				return 0;
		}
	}
	else if (wybor == 3)
		return 0;
	
	
	system("pause");
	return 0;
}