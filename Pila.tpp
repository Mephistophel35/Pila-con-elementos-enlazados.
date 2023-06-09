//ADDB

#include <iostream>

//**** M�todos que nos garantiza el buen funcionamiento de la clase ****//

template <typename T>
Pila<T>::Pila()
{
    capacidad = 8;
    tope = -1;
    Elementos = new T[capacidad];
}

template <typename T>
Pila<T>::Pila(const Pila<T> &p) : capacidad(p.capacidad), tope(p.tope), Elementos(nullptr)
{
    *this = p;
}

template <typename T>
Pila<T> & Pila<T>::operator=(const Pila<T> &p)
{
    // Si se quiere hacer esto (p == p) retornar lo mismo.
    if(this == &p){
        return *this;
    }

    //Eliminar el arreglo
    delete[] Elementos;

    //Inicializar nuevos valores.
    capacidad = p.capacidad;
    tope = p.tope;

    //Creamos otro arreglo
    Elementos = new T[capacidad];

    //Agregamos todos los elementos de la pila recibida como par�metro y se lo agregamos al nuevo arreglo.
    for(int i = 0; i <= tope; ++i){
        Elementos[i] = p.Elementos[i];
    }

    //Retornamos el nuevo arreglo.
    return *this;
}

template <typename T>
Pila<T>::~Pila()
{
    delete[] Elementos;
}

//********************// M�todos P�blicos //********************//

template <typename T>
void Pila<T>::Agregar(T d)
{
    //Si la pila no est� llena que solo agregue
    //*** IMPORTANTE ***//
    //Se debe primero incrementar el valor del tope para poder agregarlo en ese lugar (recuerda que es un arreglo).
    if(!pilaLlena()){
        // Incrementamos el tope.
        ++tope;
        // Ahora agregamos el valor recibido como par�metro (d) en la posici�n tope del arreglo (o sea, hasta arriba en la pila).
        Elementos[tope] = d;
    }else{
        //Si la pila est� llena mandamos a Redimensionar el arreglo para despu�s mandar a llamar por recursi�n el agregar pas�ndole el mismo dato.
        Redimensionar();
        Agregar(d);
    }

}

template <typename T>
void Pila<T>::Eliminar()
{
    //Si la pila est� vac�a tiramos una excepci�n (esto se puede hacer menos hardcore, solamente regresando un mensaje en pantalla y retornando
    //claro, sin decrementar el tope).
    if(pilaVacia()) throw PilaVacia();
    --tope;
}

template <typename T>
const T & Pila<T>::Tope() const
{
    //Si la pila est� vac�a tiramos una excepci�n(NO NECESARIAMENTE PUEDE SER EXCEPCI�N).
    if(pilaVacia()) throw PilaVacia();
    //Retornamos el valor que est� en el tope de la pila.
    return Elementos[tope];
}

template <typename T>
bool Pila<T>::pilaVacia() const
{
    //Evaluamos si el tope es igual a -1, si el tope es igual a -1, entonces la pila est� vac�a.
    return tope == -1;
}

template <typename T>
void Pila<T>::Vaciar()
{
    //Para vaciar la pila es simplemente igualando el tope a -1.
    tope = -1;
}

template <typename T>
int Pila<T>::Tamanio() const
{
    //Regresamos la cantidad de datos que el arreglo tiene en ese momento al ser llamada esta funci�n
    //Se manda tope + 1, ya que el tope est� inicializado en -1.
    return tope + 1;
}

template <typename T>
int Pila<T>::Capacidad() const
{
    //Retornamos la capacidad que la pila (el arreglo) tiene.
    return capacidad;
}

template <typename T>
void Pila<T>::Imprimir() const
{
    //Si la pila est� vacia tiramos excepci�n (NO NECESARIAMENTE NECESITA SER EXCEPTION.)
    if(pilaVacia()) throw PilaVacia();

    //Imprimo el valor que est� en el tope
    std:: cout << "[" << Elementos[tope] << "]  <--- Tope" << std::endl;

    //Imprimo los dem�s valores EXCEPTO el primero ya que ya lo imprim� antes (por eso tope - 1).
    for(int i = tope-1; i >= 0; --i){
        std:: cout << "[" << Elementos[i] << "]" << std::endl;
    }
}

//********************// M�todos Privados //********************//

template <typename T>
void Pila<T>::Redimensionar()
{
    //Creamos un arreglo temporal
    T * temp = Elementos;
    //Duplicamos la capacidad del arreglo.
    capacidad *= 2;
    //Creamos un nuevo arreglo de tama�o "capacidad" (Recordar que ya duplicamos la capacidad,
    //entonces, si la capacidad era de 8 datos, ahora ser� de 16).
    Elementos = new T[capacidad];

    //Agregamos los datos del arreglo temporal en el nuevo arreglo con capacidad duplicada.
    for(int i = 0; i <= tope; ++i){
        Elementos[i] = temp[i];
    }

    //Eliminamos el arreglo temporal (para no dejar basura).
    delete[] temp;
}

template <typename T>
bool Pila<T>::pilaLlena() const
{
    // Evaluamos si el tama�o actual de arreglo es igual a la capacidad.
    return tope + 1 == capacidad;
}

//*****************// Clase Exception //*****************//

template <typename T>
const char * Pila<T>::PilaVacia::what() const throw()
{
    //Aqu� solamente se retorna el mensaje de excepci�n.
    return "La pila est\240 vacia";
}
