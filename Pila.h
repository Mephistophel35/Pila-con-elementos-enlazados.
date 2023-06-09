// ADDB

#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

template <typename T>
class Pila{

public:

    /** \class Clase Pila vacia
     *
     * \exception Lanza excepci�n cuando la pila est� llena (cuando se intente agregar un elemento).
     *
     */
    class PilaVacia : public std::exception{

    public:
        virtual const char * what() const throw();
    };

    /** \brief Constructor por default
     *
     */
    Pila();

    /** \brief Constructor de copias
     *
     * \param Pila tipo T constante por referencia
     *
     */
    Pila(const Pila<T> &p);

    /** \brief Sobrecarga del operador igual
     *
     * \param Pila tipo T constante por referencia
     * \return  Pila tipo T por referencia
     *
     */
    Pila<T> & operator=(const Pila<T> &p);

    /** \brief Destructor
     *
     */
    ~Pila();

    /** \brief Metodo agregar a la pila (agrega hasta arriba de la pila, es decir, en el tope)
     *
     * \param dato tipo T
     *
     */
    void Agregar(T d);

    /** \brief Metodo eliminar de la pila (Elimina el elemento del tope).
     *
     */
    void Eliminar();

    /** \brief Metodo obtener elemento en el tope de la pila (m�todo constante) ya que no modifica nada.
     *
     * \return Dato tipo T constante por referencia.
     *
     */
    const T & Tope() const;

    /** \brief M�todo que determina si la pila est� vacia (m�todo constante).
     *
     * \return True/False si la pila est� vac�a (evalua si el tope es igual a -1)
     *
     */
    bool pilaVacia() const;

    /** \brief M�todo que vac�a la pila (Elimina los datos que tenga)
     *
     */
    void Vaciar();

    /** \brief M�todo que nos dice el tama�o de la pila, es decir, cuantos elementos tiene la pila (m�todo constante).
     *
     * \return Cantidad de datos (entero).
     *
     */
    int Tamanio() const;

    /** \brief M�todo que nos dice la capacidad de datos que el arreglo tiene (m�todo constante).
     *
     * \return Capacidad del arreglo (entero).
     *
     */
    int Capacidad() const;

    /** \brief M�todo que imprime la pila (m�todo constante).
     *
     */
    void Imprimir() const;

private:

    int capacidad;                  /**< Entero que nos dice la capacidad del arreglo de datos (la pila) */
    int tope;                       /**< Entero usado como �ndice que determina el tope de la pila */
    T * Elementos;                  /**< Puntero al arreglo din�mico que contendr� los elementos en la pila */

    /** \brief M�todo para que ampl�a un x2 la capacidad del arreglo (la pila)
     *
     */
    void Redimensionar();

    /** \brief M�todo que determina si la pila est� llena (m�todo constante).
     *
     * \return True/False si la pila est� llena.
     *
     */
    bool pilaLlena() const;
};

#include "Pila.tpp"

#endif // PILA_H_INCLUDED
