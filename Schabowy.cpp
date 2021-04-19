#include "Schabowy.h"

void Schabowy::setNazwa(string n)
{
	nazwa = n;
}

string Schabowy::getNazwa()
{
	return nazwa;
}

Schabowy::Schabowy()
{
	this->nazwa = "Podstawowy Schabowy";
	//[7.3] Wartoœci skladowych klasy bazowej mozna przypisac poprzez settery
	this->setMins(2);
	//[7.3] Konstruktory zostan¹ wywo³ane zawsze w kolejnoœci Bazowa->Pochodna
	//[7.3] Zawsze konieczne jest wywolanie konstruktora klasy bazowej w klasie pochodnej
}

Schabowy::Schabowy(string n)
{
	this->nazwa = n;
	//[7.5] Schabowy::WyswietlJedzenie(); Tak, jest mo¿liwe w pochodnej funkcji wywolac przeslonieta metode
}

//[7.4] Przysloniecie istniejacej metody z klasy bazowej
void Schabowy::WyswietlJedzenie()
{
	cout << "Wywolano od Schabowego" << endl;
	cout << "Nazwa: " << getNazwa() << endl;
	Jedzenie::Wyswietl();
	//[7.4]Modyfikator zasiegu moze byc jako private, protected lub public
}