#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include "Program.h"
#include "Microwave.h"
#include "Jedzenie.h"
#include "Schabowy.h"
#include "Button.h"
#include "Button_Increase_Time.h"
#include "Button_Decrease_Time.h"
#include "Zupa.h"
#include "Zarzadzanie.h"
using namespace std;

void ChangeProgram(Program& p, int m, int s, float t); // [3]

void spr3(Microwave* MW);
void spr4(Microwave* MW);
void spr5(Microwave* MW);
void spr6(Microwave* MW);
void spr7();
void spr9();
void spr10(Button* tab[], int size); // [10.3] Zadeklarowć metodę globalną g(), której parametrem p będzie tablica typu B.
//na potrzeby 11
void spr11();
void IncToDec(Button_Increase_Time bit);
void DecToInc(Button_Decrease_Time bdt);
//--------------
//na potrzeby 12
void spr12();
Zarzadzanie operator<<(Zarzadzanie zrz, string bufor);
void operator>>(Zarzadzanie zrz, ostream& ostr);
void Read(std::istream& istr, Zarzadzanie& zrz);
void Write(std::ostream& ostr, Zarzadzanie& zrz);
//--------------
void spr13();



void operator+(int value, Program& p1) // [5.2] funkcja globalana umozliwiajaca operacje liczba + obiekt
{
    p1.setSecs(p1.getSecs() + value);
}

int main()
{
    Program* PR = new Program(10, 30, 50);
    Microwave* MW = new Microwave("Mikrofalowka", *PR);
    Button* BU = NULL; //[8.6] niemożliwe jest utworzenie obiektu klasy abstrakcyjnej
    int wybor = 0;

    //Sprawdzenie cwiczenia 3
    spr3(MW);
    //Sprawdzenie cwiczenia 4
    spr4(MW);
    //Sprawdzenie cwiczenia 5
    spr5(MW);
    //Sprawdzenie cwiczenia 6
    spr6(MW);
    //Sprawdzenie cwiczenia 7
    spr7();
    //Sprawdzenie cwiczenia 9
    spr9();
    //Sprawdzenie cwiczenia 10
    Button_Decrease_Time* bdt1 = new Button_Decrease_Time();
    Button_Decrease_Time* bdt2 = new Button_Decrease_Time();
    Button_Decrease_Time* bdt3 = new Button_Decrease_Time();

    Button* tab[] = { bdt1,bdt2,bdt3 };
    int _size = sizeof(*tab);
    cout << "int _size = sizeof(*tab); === " << _size << endl;
    spr10(tab, 3);
    //Sprawdzenie cwiczenia 11
    spr11();
    //Sprawdzenie cwiczenia 12
    spr12();
    //Sprawdzenie cwiczenia 13
    spr13();
    //Sprawdzenie cwiczenia 8
    cout << "====================================" << endl;
    system("pause");
    system("cls");
    while (true)
    {
        cout << "=================================================" << endl;
        cout << "CZAS - " << MW->program.getMins() << ":" << MW->program.getSecs() << endl;
        cout << "=================================================" << endl;
        cout << "Kliknij przycisk: " << endl;
        cout << "1. Zmniejsz czas (o sekunde)" << endl;
        cout << "2. Zwieksza czas (o sekunde)" << endl;
        cout << "666. Wyjdz z programu" << endl;
        cout << "=================================================" << endl;
        cout << "Wybor: "; cin >> wybor;
        switch (wybor)
        {
        case 1:
            BU = new Button_Decrease_Time();
            break;
        case 2:  
            BU = new Button_Increase_Time();
            break;
        case 666:
            exit(0);
            break;
        default:
            cout << "Brak opcji" << endl;
        }

        if(BU != NULL) BU->Touch(MW);
        system("pause");
        system("cls");
    }
}

void ChangeProgram(Program& p, int m, int s, float t)
{
    p.mins = m;
    p.secs = s;
    p.temp = t;
}

void spr3(Microwave* MW)
{
    cout << "====================================" << endl;
    cout << "Sprawdzenie cwiczenia 3" << endl;
    cout << "====================================" << endl;
    MW->getInfo(MW->program);
    ChangeProgram(MW->program, 30, 30, 30);
    MW->getInfo(MW->program);

    //tworzenie obiektu z const value
    cout << "====================================" << endl;
    cout << "Obiekt z const zmienna" << endl;
    cout << "====================================" << endl;
    Microwave::PowerSupply* ps = new Microwave::PowerSupply(500);
    ps->getInfo();
}

void spr4(Microwave * MW)
{
    cout << "====================================" << endl;
    cout << "Sprawdzenie cwiczenia 4" << endl;
    cout << "====================================" << endl;
    Jedzenie* food = new Jedzenie();
    food->ZmienProgram(MW->program);
    MW->getInfo(MW->program);
    MW->useInnerClass();
}

void spr5(Microwave* MW)
{
    cout << "====================================" << endl;
    cout << "Sprawdzenie cwiczenia 5" << endl;
    cout << "====================================" << endl;
    MW->program + 10;
    MW->getInfo(MW->program);
    10 + MW->program;
    MW->getInfo(MW->program);
}

void spr6(Microwave* MW)
{
    cout << "====================================" << endl;
    cout << "Sprawdzenie cwiczenia 6" << endl;
    cout << "====================================" << endl;
    Program pr = Program(20, 15, 10.5f);
    MW->getInfo(MW->program);
    MW->program = "Program Testowy";
    MW->getInfo(MW->program);
    MW->program = pr;
    MW->getInfo(MW->program);
}

void spr7()
{
    cout << "====================================" << endl;
    cout << "Sprawdzenie cwiczenia 7" << endl;
    cout << "====================================" << endl;
    Schabowy* sch1 = new Schabowy();
    sch1->WyswietlJedzenie();
    Schabowy* sch2 = new Schabowy("Krolewski Schabowy");
    sch2->WyswietlJedzenie();
}

void spr9()
{
    cout << "====================================" << endl;
    cout << "Sprawdzenie cwiczenia 8" << endl;
    cout << "====================================" << endl;
    Zupa * zupa = new Zupa("rzadka");
    //zupa->Wyswietl(); [9.3] Nie można wywolac metody wprost z obiektu poniewaz jest niejednoznaczna
    zupa->Wyswietl(); //[9.4] Rozwiazanie konfliktu ([9.5] tak rozwiązało)

}

void spr10(Button* tab[], int size) // [10.3] Zadeklarowć metodę globalną g(), której parametrem p będzie tablica typu B.
{
    cout << "====================================" << endl;
    cout << "Sprawdzenie cwiczenia 10" << endl;
    cout << "====================================" << endl;
    for (int i = 0; i < size; i++)
    {
        tab[i]->TripleClick(); //[10.6] Wywolywana metoda jest funkcji "Button", ponieważ tablica jest klasy "Button"
    }
}

void IncToDec(Button_Increase_Time bit)
{

}
void DecToInc(Button_Decrease_Time bdt)
{

}
void spr11()
{
    Button_Decrease_Time* bdt1 = new Button_Decrease_Time();
    Button_Increase_Time* bit1 = new Button_Increase_Time();
    DecToInc(*bit1); // [11.3] Wywolanie
    IncToDec(*bdt1); // [11.5] Wywolanie
}

Zarzadzanie operator<<(Zarzadzanie zrz, string bufor)
{
    int pobor;
    string tryb;
    istringstream(bufor) >> pobor >> tryb;

    zrz.setPoborPradu(pobor);
    zrz.setTryb(tryb);
    return zrz;
}
void operator>>(Zarzadzanie zrz, ostream& ostr) 
{
    ostr << zrz.getPoborPradu() << zrz.getTryb() << endl;
}
void Read(istream& istr, Zarzadzanie& zrz)
{
    string bufor;
    getline(istr, bufor);
    zrz << bufor;
}
void Write(ostream& ostr, Zarzadzanie& zrz)
{
    zrz >> ostr;
}
void spr12()
{
    Zarzadzanie* zrz = new Zarzadzanie();
    fstream istr;
    fstream istr2;
    istr.open("plik.txt");
    istr2.open("plik2.txt");

    while (!istr.eof())
    {
        Read(istr, *zrz); //[12.5]
        Write(istr2, *zrz); //[12.5]
    }

    istr2.close();
    istr.close();
}

void spr13()
{
    Jedzenie* j1 = new Jedzenie("Pizza");
    Jedzenie* j2 = new Jedzenie("Kurczak");
    Jedzenie* j3 = new Jedzenie("Parowki");

    //[13.1]
    vector<Jedzenie> foodV;
    list<Jedzenie> foodL;

    vector<Jedzenie> foodV2;
    list<Jedzenie> foodL2;

    foodV.push_back(*j1);
    foodV.push_back(*j2);
    foodV.push_back(*j3);

    foodL.push_back(*j1);
    foodL.push_back(*j2);
    foodL.push_back(*j3);

    for (vector<Jedzenie>::iterator it = foodV.begin(); it != foodV.end(); ++it) 
    {
        foodV2.push_back(*it); 
    }

    for (list<Jedzenie>::iterator it = foodL.begin(); it != foodL.end(); ++it)
    {
        foodL2.push_back(*it); 
    }

    foodV.clear();
    foodL2.clear();

    //Mapa jest kolekcja, ktora posiada klucze i wartosci
    //Lista jest kolekcja, ktora posiada wartosci
}

