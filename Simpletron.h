#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include"Cola.h"

class Simpletron{
private:
 Cola<int> MEMORIA;
 Cola<int> ACUMULADOR;
 int *arreglo;
//************[AUXILIARES]**********************
 void LEE(const int &);
 void ESCRIBE(const int &);
 void CARGA(const int &);
 void ALMACENA(const int &);
 void SUMA(const int &);
 void RESTA(const int &);
 void DIVIDE(const int &);
 void MULTIPLICA(const int &);
//void BIFURCA();
//void BIFURCANEG();
//void BIFURCACERO();
//void TERMINATE();
//void MOSTRAR();

public:
 Simpletron();
 void PasarInstruccion(const int &);
//EliminarInstruccion();
 int Ejecutar();
 void MOSTRAR();
};
//***********************[CONSTRUCTOR]*******************************
Simpletron::Simpletron():arreglo(new int[100])
{
 for(int i=0;i<100;i++)
  arreglo[i]=-9999;
}

void Simpletron::MOSTRAR()
{ 
 cout<<"MEMORIA:\n\n";
 MEMORIA.Mostrar();
 cout<<"ACUMULADOR:\n\n";
 ACUMULADOR.Mostrar();
}
//*********************[PASAR INSTRUCCION]***************************
void Simpletron::PasarInstruccion(const int &inst)
{
 if(inst >=1000 && inst <= 9999)
 {
  MEMORIA.Insertar(inst);
 }
 else
 cout<<"Instruccion Invalida";
}
//**************************[EJECUTAR]***********************
int Simpletron::Ejecutar()
{
 int linea=0;
 int instruccion=0;
 while(MEMORIA.Sacar(instruccion))
 {
  int posicion=instruccion%100;
  instruccion/=100;
  switch(instruccion)
  {
   case 10:
    LEE(posicion);break;
   case 11:
    ESCRIBE(posicion);break;
   case 20:
    CARGA(posicion);break;
   case 21: 
    ALMACENA(posicion);break;
   case 30:
    SUMA(posicion);break;
   case 31:
    RESTA(posicion);break;
   case 32:
    DIVIDE(posicion);break;
   case 33:
    MULTIPLICA(posicion);break;
   case 99:
    return 0;break;
   default:
    return 1;break;
  }
 }
return 0;
}
//************************[LEE]*********************************
void Simpletron::LEE(const int &pos)
{
int aux;
cin>>aux;
arreglo[pos]=aux;
//ELSE LANZAR EXCEPCION
}
//*************************[ESCRIBE]********************************
void Simpletron::ESCRIBE(const int &pos)
{
cout<<arreglo[pos];
}

//*************************[CARGA]********************************
void Simpletron::CARGA(const int &pos)
{
 if(arreglo[pos]!=-9999)
  ACUMULADOR.Insertar(arreglo[pos]);
}

//*************************[ALMACENA]********************************
void Simpletron::ALMACENA(const int &pos)
{
 int valor=0;
 
 if(ACUMULADOR.Sacar(valor))
 {
   arreglo[pos]=valor;
 }
}

//*************************[SUMA]********************************
void Simpletron::SUMA(const int &pos)
{
 if(arreglo[pos]!=-9999 && !ACUMULADOR.EstaVacia()){
  int temp=0;
  ACUMULADOR.Sacar(temp);
  temp+=arreglo[pos];
  ACUMULADOR.Insertar(temp);}
}

//*************************[RESTA]********************************
void Simpletron::RESTA(const int &pos)
{
 if(arreglo[pos]!=-9999 && !ACUMULADOR.EstaVacia()){
  int temp=0;
  ACUMULADOR.Sacar(temp);
  temp-=arreglo[pos];
  ACUMULADOR.Insertar(temp);}
}

//*************************[DIVIDE]********************************
void Simpletron::DIVIDE(const int &pos)
{
 if(arreglo[pos]!=-9999 && !ACUMULADOR.EstaVacia()){
  int temp=0;
  ACUMULADOR.Sacar(temp);
  temp/=arreglo[pos];
  ACUMULADOR.Insertar(temp);}
}

//*************************[MULTIPLICA]********************************
void Simpletron::MULTIPLICA(const int &pos)
{
 if(arreglo[pos]!=-9999 && !ACUMULADOR.EstaVacia()){
  int temp=0;
  ACUMULADOR.Sacar(temp);
  temp*=arreglo[pos];
  ACUMULADOR.Insertar(temp);}
}

#endif
