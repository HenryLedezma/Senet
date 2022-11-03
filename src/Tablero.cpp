/*
*   Implementación de clase, 
*   Simula ser el tablero
*/

#include "Tablero.h"

Tablero::Tablero() {
  int casillas_count = 30;
  for (int i = 0; i < casillas_count; i++) {
    tablero.push_back(Casilla());
  }
}