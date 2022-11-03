/*
*   Implementación de clase,
*   Simula ser una ficha del tablero
*/

#include "Ficha.h"

Ficha::Ficha(int player, int pos) {
  this->jugador = player;
  this->posc = pos;
}

Ficha::Ficha() {}

int Ficha::getJugadorID() {
  return this->jugador;
}

int Ficha::getPosicion() {
  return this->posc;
}

int Ficha::isProtected() {
  return this->protegido;
}
