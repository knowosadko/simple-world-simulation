#pragma once
#include "Zwierze.h"
#include "Swiat.h"
#include <conio.h>
#include "windows.h"
#include "ConsoleColor.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define S 115
class Czlowiek : public Zwierze {
	class Umiejetnosc {
		private:
			int OstatnieUzycieMocy;
			bool moc;
		public:
			bool SprawdzDostepnosc(Swiat& swiat)
			{
				if (swiat.KtoraTura() > OstatnieUzycieMocy + 5)
				{
					OstatnieUzycieMocy = swiat.KtoraTura();
					moc = true;
					return true;
				}
				else
					return false;
			}
			
			Umiejetnosc()
			{
				moc = false;
				OstatnieUzycieMocy = -5;
			}
			bool GetMoc(Swiat& swiat)
			{
				if ((swiat.KtoraTura() > OstatnieUzycieMocy + 5) && moc == true )
				{
					moc = false;
				}
				return moc;
			}
	};
	Umiejetnosc umiejetnosc;
public:
	Czlowiek(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y);
	Czlowiek( Swiat& swiat);
	void akcja();
	WynikKolizji walka(int ID) override;
	void rysowanie() override;
	void rozmnazanie() override;
	bool getMoc()
	{
		return umiejetnosc.GetMoc(swiat);
	}
 };
