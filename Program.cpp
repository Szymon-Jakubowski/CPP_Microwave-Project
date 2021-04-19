#include "Program.h"


int Program::getMins() {
    return mins;
}
void Program::setMins(int mins) {
    this->mins = mins;
}
int Program::getSecs() {
    return secs;
}
void Program::setSecs(int secs) {
    this->secs = secs;
}
float Program::getTemp() {
    return temp;
}
void Program::setTemp(float temp) {
    this->temp = temp;
}
char Program::getProgramName()
{
    return *nazwaProgramu;
}

Program::Program()
{
    setMins(0);
    setSecs(60);
    setTemp(80);
}

Program::Program(int m, int s, float t)
{
    setMins(m);
    setSecs(s);
    setTemp(t);
}

void Program::operator+(int value) //[5.1]
{
    this->secs += value;
}

void Program::operator=(Program k)
{
    setMins(k.getMins());
    setSecs(k.getSecs());
    setTemp(k.getTemp());

    if (k.nazwa != NULL)
        this->nazwa = k.nazwa;
    else
        this->nazwa = "Test";
}

void Program::operator=(const char* k)
{
    this->nazwaProgramu = nullptr;
    this->nazwaProgramu = new char[strlen(k) + 1];
    #pragma warning(suppress : 4996)
    strcpy(this->nazwaProgramu, k);
}
