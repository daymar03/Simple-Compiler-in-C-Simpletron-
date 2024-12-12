#ifndef COLA_H
#define COLA_H
#include"Nodo.h"
#include<iostream>
using std::cout;

template <typename T>
class Cola
{
private:
 Nodo<T> *primerPtr;
 Nodo<T> *ultimoPtr;
 Nodo<T> *ObtenerNuevoNodo(const T &);
 void Eliminar();
public:
 Cola();
 ~Cola();
 void Insertar(const T &);
 bool Sacar(int &);
 bool EstaVacia();
 void Mostrar();
 T VerPosicion(const int &);
};
//******************************************
template<typename T>//CONSTRUCTOR DE COLA
Cola<T>::Cola(): primerPtr(0), ultimoPtr(0)
{
 //Cuerpo Vacio
}

template<typename T>//DESTRUCTOR DE COLA
Cola<T>::~Cola()
{
 if(!EstaVacia())
 {
  Nodo<T> *actualPtr = primerPtr;
  Nodo<T> *temporalPtr;
  while(actualPtr != 0)
  {
   temporalPtr=actualPtr;
   actualPtr=actualPtr->siguientePtr;
   delete temporalPtr;
  }
 }
}

template<typename T>//METODO INSERTAR
void Cola<T>::Insertar(const T &data)
{
 Nodo<T> *nuevoPtr = ObtenerNuevoNodo(data);
 if(EstaVacia())
  primerPtr = ultimoPtr = nuevoPtr;
 else
 {
  ultimoPtr->siguientePtr = nuevoPtr;
  ultimoPtr = nuevoPtr;
 }
}
//**********************************************
template<typename T>//METODO SACAR
bool Cola<T>::Sacar(int &sacar)
{
 if(!EstaVacia())
 {
  T date = primerPtr->ObtenerDato();
  Eliminar();
  sacar = date;
  return true;
 }
 else 
 { 
  return false;
 } 
}
//**********************************************
template<typename T>//METODO ELIMINAR
void Cola<T>::Eliminar()
{
 if(primerPtr != 0)
 {        
  Nodo<T> *temporalPtr = primerPtr;
  primerPtr = primerPtr->siguientePtr;
  delete temporalPtr;
 } 
}
//**********************************************
template<typename T>//CONSTRUCTOR DE COLA
bool Cola<T>::EstaVacia()
{
if(primerPtr==0)
 return true;
else
 return false;
}
//**********************************************
template<typename T>//METOD OBTENER NUEVO NODO
Nodo<T>* Cola<T>::ObtenerNuevoNodo(const T &data)
{
 return new Nodo<T>(data);
}
//******************************************************
template<typename T>//METODO MOSTRAR
void Cola<T>::Mostrar()
{
 if(!EstaVacia())
 {
  Nodo<T> *actualPtr = primerPtr;
  while(actualPtr != 0)
  {
   cout<<actualPtr->dato<<"\n";
   actualPtr=actualPtr->siguientePtr;
  }
 }
}
//****************************************************
template<typename T>//METODO VER POSICION
T Cola<T>::VerPosicion(const int &pos)
{
 int cont=1;
 Nodo<T> *actualPtr = primerPtr;
 if(pos==1)
  return actualPtr->dato;
 else
 {
  while(cont < pos)
  {
  actualPtr=actualPtr->siguientePtr;
  cont++;
  }
 }
 return actualPtr->dato;
} 
#endif
