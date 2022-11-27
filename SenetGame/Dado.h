/*
*   Simula ser un mecanismo de azar
*/

#ifndef DADO_H
#define DADO_H

#include <cstdlib>
#include <vector>
using namespace std;

/** 
 @brief Clase emplantillada que simula un menacismo de azar, basado en lados y pesos setteados por el usuario
*/
template < typename T >
class Dado
{
private:
  // Cantidad de lados en el dado (comenzando desde 1)
  int lados_count;
  // Pesos de cada lado del dado
  vector < T > pesos;

  /**
    @brief retorna la cantidad de lados del mecan. de azar
  */
  int getLados() {return lados_count;};

public:
  /**
    @brief constructor de clase
    @param lados cantidad de lados que tendrá el mecanismo de azar
    @param pesos lo que se debería retornar según el num. lado del mecanismo de azar
  */
  Dado(int lados, vector < T > pesos);

  /**
    @brief destructor de clase
  */
  ~Dado() {};

  /**
    @brief Simula tirar un dado
    @return un entero entre 1 y 6, menos el 5
  */
  T rollDice();
};

template < typename T >
Dado<T>::Dado(int lados, vector < T > pesos) {
  this->lados_count = lados;
  this->pesos = pesos;
}

template < typename T >
T Dado<T>::rollDice() {
  int indice = 0;
  indice = 1 + rand() % (this->getLados());
  T value;
  value = this->pesos[indice - 1];
  return value;
}

#endif  // DADO_H