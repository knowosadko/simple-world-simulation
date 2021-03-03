#include "Organizm.h"

class Swiat// --------------------------------------------------Dodane bo inaczej nie dziala
{
public:
	int GetX();
	int GetY();
	int GetOrganizm(int x, int y);
};

void Organizm::losuj( int x, int y, int& new_x, int& new_y)
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

bool Organizm::losujWolne(int x, int y, int& new_x, int& new_y)
{
	bool wolne[9];
	for (int i = 0; i < 9; i++)
		wolne[i] = false;
	
	int l = 0;
	for(int i=0;i < 3;i++)
		for (int j = 0; j < 3; j++)
		{
			if (x + j - 1 >= 1 && x + j -1 <= swiat.GetX())
			{
				if (y + i - 1 >= 1 && y + i - 1 <= swiat.GetY())
				{
					if (swiat.GetOrganizm(x + j - 1, y + i - 1) == -1)
					{
					wolne[i*3+j] = true;
					l++;
					}
				}
			}
		}
	if (l == 0) return false;
	int whichOne = rand() % l + 1;
	int k = 0;
	int i = -1;
	while ( k!=whichOne )
	{
		++i;
		if (wolne[i] == true) k++;
	}
	new_x =x + i % 3 - 1;
	new_y =y + i / 3 - 1;

	return true;
}