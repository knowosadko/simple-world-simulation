#include "EventListener.h"
void EventListener::smierc(std::string gatunek, std::string agresor)
{
	std::string text;
	if (gatunek != "Antylopa" && gatunek != "Owca")
		text = gatunek + " zostal zabity przez " + agresor + ". ";
	else
		text = gatunek + " zostala zabita przez " + agresor + ". ";
	events.push_back(text);
}

void EventListener::narodziny(std::string gatunek)
{
	std::string text;
	if (gatunek != "Antylopa" && gatunek != "Owca")
		text = "Kolejny " + gatunek + " sie urodzil. ";
	else
		text = "Kolejna " + gatunek + " sie urodzla. ";
	events.push_back(text);
}

void EventListener::obrona(std::string gatunek,std::string agresor)
{
	std::string text;
	text = gatunek + " obronil sie przed atakiem ze strony " + agresor +". ";
	events.push_back(text);
}

void EventListener::ucieczka(std::string gatunek)
{
	std::string text;
	if (gatunek == "Czlowiek")
		text = gatunek + " uciekl przed agresorem. ";
	else
		text = gatunek + " uciekla przed agresorem. ";
	events.push_back(text);
}
void EventListener::wyroslo(std::string gatunek)
{
	std::string text;
	if (gatunek == "Mlecz" || gatunek == "Barszcz")
	{
		text = " Wyrosl  kolejny " + gatunek + ". ";
	}
	else
	{
		text = " Wyrosla kolejna " + gatunek + ". ";
	}
	events.push_back(text);
}

void EventListener::zatrul(std::string gatunek, std::string trucizna)
{
	std::string text;
	if (trucizna == "Barszcz")
	{
		text = trucizna + " zatrul " + gatunek + ".";
	}
	else
	{
		text = trucizna + " zatrula " + gatunek + ".";
	}
	events.push_back(text);
}

void EventListener::umiejetnoscStart()
{
	std::string text = "Czlowiek uruchomil swoja moc. ";
	events.push_back(text);
}

void EventListener::umiejetnoscEnd()
{
	std::string text = "Moc czlowieka sie skonczyla. ";
	events.push_back(text);
}

void EventListener::umiejetnoscLast()
{
	std::string text = "Moc Czlowieka jest aktywna. ";
	events.push_back(text);
}

void EventListener::poparzony(std::string gatunek)
{
	std::string text = "Barszcz Sosnowskiego poparzyl " + gatunek + ". ";
	events.push_back(text);
}
