#ifndef NODO_H
#define NODO_H
template<typename T> class Cola;
template<typename T>
class Nodo{
friend class Cola<T>;
private:
 T dato;
 Nodo<T> *siguientePtr;
public:
 Nodo(const T &);
 T ObtenerDato();
};
//***************************************
template<typename T>//CONSTRUCTOR DE NODO
Nodo<T>::Nodo(const T &data) : dato(data), siguientePtr(0)
{
//Cuerpo Vacio
}
//***************************************
template<typename T>//METODO OBTENER DATO
T Nodo<T>::ObtenerDato()
{
 return dato;
}

#endif
