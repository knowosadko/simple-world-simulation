#include "Swiat.h"
#include "GeneratorOrganizmow.h"
#include <fstream>
#include <iostream>
#include "Czlowiek.h"
#include "Owca.h"
#include "Wilk.h"
#include "Antylopa.h"
#include "Zolw.h"
#include "Lis.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Barszcz.h"
#include "Guarana.h"
#include "WilczaJagoda.h"
using namespace std;

int  Swiat::GetOrganizm(int x, int y)
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i]->Getx() == x && organizmy[i]->Gety() == y)
		{
			return i;
		}
	}
	return -1;
}


 Swiat::Swiat(int X, int Y)
 {
	 this->x = X;
	 this->y = Y;
	 tura = 0;
	 
 }
 void Swiat::RemoveOrganizm(int ID)
 {
	 delete organizmy[ID];
	 organizmy.erase(organizmy.begin()+ID);
 }
 int Swiat::GetSilaOrganizmu(int ID)
 {
	 return organizmy[ID]->GetSila();
 }
 int Swiat::GetInicjawtywaOrganizmu(int ID)
 {
	 return organizmy[ID]->GetInicjatywa();
 }
 std::string Swiat::GetGatunek(int ID)
 {
	 return organizmy[ID]->GetGatunek();
 }

 void Swiat::DodajOrganizm(Organizm* organizm)
 {
	 organizmy.push_back(organizm);
 }

 WynikKolizji Swiat::ExecKolizja(int index_ob,int index_at)
 {
	 return organizmy[index_ob]->kolizja(index_at);
 }
 
 


 void Swiat::wykonajTure()
 {
	 tura++;
	 for (int i = 0; i < organizmy.size(); i++)
	 {
 		 organizmy[i]->akcja();
	 }
	 rysujSwiat();
 }

 void Swiat::rysujSwiat()
 {
	 
	 for (int i = 0; i <= x + 1; i++)
	 {
		 for (int j = 0; j <= y + 1; j++)
		 {
			 int indeksOrganizmu = GetOrganizm(j,i);
			 if ( indeksOrganizmu != -1 )
			 {
				 organizmy[indeksOrganizmu]->rysowanie();
			 }
			 else if (i == 0 || i == x +1)
			 {
				 cout << '#';
			 }
			 else if (j == 0 || j == y + 1)
			 {
				 cout << '#';
			 }
			 else
			 {
				 cout << ' ';
			 }
		 }
		 cout << ' ';
		 cout << ' ';
		 cout << ' ';
		 cout << ' ';
		 cout << ' ';
		 cout << ' ';
		 cout << ' ';
		 PiszInstrukcje(i);
		 cout << endl;
	 }
	 obserwator.reset();
 }



 void Swiat::PiszInstrukcje(int line)
 {
	 switch (line)
	 {
	 case 0:
		 cout << "Legenda: ";
		 break;
	 case 1:
		 cout << "1. H - Czlowiek  Z - Zolw  A - Antylopa  W - Wilk  O - Owca  L - Lis";
		 break;
	 case 2:
		 cout << "2. T - Trawa  M - Mlecz  G - Guarana  J - Wilcze jagody  B - Barszcz sonsowskiego";
		 break;
	 case 3:
		 cout << "3. Poruszanie sie czlowiekiem przy pomocy strzalek. Moc specjalna s. ";
		 break;
	 case 4:
		cout << "Obserwator:";
		 break;
	 case 5:
		 cout<< "Tura: "<<tura;
		 break;
	 default:
		 obserwator.Odczytaj();
		 break;
	 }
 }

 void Swiat::sortujOrganizmy()
 {
	 for (int i = 0; i < organizmy.size(); i++)
	 {
		 int j = i;
		 Organizm* com = organizmy[i];
		 while (j > 0 && organizmy[j - 1]->GetInicjatywa() < com->GetInicjatywa() )
		 {
			 organizmy[j] = organizmy[j - 1];
			 j--;
		 }
		 organizmy[j] = com;
	 }
 }

 void Swiat::zapisz()
 {
	 std::string name;
	 cout << "Podaj nazwe pod jaka chcesz zapisac symulacje: ";
	 cin >> name;
	 std::fstream myfile(name, std::ios_base::out);
	 myfile << x;
	 myfile << ' ';
	 myfile << y;
	 myfile << ' ';
	 myfile << tura;
	 myfile << endl;
	 char typ;
	 for (int i = 0; i < organizmy.size(); i++)
	 {
		 myfile << organizmy[i]->GetId();
		 myfile << ' ';
		 myfile << organizmy[i]->GetSila();
		 myfile << ' ';
		 myfile << organizmy[i]->GetInicjatywa();
		 myfile << ' ';
		 myfile << organizmy[i]->Getx();
		 myfile << ' ';
		 myfile << organizmy[i]->Gety();
		 myfile << ' ';
		 myfile << organizmy[i]->GetGatunek();
		 myfile << ' ';
		 if (organizmy[i]->GetId() == 11 || organizmy[i]->GetId() == 12 || organizmy[i]->GetId() == 13 || organizmy[i]->GetId() == 14 || organizmy[i]->GetId() == 15)
			 myfile << organizmy[i]->GetPraw();
		 myfile << endl;
	 }
	 myfile.close();
 }

 void Swiat::wczytaj(Swiat& swiat)
 {
	 std::string name;
	 cout << "Podaj nazwe pliku z jakiego chcesz wczytac symulacje: ";
	 cin >> name;
	 std::fstream myfile(name, std::ios_base::in);
	 organizmy.clear();
	 obserwator.reset();
	 myfile >> swiat.x;
	 myfile >> swiat.y;
	 myfile >> tura;
	 int Id, x, y, sila, inicjatywa,praw=2,moc;
 std:string gatunek1,gatunek2;
	 
	 while (myfile >> Id)
	 {
		 myfile >> sila;
		 myfile >> inicjatywa;
		 myfile >> x;
		 myfile >> y;

		 if (Id == 15||Id == 13)
		 {
			 myfile >> gatunek1;
			 myfile >> gatunek2;
			 gatunek1 = gatunek1 + " " + gatunek2;
		 }
		 else
			 myfile >> gatunek1;
		 if (Id == 11 || Id == 12 || Id == 13 || Id == 15 || Id == 14)
			 myfile >> praw;
		 if(Id == 0)
		 {

			 Czlowiek* organizm = new Czlowiek(Id, sila, inicjatywa, gatunek1, swiat, x, y);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 1)
		 {

			 Wilk* organizm = new Wilk(Id, sila, inicjatywa, gatunek1, swiat, x, y);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 2)
		 {

			 Owca* organizm = new Owca(Id, sila, inicjatywa, gatunek1, swiat, x, y);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 3)
		 {

			 Lis* organizm = new Lis(Id, sila, inicjatywa, gatunek1, swiat, x, y);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 4)
		 {
			 Zolw* organizm = new Zolw(Id, sila, inicjatywa, gatunek1, swiat, x, y);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 5)
		 {

			 Antylopa* organizm = new Antylopa(Id, sila, inicjatywa, gatunek1, swiat, x, y);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 11)
		 {

			 Trawa* organizm = new Trawa(Id, sila, inicjatywa, gatunek1, swiat, x, y, praw);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 12)
		 {

			 Mlecz* organizm = new Mlecz(Id, sila, inicjatywa, gatunek1, swiat, x, y, praw);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 13)
		 {
			 WilczaJagoda* organizm = new WilczaJagoda(Id, sila, inicjatywa, gatunek1, swiat, x, y, praw);
			 organizmy.push_back(organizm);
		 }
		 else if (Id == 14) {
			 Guarana* organizm = new Guarana(Id, sila, inicjatywa, gatunek1, swiat, x, y, praw);
			 organizmy.push_back(organizm);
		 }
		 else if(Id==15)
		 {

			 Barszcz* organizm = new Barszcz(Id, sila, inicjatywa, gatunek1, swiat, x, y, praw);
			 organizmy.push_back(organizm);
			 break;
		 }
		 
	 }
	 rysujSwiat();

 }