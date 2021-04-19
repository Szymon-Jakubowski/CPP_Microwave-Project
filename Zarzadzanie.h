#pragma once
#include <iostream>
#include <string>

using namespace std;

class Zarzadzanie
{
	float poborPradu;
	string trybDzialania;
public:
	Zarzadzanie()
	{
		poborPradu = 1040;
		trybDzialania = "Normalny";
	}

	void setPoborPradu(float value) { poborPradu = value; }
	float getPoborPradu() { return poborPradu; }
	void setTryb(string value) { trybDzialania = value; }
	string getTryb() { return trybDzialania; }

	void Print()
	{
		cout << "Pobor pradu: " << poborPradu << "V" << endl;
		cout << "Tryb: " << trybDzialania << endl;
	}
};

