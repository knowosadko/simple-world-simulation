#pragma once
#include "GeneratorOrganizmow.h"
#include "EventListener.h"
#include <iostream>
#include <vector>
typedef std::vector<Organizm*> Organizmy;
class Swiat {
	private:
		int tura;
		Organizmy organizmy;
		int x;
		int y;
	protected:
		EventListener obserwator;
	public:
	Swiat(int X, int Y);
	void wykonajTure();
	void rysujSwiat();
	
	int GetX()
	{
		return x;
	}
	
	int GetY()
	{
		return y;
	}
	
	int KtoraTura()
	{
		return tura;
	}
	
	int GetOrganizm(int x, int y);// nie wiem czy ta opcja ze wskaznikiem zadziala
	void RemoveOrganizm(int ID);
	int GetSilaOrganizmu(int ID);
	int GetInicjawtywaOrganizmu(int ID);
	std::string GetGatunek(int ID);
	void DodajOrganizm(Organizm* organizm);
	WynikKolizji ExecKolizja(int index_ob, int index_at);
	void PiszInstrukcje(int line);
	friend class GeneratorOrganizmow;
	void sortujOrganizmy();
	void zapisz();
	void wczytaj(Swiat& swiat);
	void ZwiekszSilaOrganizmu(int index, int i)
	{
		organizmy[index]->ZwiekszSile(i);
	}
	//obsluga obserwatora
	void OdczytajObserwator()
	{
		obserwator.Odczytaj();
	}
	void SmiercObserwator(std::string gatunek, std::string agresor)
	{
		obserwator.smierc(gatunek,agresor);
		int size=obserwator.GetSize();
	}
	void ObronaObserwator(std::string gatunek,std::string agresor)
	{
		obserwator.obrona(gatunek,agresor);
	}
	void UcieczkaObserwator(std::string gatunek)
	{
		obserwator.ucieczka(gatunek);
	}
	void UmiejetnoscObserwator()
	{
		obserwator.umiejetnoscLast();
	}
	void NarodzinyObserwator(std::string gatunek)
	{
		obserwator.narodziny(gatunek);
	}
	void UrosloObserwator(std::string gatunek)
	{
		obserwator.wyroslo(gatunek);
	}
	void ZatruloObserwator(std::string gatunek,std::string trucizna)
	{
		obserwator.zatrul(gatunek, trucizna);
	}
	void PoparzonyObserwator(std::string gatunek)
	{
		obserwator.poparzony(gatunek);
	}
};