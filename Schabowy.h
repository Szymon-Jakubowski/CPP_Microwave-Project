#pragma once
#include "Jedzenie.h"

using namespace std;

class Schabowy : private Jedzenie //[7.1]
{
	string nazwa;

public:
	void setNazwa(string n); string getNazwa();

	Schabowy();
	Schabowy(string n);

	void WyswietlJedzenie();
};

