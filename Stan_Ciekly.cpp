#include "Stan_Ciekly.h"

string Stan_Ciekly::getName() {
	return nazwa;
}
void Stan_Ciekly::setName(string n) {
	this->nazwa = n;
}

Stan_Ciekly::Stan_Ciekly()
{
	nazwa = "Stan Ciekly";
}

void Stan_Ciekly::Wyswietl()
{
	cout << "Jest w stanie ciek³ym" << endl;
}