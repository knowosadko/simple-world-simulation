#pragma once

#include <string>
#include <cstdio>
class Swiat;
enum WynikKolizji {wygrana, smierc, ucieczka, odstraszenie, potomek , brak , wzmocnienie, zatrucie};
 class Organizm {
private:
	int sila;
	int inicjatywa;
	std::string gatunek;
	int Id;
 protected:
	int x;
	int y;
	Swiat& swiat;
 public:

	 Organizm(Swiat& swiat) : swiat(swiat) {};
	 Organizm(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y) : swiat(swiat) {};
	 Organizm(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y, int praw) : swiat(swiat) {};
	 int Getx()
	 {
		 return x;
	 }
	 int Gety()
	 {
		 return y;
	 }
	 int GetSila()
	 {
		 return sila;
	 }
	 void SetSila(int sila)
	 {
		 this->sila = sila;
	 }
	 int GetInicjatywa()
	 {
		 return inicjatywa;
	 }
	 void SetInicjatywa(int inicjatywa)
	 {
		 this->inicjatywa = inicjatywa;
	 }
	 std::string GetGatunek()
	 {
		 return gatunek;
	 }
	 void SetGatunek(std::string gatunek)
	 {
		 this->gatunek = gatunek;
	 }
	 int GetId() {
		 return Id;
	 }
	 void SetId(int Id)
	 {
		 this->Id = Id;
	 }
	virtual int GetPraw() = 0;
	virtual void akcja() = 0;
	virtual WynikKolizji kolizja(int ID) = 0;
	virtual void rysowanie() = 0;
	void ZwiekszSile(int i)
	{
		sila = sila + i;
	}
	void losuj(int x,int y, int& new_x,int& new_y);
	bool losujWolne(int x, int y, int& new_x, int& new_y);
};