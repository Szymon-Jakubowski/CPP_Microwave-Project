#include "Zupa.h"

string Zupa::getGestosc()
{
	return gestosc;
}

void Zupa::setGestosc(string gestosc)
{
	this->gestosc = gestosc;
}

Zupa::Zupa(string gestosc) : Jedzenie("Zupa"), Stan_Ciekly()
{
	setGestosc(gestosc);
}

void Zupa::Wyswietl()
{
	Jedzenie::Wyswietl();
}