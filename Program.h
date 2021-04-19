#pragma once
#include <iostream>
#include <string>

using namespace std;

class Program {
    friend class Jedzenie; // [4.1]
    friend void ChangeProgram(Program& p, int m, int s, float t); // [3]
private:
    const char* nazwa = "x";
    char* nazwaProgramu = (char*)"x";
    int mins = 0;
    int secs = 0;
    float temp = 0;
public:
    //GET&SET
    int getMins(); void setMins(int mins);
    int getSecs(); void setSecs(int secs);
    float getTemp(); void setTemp(float temp);
    char getProgramName(); 
    //Konstruktory
    Program();
    Program(int m, int s, float t);
    //METODY
    void operator+(int value); //[5.1]
    void operator=(Program k); //[6.2]
    void operator=(const char* k); //[6.3]
};
