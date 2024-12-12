#include<iostream>
using namespace std;

#include"Simpletron.h"

int main()
{
Simpletron m;
m.PasarInstruccion(1010);
m.PasarInstruccion(1011);
m.PasarInstruccion(2010);
m.PasarInstruccion(3011);
m.PasarInstruccion(2112);
m.PasarInstruccion(1112);

m.Ejecutar();
return 0;
}
