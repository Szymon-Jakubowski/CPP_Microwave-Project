#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stan_Ciekly //[9.2] Utworzenie klasy bazowej dla dziedziczenia wielokrotnego
{
protected:
	string nazwa;
public:
	string getName(); void setName(string n);
	Stan_Ciekly();

	void Wyswietl();
};

