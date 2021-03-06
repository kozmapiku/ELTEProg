//Név:              Pusztai Kinga, Garamvölgyi Ákos
//Neptun kód:
//MAIL:             kinga@inf.elte.hu, akoskax3@inf.elte.hu
//Feladat:          Típus definiálása, tesztelése
//                      -pont
//                      -kor
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "pont.h"
#include "kor.h"
#include "vector"

using namespace std;

void Beker(std::vector<pont> &v) //Pontokat bekérő függvény
{
    std::ifstream ifstr("input.txt");
    double a, b;
    ifstr >> a >> b;
    while(!ifstr.fail())
    {
        pont p(a,b);
        v.push_back(p);
        ifstr >> a >> b;
    }
}

int main()
{
    std::cout << "Adja meg a kor sugarat!";
    double r;
    std::cin >> r;
    std::cout << std::endl << "Adja meg a kor kozeppontjanak koordinatait:";
    double kpX, kpY;
    std::cin >> kpX >> kpY;
    kor k(kpX,kpY,r);
    k.Kiir();
    (k*5).Kiir();
    (10*k).Kiir();
    std::vector<pont> v;
    Beker(v);
    for(unsigned int i = 0; i < v.size(); i++)
    {
        v[i].kiir();
    }
    std::cout << std::endl;
    for(unsigned int i = 0; i < v.size() -1; i++)
    {
        (v[i]+v[i+1]).kiir();
        (v[i]-v[i+1]).kiir();
    }
    return 0;
}
