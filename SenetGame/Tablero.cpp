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
  int initial_casillas = 10;
  int jugadorID = 0;
  for (int i = 0; i < initial_casillas; i++) {
    (i % 2 == 0) ? jugadorID = 1 :  jugadorID = 2;
    Ficha ficha = Ficha(jugadorID, i);
    tablero[i].ocupada = 1;
    tablero[i].ficha = ficha;
  }
}
