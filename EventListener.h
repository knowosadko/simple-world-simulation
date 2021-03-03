#pragma once
#include <vector>
#include <string>
#include <iostream>
class EventListener
{
private:
	std::vector<std::string> events;
	int odczytane;
public:
	EventListener()
	{
		odczytane = 0;
	}
	void Odczytaj()
	{

		for (int i = odczytane; i < odczytane + 3 && i < events.size() ; i++)//odzytuje 3 komunikaty w lini
		{
			std::cout << events[i];
		}
		odczytane += 3;
	}
	////////////////////////
	int GetSize()
	{
		return events.size();
	}
	///////////////////////////
	void reset()
	{
		events.clear();
		odczytane = 0;
	}
	void smierc(std::string gatunek, std::string agresor);

	void narodziny(std::string gatunek);

	void obrona(std::string gatunek, std::string agresor);

	void ucieczka(std::string gatunek);
	void wyroslo(std::string gatunek);

	void zatrul(std::string gatunek, std::string trucizna);

	void umiejetnoscStart();

	void umiejetnoscEnd();

	void umiejetnoscLast();
	
	void poparzony(std::string gatunek);
	
};