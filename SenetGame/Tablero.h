#pragma once
#include "Casilla.h"
/*
*   Clase que simula ser un tablero del juego
*/

#ifndef TABLERO_H
#define TABLERO_H

#include <vector>


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

  /**
   Representación concreta del tablero
  */
  vector < Casilla > tablero;
};

#endif // TABLERO_H
