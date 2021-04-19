#include "Microwave.h"

using namespace std;

Microwave::PowerSupply::PowerSupply(int pow, string name) : power(pow)
{
	setName(name);
}

Microwave::PowerSupply::PowerSupply(int pow) : power(pow){}

int Microwave::PowerSupply::getPower() {
    return power;
}

string Microwave::PowerSupply::getName() {
	return name;
}
void Microwave::PowerSupply::setName(string name) {
	this->name = name;
}

void Microwave::PowerSupply::getInfo()
{
	cout << "Nazwa zasilacza: " << name << endl;
	cout << "Moc zasilacza: " << power << endl;
}