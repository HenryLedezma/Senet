/*
*   Implementación de clase, 
*   Simula tirar un dado
*/

#include <cstdlib>
#include "Dado.h"

int rollDice() {
  int numero = 0;
  numero = 1 + rand() % (6-1);
  if (5 == numero) {
    numero = 6;
  }
  return numero;
}