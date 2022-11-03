/*
*   Clase que simula ser un tablero del juego
*/

#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Ficha.h"

using namespace std;

/**
 @brief Tablero del juego
*/
class Tablero {
public:
  /**
    @brief Vector size_30 con casilla en default
  */
  Tablero();

// For testing private:
  /**
    @brief Representa una casilla
    @param ocupada Identifica si se encuentra ocupada
    @param bloqueada Identifica si se encuentra bloqueada
    @param ficha Representa una ficha
  */
  struct Casilla {
    bool ocupada = 0;
    int bloqueada = 0;
    Ficha ficha;
  };
  /**
   Representación concreta del tablero
  */
  vector < Casilla > tablero;
};

#endif // TABLERO_H