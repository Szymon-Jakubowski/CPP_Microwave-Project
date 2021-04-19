#pragma once
#include "Jedzenie.h"
#include "Stan_Ciekly.h"

class Zupa :public Jedzenie, Stan_Ciekly //[9.2] Utworzenie klasy pochodnej
{
	string gestosc;

public:
	string getGestosc(); void setGestosc(string gestosc);
	Zupa(string gestosc);
	void Wyswietl(); // [9.4] Uzupelnienie
};

